/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_init_values.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:59:11 by pdessant          #+#    #+#             */
/*   Updated: 2025/05/22 12:59:15 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_values(t_fractol *fractol, char **av)
{
	fractol->name = av[1];
	if (ft_strncmp(fractol->name, "julia", 5) == 0)
	{
		fractol->c.re = ft_atodouble(av[2]);
		fractol->c.im = ft_atodouble(av[3]);
	}
	fractol->needs_redraw = 1;
	fractol->win.xmin = -2.0;
	fractol->win.ymin = 2.0;
	fractol->win.xmax = 2.0;
	fractol->win.ymax = -2.0;
	fractol->win.width = WIDTH;
	fractol->win.height = HEIGHT;
	fractol->win.zoom = 0;
}
