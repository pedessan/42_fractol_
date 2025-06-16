/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mouse_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:44:48 by pdessant          #+#    #+#             */
/*   Updated: 2025/05/22 17:21:56 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	double	zoom_factor;
	double	mouse_re;
	double	mouse_im;

	if (button == 4)
		zoom_factor = 0.9;
	else if (button == 5)
		zoom_factor = 1.1;
	else
		return (0);
	mouse_re = fractol->win.xmin + x *(fractol->win.xmax - fractol->win.xmin) \
				/ fractol->win.width;
	mouse_im = fractol->win.ymin + y * (fractol->win.ymax - fractol->win.ymin) \
				/ fractol->win.height;
	fractol->win.xmin = mouse_re + (fractol->win.xmin - mouse_re) * zoom_factor;
	fractol->win.xmax = mouse_re + (fractol->win.xmax - mouse_re) * zoom_factor;
	fractol->win.ymin = mouse_im + (fractol->win.ymin - mouse_im) * zoom_factor;
	fractol->win.ymax = mouse_im + (fractol->win.ymax - mouse_im) * zoom_factor;
	fractol->needs_redraw = 1;
	return (0);
}

/*
 * mouse_hook - Handles zooming of the fractal on mouse wheel events.
 *
 * Parameters:
 *   button - Mouse button code (4 for scroll up, 5 for scroll down)
 *   x, y   - Mouse cursor position in pixels
 *   fractol - Pointer to fractal data structure
 *
 * What it does:
 *   - Determines zoom factor based on mouse wheel direction:
 *       * 0.9 for zooming in (scroll up)
 *       * 1.1 for zooming out (scroll down)
 *   - Converts mouse pixel coordinates (x, y) to complex plane coordinates
 *     (mouse_re, mouse_im) according to current viewport limits.
 *   - Updates viewport limits (xmin, xmax, ymin, ymax) by zooming toward
 *     the point under the mouse cursor using the zoom factor.
 *   - Sets a flag (needs_redraw) to request the fractal be redrawn.
 *
 * Purpose:
 *   Zoom in/out centered on the mouse pointer to allow
 * interactive fractal exploration.
 */
