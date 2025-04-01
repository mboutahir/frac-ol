/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_scale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutahi <mboutahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:43:47 by mboutahi          #+#    #+#             */
/*   Updated: 2025/03/28 18:18:22 by mboutahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double unscaled, double new_max, double new_min, double max)
{
	double	min; 
	min = 0;

	return ((new_max - new_min) * (unscaled - min) 
		/ (max - min) + new_min);
}
