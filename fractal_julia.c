/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:43:10 by pdessant          #+#    #+#             */
/*   Updated: 2025/05/22 17:08:06 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_math(t_fractol *f)
{
	int		iter;
	double	temp;

	iter = 0;
	while (((f->z.re * f->z.re) + (f->z.im * f->z.im)) <= 4.0 \
				&& iter < MAX_ITER)
	{
		temp = (f->z.re * f->z.re) - (f->z.im * f->z.im) + f->c.re;
		f->z.im = 2.0 * (f->z.re * f->z.im) + f->c.im;
		f->z.re = temp;
		iter++;
	}
	return (iter);
}

void	julia(t_fractol *fractol)
{
	draw_fractal(fractol, setup_julia, julia_math);
}

/*
 * Julia set iteration:
 * 
 * Each pixel corresponds to an initial complex number z (f->z).
 * The constant complex parameter c (f->c) is fixed for the entire image.
 * 
 * Iteratively compute:
 *    z = z^2 + c
 * where
 *    z^2 = (z.re + i*z.im)^2 = (z.re^2 - z.im^2) + i*(2 * z.re * z.im)
 * 
 * Loop stops when either:
 *    - Maximum iterations reached (MAX_ITER),
 *    - Or |z|^2 = z.re^2 + z.im^2 exceeds 4 (z escapes to infinity).
 * 
 * The iteration count 'iter' returned shows how quickly z diverges.
 * Points where z remains bounded (iter == MAX_ITER) belong to the Julia set,
 * others escape and can be colored based on 'iter' to reveal fractal structure.
 */
