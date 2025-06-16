/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_my_pixel_put.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:27:24 by pdessant          #+#    #+#             */
/*   Updated: 2025/05/22 17:27:29 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	put_pixel(t_fractol *fractol, int x, int y, int color)
{
	char	*dst;

	dst = fractol->img.addr + (y * fractol->img.line_len + x \
			* (fractol->img.bpp / 8));
	*(unsigned int *)dst = color;
}

/*
 * put_pixel - Draws a pixel with a given color
 					at coordinates (x, y) on the image.
 *
 * Parameters:
 *   fractol - Pointer to fractal data structure containing image info
 *   x, y    - Pixel coordinates on the image
 *   color   - Color value to set at the pixel (usually 0xRRGGBB format)
 *
 * How it works:
 *   - Calculates the memory address (dst) of the pixel inside the image buffer,
 *     using the image’s line length and bytes per pixel (bpp).
 *   - Writes the color value directly to that memory location,
 *     setting the pixel’s color on the image.
 *
 * Purpose:
 *   To place colored pixels on the image buffer for fractal rendering.
 */
