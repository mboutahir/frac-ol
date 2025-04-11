/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutahi <mboutahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:32:27 by mboutahi          #+#    #+#             */
/*   Updated: 2025/04/05 13:23:35 by mboutahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[n])
		n++;
	while (s2[i])
		i++;
	if (i != n)
		return (0);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_error(void)
{
	write(2, "Please enter: ./fractol mandelbrot", 34);
	write(2, " \nOR  \t\t./fractol julia <valid_value1> <valid_value2>\n", 55);
	write(2, "          ----------------------------\n", 39);
	write(2, "in case of julia set please enter values between 2 and -2\n", 58);
	exit(1);
}

static double	double_part(char *str)
{
	double	double_part;
	double	pow;

	pow = 1;
	double_part = 0;
	while (*str <= '9' && *str >= '0' && *str)
	{
		pow /= 10;
		double_part = double_part + (*str++ - 48) * pow;
	}
	return (double_part);
}

double	atoi_double(char *str)
{
	long	int_part;
	int		j;
	double	fractional_part;

	j = 1;
	int_part = 0;
	fractional_part = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			j = -j;
		++str;
	}
	while (*str <= '9' && *str >= '0' && *str)
	{
		int_part = 10 * int_part +(*str++ - '0');
		if (int_part > 2 || int_part < -2)
			ft_error();
	}
	if (*str == '.')
		++str;
	fractional_part = double_part(str);
	return ((int_part + fractional_part) * j);
}
