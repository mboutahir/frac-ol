/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutahi <mboutahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 20:41:20 by mboutahi          #+#    #+#             */
/*   Updated: 2025/03/30 01:11:47 by mboutahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//initialize /mlx /listenting events/ hooks data
static void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(1);
}

void	data_init(t_fractol *fractol)
{
	fractol->escape_value = 4;
	fractol->iterations = 51;
	fractol->shift_x = 0.0;
	fractol->shift_y = 0.0;
	fractol->zoom = 1.0;
}

static void	event_init(t_fractol *fractol)
{
	mlx_key_hook(fractol->mlx_window, key_handler, fractol);
	 mlx_hook(fractol->mlx_window, 4, 0, mouse_scroll, fractol);
	mlx_hook(fractol->mlx_window, 17, 0, close_handler, fractol); 
}

void	fractol_init(t_fractol *fractol)
{
	fractol->mlx_connection = mlx_init();
	if (!(fractol->mlx_connection))
		malloc_error();
	fractol->mlx_window = mlx_new_window(fractol->mlx_connection,
			width,
			hight, fractol->name);
	if (!(fractol->mlx_window))
	{
		// mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
		free(fractol->mlx_connection);
		malloc_error();
	}
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_connection,
			width,
			hight);
	if (!(fractol->img.img_ptr))
	{
		mlx_destroy_image(fractol->mlx_connection, fractol->mlx_window);
		mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
		free(fractol->mlx_connection);
		malloc_error();
	}
}

void	fractol_second_init(t_fractol *fractol)
{
	fractol->img.pixels_ptr = mlx_get_data_addr(fractol->img.img_ptr,
			&fractol->img.bit_per_pixel,
			&fractol->img.line_length, &fractol->img.endian);
	data_init(fractol);
	event_init(fractol);
}
