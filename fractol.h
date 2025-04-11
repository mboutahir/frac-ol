/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutahi <mboutahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:32:15 by mboutahi          #+#    #+#             */
/*   Updated: 2025/04/05 12:56:48 by mboutahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>

# define HIGHT	800
# define WIDTH	800

# define BLACK					0x000000
# define FLUORESCENT_ORANGE		0xFFA500

typedef struct s_complex
{
	double	real;
	double	imgnry;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_fractol
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iterations;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}	t_fractol;

int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_error(void);
void		fractol_init(t_fractol *fractol);
void		fractol_second_init(t_fractol *fractol);
double		map(double unscaled, double new_min, double new_max, double max);
void		fractol_render(t_fractol *fractol);
int			key_handler(int keysym, t_fractol *fractol);
int			close_handler(t_fractol *fractol);
int			mouse_scroll(int button, int x, int y, t_fractol *fractol);
int			key_handler(int keycode, t_fractol *fractol);
double		atoi_double(char *str);
#endif