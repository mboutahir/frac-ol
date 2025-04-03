/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutahi <mboutahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:32:23 by mboutahi          #+#    #+#             */
/*   Updated: 2025/04/03 02:28:05 by mboutahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if ((argc == 2 && ft_strncmp(argv[1], "mandelbrot", 0) == 1) 
		|| (argc == 4 && ft_strncmp(argv[1], "julia", 0) == 1)
		|| (argc == 2 && ft_strncmp(argv[1], "burning_ship", 0) == 1))
	{
		if ((argc == 4 && ft_strncmp(argv[1], "julia", 0) == 1))
		{
			fractol.name = argv[1];
			fractol.julia_x = atoi_double(argv[2]);
			fractol.julia_y = atoi_double(argv[3]);
		}
		fractol.name = argv[1];
		fractol_init(&fractol);
		fractol_second_init(&fractol);
		fractol_render(&fractol);
		mlx_loop(fractol.mlx_connection);
	}
	else
		ft_error();
}
