/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:55:06 by pdessant          #+#    #+#             */
/*   Updated: 2025/05/21 12:14:33 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_fractal(t_fractol *f, t_setup_func setup, t_math_func math)
{
	t_win		win;
	t_complex_n	cn;
	int			i;

	win.zoom_x = (f->win.xmax - f->win.xmin) / (double)(f->win.width);
	win.zoom_y = (f->win.ymax - f->win.ymin) / (double)(f->win.height);
	win.y = 0;
	while (win.y < f->win.height)
	{
		win.x = 0;
		while (win.x < f->win.width)
		{
			cn.re = f->win.xmin + win.x * win.zoom_x;
			cn.im = f->win.ymin + win.y * win.zoom_y;
			setup(f, cn.re, cn.im);
			i = math(f);
			f->win.x = win.x;
			f->win.y = win.y;
			color_fractal_point(f, i);
			win.x++;
		}
		win.y++;
	}
	mlx_put_image_to_window(f->win.mlx, f->win.win, f->img.img, 0, 0);
}

/* void	draw_fractal(t_fractol *f, t_setup_func setup, t_math_func math)
{
	int		x;
	int		y;
	int		i;
	double	real;
	double	imag;
	double	zoom_x;
	double	zoom_y;

	zoom_x = (f->win.xmax - f->win.xmin) / (double)(f->win.width);
	zoom_y = (f->win.ymax - f->win.ymin) / (double)(f->win.height);
	y = 0;
	while (y < f->win.height)
	{
		x = 0;
		while (x < f->win.width)
		{
			real = f->win.xmin + x * zoom_x;
			imag = f->win.ymin + y * zoom_y;
			setup(f, real, imag);
			i = math(f);
			f->win.x = x;
			f->win.y = y;
			color_fractal_point(f, i);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->win.mlx, f->win.win, f->img.img, 0, 0);
} */
