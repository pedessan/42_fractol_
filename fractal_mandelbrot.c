/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:44:54 by pdessant          #+#    #+#             */
/*   Updated: 2025/05/22 17:05:59 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_math(t_fractol *f)
{
	int		i;
	double	tmp;

	i = 0;
	while (i < MAX_ITER && (f->z.re * f->z.re + f->z.im * f->z.im) <= 4)
	{
		tmp = f->z.re;
		f->z.re = f->z.re * f->z.re - f->z.im * f->z.im + f->c.re;
		f->z.im = 2 * tmp * f->z.im + f->c.im;
		i++;
	}
	return (i);
}

void	mandelbrot(t_fractol *fractol)
{
	draw_fractal(fractol, setup_mandelbrot, mandelbrot_math);
}

/*
 * Mandelbrot set iteration:
 * 
 * Each pixel corresponds to a complex number c (f->c).
 * Start with z = 0 (stored in f->z).
 * 
 * Iteratively compute:
 *    z = z^2 + c
 * where
 *    z^2 = (z.re + i*z.im)^2 = (z.re^2 - z.im^2) + i*(2 * z.re * z.im)
 * 
 * Loop stops when either:
 *    - Maximum iterations reached (MAX_ITER),
 *    - Or |z|^2 = z.re^2 + z.im^2 exceeds 4 (diverges).
 * 
 * The iteration count 'i' returned indicates how fast z escapes to infinity.
 * Pixels where z does not escape (i == MAX_ITER) are inside the Mandelbrot set,
 * others are outside and can be colored based on 'i' to show fractal detail.
 */
