/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutahi <mboutahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 20:48:01 by mboutahi          #+#    #+#             */
/*   Updated: 2025/04/03 02:33:03 by mboutahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_connection, fractol->img.img_ptr);
	mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
	free(fractol->mlx_connection);
	exit (0);
}

int	key_handler(int keycode, t_fractol *fractol)
{
	if (keycode == 53)
		close_handler(fractol);
	if (keycode == 126)
		fractol->shift_y -= (0.5 * fractol->zoom);
	else if (keycode == 125)
		fractol->shift_y += (0.5 * fractol->zoom);
	else if (keycode == 123)
		fractol->shift_x -= (0.5 * fractol->zoom);
	else if (keycode == 124)
		fractol->shift_x += (0.5 * fractol->zoom);
	else if (keycode == 69)
		fractol->iterations += 10;
	else if (keycode == 78)
		fractol->iterations -= 10;
	mlx_destroy_image(fractol->mlx_connection, fractol->img.img_ptr);
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_connection, WIDTH,
			HIGHT);
	fractol->img.pixels_ptr = mlx_get_data_addr(fractol->img.img_ptr,
			&(fractol->img.bit_per_pixel), &(fractol->img.line_length),
			&(fractol->img.endian));
	fractol_render(fractol);
	return (0);
}

int	mouse_scroll(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (button == 4)
		fractol->zoom *= 1.1;
	else if (button == 5)
		fractol->zoom *= 0.9;
	mlx_destroy_image(fractol->mlx_connection, fractol->img.img_ptr);
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_connection, WIDTH, HIGHT);
	fractol->img.pixels_ptr = mlx_get_data_addr(fractol->img.img_ptr,
			&(fractol->img.bit_per_pixel), &(fractol->img.line_length),
			&(fractol->img.endian));
	fractol_render(fractol);
	return (0);
}
