/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:02:06 by pdessant          #+#    #+#             */
/*   Updated: 2025/05/22 17:19:09 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_fractal_point(t_fractol *fractol, int i)
{
	fractol->color = get_color(i);
	put_pixel(fractol, fractol->win.x, fractol->win.y, fractol->color);
}

int	get_color(int i)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (i == MAX_ITER)
		return (0x000000);
	t = (double)i / MAX_ITER;
	r = (int)(sin(5 * t) * 127 + 128);
	g = (int)(sin(7 * t + 2) * 127 + 128);
	b = (int)(sin(9 * t + 4) * 127 + 128);
	return ((r << 16) | (g << 8) | b);
}
/*
 * color_fractal_point:
 *  - Assigns a color to the current pixel based on iteration count i.
 *  - Uses get_color(i) to translate i into an RGB color.
 *  - Draws the pixel at coordinates (win.x, win.y) with the chosen color.
 *
 * get_color:
 *  - Maps iteration count i to a smooth RGB color gradient.
 *  - If i == MAX_ITER (point inside the fractal), returns black (0x000000).
 *  - Otherwise, calculates normalized t = i / MAX_ITER in [0,1].
 *  - Computes red, green, and blue components using sine waves with different
 * 			frequencies and phase shifts:
 *      r = sin(5t)*127 + 128
 *      g = sin(7t + 2)*127 + 128
 *      b = sin(9t + 4)*127 + 128
 *  - Combines r, g, b into a single 24-bit color value.
 * 
 * This coloring creates smooth, vivid gradients to visually distinguish
 * points escaping at different iteration counts, adding depth and beauty
 * to the fractal image.
 * 
 * 
 * 

   - i is the number of iterations (how many times the calculation was 
   		repeated for that point).

   - MAX_ITER is the maximum number of iterations performed.

So t is a number between 0 and 1 that indicates the “position” of that point
in the iteration process, normalized with respect to the maximum.

In simple words, t tells how “far” the point is from the maximum iteration limit,
expressed as a fraction.

It is used to smoothly vary the colors,
linking the number of iterations to a value
that can be used as a parameter for the sine functions that generate the colors.
 * 


5, 7, and 9 are simply numbers chosen to vary the frequencies of the sine waves.
Each color (red, green, blue) uses a different frequency to create a gradient and
movement effect in the final color.

sin is the sine function, a mathematical function that produces a smooth wave
oscillating between -1 and 1. Here, it transforms a linear value (t, from 0 to 1)
into a gentle wave that changes over time, allowing the color to change
gradually and rhythmically.

Why do we multiply by 127 and add 128?

The sine function returns values between -1 and 1, but RGB colors need to be
between 0 and 255 (unsigned integers).

    Multiplying by 127 scales the value from [-1,1] to [-127,127].

    Adding 128 shifts the value so it’s always positive, that is, from [1,255].

This way we get a valid RGB value that smoothly
varies between minimum and maximum, never going out of the allowed range.
 
 */

/* int	get_color(int i)
{
	if (i == MAX_ITER)
		return (0x000000); // nero al centro

	int colors[6] = {
		0xFF00FF, // fucsia
		0x00FFFF, // ciano
		0xFFFF00, // giallo
		0x00FF00, // verde
		0xFF0000, // rosso
		0x0000FF  // blu
	};

	return colors[i % 6];
} */

/* int get_color(int i)  (colori sfumati)
{
	if (i == MAX_ITER)
		return (COLOR_INSIDE); // nero
	
	double t = (double)i / MAX_ITER;

	// RGB componendo a mano
	int r = (int)(9 * (1 - t) * t * t * t * 255);
	int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

	return ((r << 16) | (g << 8) | b);
} */

/* 
int	close_to(t_complex_n a, t_complex_n b)
{
	double	diff_re;
	double	diff_im;
	double	dist;

	diff_re = a.re - b.re;
	diff_im = a.im - b.im;
	dist = diff_re * diff_re + diff_im * diff_im;
	return (dist < 0.00001);
}

void	color_fractal_point(t_fractol *f, int iter)
{
	t_complex_n z = f->z;

	if (close_to(z, (t_complex_n){1.0, 0.0}))
		put_pixel(f, f->win.x, f->win.y, color_for_root(1, iter));
	else if (close_to(z, (t_complex_n){-0.5, sqrt(3)/2}))
		put_pixel(f, f->win.x, f->win.y, color_for_root(2, iter));
	else if (close_to(z, (t_complex_n){-0.5, -sqrt(3)/2}))
		put_pixel(f, f->win.x, f->win.y, color_for_root(3, iter));
	else
		put_pixel(f, f->win.x, f->win.y, 0x000000); // nero se non converge
} */

/* void	mandelbrot(t_fractol *fractol)
{
	//come fare?
} */
