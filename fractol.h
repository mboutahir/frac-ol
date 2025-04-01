/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutahi <mboutahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:32:15 by mboutahi          #+#    #+#             */
/*   Updated: 2025/04/01 18:28:29 by mboutahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
#include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

//we use square to keep the rendering math simple
#define hight	800
#define width	800

#define BLACK				0x000000  // RGB(0, 0, 0)
#define WHITE				0xFFFFFF  // RGB(255, 255, 255)
#define BLUE				0x0000FF  // RGB(0, 0, 255)
#define GREEN				0x00FF00  // RGB(0, 255, 0)
#define RED					0xFF0000 
#define ELECTRIC_PURPLE		0x8A2BE2  // RGB(138, 43, 226)
#define HOT_PINK			0xFF69B4  // RGB(255, 105, 180)
#define NEON_GREEN			0x39FF14  // RGB(57, 255, 20)
#define CYAN				0x00FFFF  // RGB(0, 255, 255)
#define ELECTRIC_BLUE		0x7DF9FF  // RGB(125, 249, 255)
#define FLUORESCENT_ORANGE	0xFF5F00 // RGB(255, 95, 0)
#define BRIGHT_YELLOW		0xFFFF00  // RGB(255, 255, 0)
#define MAGENTA				0xFF00FF  // RGB(255, 0, 255)
#define LIME_GREEN			0x32CD32  // RGB(50, 205, 50)
#define RADICAL_RED			0xFF355E  // RGB(255, 53, 94)
#define GLOWING_BLUE		0x80B3FFFA
#define GLOWING_BLUE_OPAQUE	0x00B3FFFA 
//complex value
typedef struct s_complex
{
	//real
	double	real_num;
	//imagenary
	double	imgnry_num;
} t_complex;

typedef struct s_img
{
	void	*img_ptr; //pointer to actual image struct
	char	*pixels_ptr; //pointer to actual pixel struct
	int		bit_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_fractol
{
	char	*name;
	//MLX
	void	*mlx_connection; //mlx_int()
	void	*mlx_window; //mlx_new_window()
	//img
	t_img	img;
	//hooks variables TODO
	double	escape_value;
	int		iterations; //value tighed with image quality and rendering
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
double		map(double unscaled, double new_min, double new_max, double max); //scalling the big map to small map
t_complex	sum(t_complex z1, t_complex z2);
t_complex	square(t_complex z);
void		fractol_render(t_fractol *fractol);
int			key_handler(int keysym, t_fractol *fractol);
int			close_handler(t_fractol *fractol);
int			mouse_scroll(int button, int x, int y, t_fractol *fractol);
int			key_handler(int keycode, t_fractol *fractol);
double		atoi_double(char *str);
#endif