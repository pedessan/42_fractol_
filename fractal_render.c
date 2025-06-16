/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:59:21 by pdessant          #+#    #+#             */
/*   Updated: 2025/05/22 12:59:26 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	render_if_needed(t_fractol *fractol)
{
	if (fractol->needs_redraw)
	{
		if (ft_strncmp(fractol->name, "mandelbrot", 11) == 0)
			mandelbrot(fractol);
		else if (ft_strncmp(fractol->name, "julia", 5) == 0)
			julia(fractol);
		else if (ft_strncmp(fractol->name, "newton", 6) == 0)
			newton(fractol);
		fractol->needs_redraw = 0;
	}
	return (0);
}
