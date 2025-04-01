/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutahi <mboutahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 20:48:01 by mboutahi          #+#    #+#             */
/*   Updated: 2025/03/30 01:06:51 by mboutahi         ###   ########.fr       */
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

int key_handler(int keycode, t_fractol *fractol)
{
	// Handle ESC key
	printf("Key pressed: %d\n", keycode);
	if (keycode == 53)
		close_handler(fractol);  //Close the window when ESC is pressed
	if (keycode == 126) //up
		fractol->shift_y -= (0.5 * fractol->zoom);
	else if (keycode == 125) //down
		fractol->shift_y += (0.5 * fractol->zoom);
	else if (keycode == 123) //left
		fractol->shift_x -= (0.5 * fractol->zoom);
	else if (keycode == 124) //right
		fractol->shift_x += (0.5 * fractol->zoom);
	else if(keycode == 69) //plus
		fractol->iterations += 5;
	else if(keycode == 78) //minus
		fractol->iterations -= 5;
	fractol_render(fractol);
	return (0);
}

int	mouse_scroll(int button, int x, int y, t_fractol *fractol)
{
	(void)x;
    (void)y;

	if (button == 4)
	{
		fractol->zoom *= 0.95;
	}
	else if (button == 5)
	{
		fractol->zoom *= 1.05;
	}
	printf("Zooming out: %d\n", button);
	fractol_render(fractol);
	return (0);
}
