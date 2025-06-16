/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mlx_hook_event.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:40:34 by pdessant          #+#    #+#             */
/*   Updated: 2025/05/21 12:10:02 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	hook_left_up(double *a, double *b, double shift, int *n_redraw)
{
	*a -= shift;
	*b -= shift;
	*n_redraw = 1;
}

static void	hook_right_down(double *a, double *b, double shift, int *n_redraw)
{
	*a += shift;
	*b += shift;
	*n_redraw = 1;
}

int	key_hook(int keycode, t_fractol *f)
{
	double	shift;

	shift = (f->win.xmax - f->win.xmin) * 0.05;
	if (keycode == KEY_ESC)
		close_window_hook(f);
	else if (keycode == ARROW_KEY_LEFT)
		hook_left_up(&f->win.xmin, &f->win.xmax, shift, &f->needs_redraw);
	else if (keycode == ARROW_KEY_RIGHT)
		hook_right_down(&f->win.xmin, &f->win.xmax, shift, &f->needs_redraw);
	else if (keycode == ARROW_KEY_UP)
		hook_left_up(&f->win.ymin, &f->win.ymax, shift, &f->needs_redraw);
	else if (keycode == ARROW_KEY_DOWN)
		hook_right_down(&f->win.ymin, &f->win.ymax, shift, &f->needs_redraw);
	return (0);
}

void	mlx_hook_event(t_fractol *fractol)
{
	mlx_hook(fractol->win.win, 17, 0, (int (*)(void *)) \
				close_window_hook, fractol);
	mlx_hook(fractol->win.win, 2, 1L << 0, key_hook, fractol);
	mlx_mouse_hook(fractol->win.win, mouse_hook, fractol);
}
/* 
int	key_hook(int keycode, t_fractol *fractol)
{
	double	shift;

	shift = (fractol->win.xmax - fractol->win.xmin) * 0.05;
	if (keycode == KEY_ESC)
		close_window_hook(fractol);
	else if (keycode == ARROW_KEY_LEFT)
	{
		fractol->win.xmin -= shift;
		fractol->win.xmax -= shift;
		fractol->needs_redraw = 1;
	}
	else if (keycode == ARROW_KEY_RIGHT)
	{
		fractol->win.xmin += shift;
		fractol->win.xmax += shift;
		fractol->needs_redraw = 1;
	}
	else if (keycode == ARROW_KEY_UP)
	{
		fractol->win.ymin -= shift;
		fractol->win.ymax -= shift;
		fractol->needs_redraw = 1;
	}
	else if (keycode == ARROW_KEY_DOWN)
	{
		fractol->win.ymin += shift;
		fractol->win.ymax += shift;
		fractol->needs_redraw = 1;
	}
	return (0);
}
*/
