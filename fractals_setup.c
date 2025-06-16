/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:57:46 by pdessant          #+#    #+#             */
/*   Updated: 2025/05/20 16:32:01 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	setup_mandelbrot(t_fractol *f, double real, double imag)
{
	f->z.re = 0;
	f->z.im = 0;
	f->c.re = real;
	f->c.im = imag;
}

void	setup_julia(t_fractol *f, double real, double imag)
{
	f->z.re = real;
	f->z.im = imag;
}

void	setup_newton(t_fractol *f, double real, double imag)
{
	f->z.re = real;
	f->z.im = imag;
}
// Mandelbrot: z = 0, c = punto
// Julia: z = punto, c = costante già fissata
	// f->c resta invariato, è settata altrove
// Newton: z = punto, c non serve
