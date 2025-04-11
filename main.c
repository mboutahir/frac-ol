/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutahi <mboutahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:32:23 by mboutahi          #+#    #+#             */
/*   Updated: 2025/04/05 06:11:32 by mboutahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	is_number(char *argv)
{
	int	dot_count;

	dot_count = 0;
	while ((*argv >= '0' && *argv <= '9') || *argv == '.')
	{
		if (*argv == '.')
		{
			dot_count++;
			if (dot_count > 1)
				return (0);
		}
		argv++;
	}
	while (*argv == ' ')
		argv++;
	if (*argv)
		return (0);
	return (1);
}

int	handle_error(char *argv)
{
	int	i;

	i = 0;
	if (!(*argv))
		return (0);
	while (argv[i] == ' ')
		i++;
	if (argv[i] == '\0')
		ft_error();
	if (argv[i] == '+' || argv[i] == '-')
	{
		if ((argv[i + 1] < '0' || argv[i + 1] > '9') && argv[i + 1] != '.')
			ft_error();
		i++;
	}
	if (is_number(argv + i) == 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if ((argc == 2 && ft_strncmp(argv[1], "mandelbrot", 0) == 1) 
		|| (argc == 4 && ft_strncmp(argv[1], "julia", 0) == 1))
	{
		if ((argc == 4 && ft_strncmp(argv[1], "julia", 0) == 1))
		{
			if (!handle_error(argv[2]) || !handle_error(argv[3]))
				ft_error();
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
	return (0);
}
