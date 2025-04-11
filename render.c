/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutahi <mboutahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 22:36:48 by mboutahi          #+#    #+#             */
/*   Updated: 2025/04/05 06:48:34 by mboutahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	pixel_input(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_length) + (x * (img->bit_per_pixel / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	mandel_julia(t_complex *z, t_complex *c, t_fractol *fractol)
{
	if (ft_strncmp(fractol->name, "julia", 0) == 1)
	{
		c->real = fractol->julia_x;
		c->imgnry = fractol->julia_y;
	}
	else
	{
		c->real = z->real;
		c->imgnry = z->imgnry;
	}
}

static void	handle_pixel(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;
	double		temp;

	i = 0;
	z.real = (map(x, 2, -2, WIDTH) * fractol->zoom);
	z.imgnry = (map(y, 2, -2, HIGHT) * fractol->zoom);
	mandel_julia(&z, &c, fractol);
	while (i < fractol->iterations)
	{
		temp = (z.real * z.real) - (z.imgnry * z.imgnry) + c.real;
		z.imgnry = (2.0 * z.real * z.imgnry) + c.imgnry;
		z.real = temp;
		if ((z.real * z.real) + (z.imgnry * z.imgnry) > fractol->escape_value)
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
	while (++y < HIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractol);
		}
	}
	mlx_put_image_to_window(fractol->mlx_connection, fractol->mlx_window,
		fractol->img.img_ptr, 0, 0);
}
