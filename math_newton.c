/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_newton.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 17:12:31 by pdessant          #+#    #+#             */
/*   Updated: 2025/05/20 17:14:50 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex_n	complex_mult(t_complex_n a, t_complex_n b)
{
	t_complex_n	res;

	res.re = a.re * b.re - a.im * b.im;
	res.im = a.re * b.im + a.im * b.re;
	return (res);
}

t_complex_n	complex_sub(t_complex_n a, t_complex_n b)
{
	t_complex_n	res;

	res.re = a.re - b.re;
	res.im = a.im - b.im;
	return (res);
}

t_complex_n	complex_div(t_complex_n a, t_complex_n b)
{
	t_complex_n	res;
	double		denom;

	denom = b.re * b.re + b.im * b.im;
	res.re = (a.re * b.re + a.im * b.im) / denom;
	res.im = (a.im * b.re - a.re * b.im) / denom;
	return (res);
}

t_complex_n	complex_mult_scalar(t_complex_n a, double scalar)
{
	t_complex_n	res;

	res.re = a.re * scalar;
	res.im = a.im * scalar;
	return (res);
}
