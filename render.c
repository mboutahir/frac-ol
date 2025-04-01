/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutahi <mboutahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 22:36:48 by mboutahi          #+#    #+#             */
/*   Updated: 2025/04/01 16:58:09 by mboutahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//put pixel in image buffer
static void	pixel_input(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_length) + (x * (img->bit_per_pixel / 8));
	*(unsigned int *)(img->pixels_ptr +offset) = color;
}

static void	mandel_julia(t_complex *z, t_complex *c, t_fractol *fractol)
{
	if (ft_strncmp(fractol->name, "julia", 0) == 1)
	{
		c->real_num = fractol->julia_x;
		c->imgnry_num = fractol->julia_y;
	}
	else
	{
		c->real_num = z->real_num;
		c->imgnry_num = z->imgnry_num;
	}
}

static void	handle_pixel(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;
	
	i = 0;
	
	//pixel coordinates scaled since at firt z^z + c at first is 0 + c we give z the c value directly
	z.real_num = (map(x, 2, -2, width) * fractol->zoom) + fractol->shift_x;
	z.imgnry_num = (map(y, 2, -2, hight) * fractol->zoom)+ fractol->shift_y;
	mandel_julia(&z, &c, fractol);
	while(i < fractol->iterations)
	{
		if (ft_strncmp(fractol->name, "burning_ship", 0) == 1)
		{
			z.real_num = fabs(z.real_num);
			z.imgnry_num = fabs(z.imgnry_num);
		}
		double temp = (z.real_num * z.real_num) - (z.imgnry_num * z.imgnry_num) + c.real_num;
		z.imgnry_num = (2.0 * z.real_num * z.imgnry_num) + c.imgnry_num;
		z.real_num = temp;
		if((z.real_num * z.real_num) + (z.imgnry_num * z.imgnry_num) > fractol->escape_value)
		{
			color = map(i, FLUORESCENT_ORANGE, BLACK, fractol->iterations);
			pixel_input(x, y, &fractol->img, color);
			return ;
		}
		i++;
	}
	pixel_input(x, y, &fractol->img, BLACK);
}
void	fractol_render(t_fractol *fractol)
{
	int	x;
	int	y;

	y = -1;
	while (++y < hight)
	{
		x = -1;
		while (++x < width)
		{
			handle_pixel(x, y, fractol);
		}
	}
	mlx_put_image_to_window(fractol->mlx_connection,
							fractol->mlx_window,
							fractol->img.img_ptr,
							0, 0);
}