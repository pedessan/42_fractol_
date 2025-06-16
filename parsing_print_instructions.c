/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_print_instructions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:59:54 by pdessant          #+#    #+#             */
/*   Updated: 2025/05/22 12:59:58 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_instructions(void)
{
	ft_printf(BOLD "Usage:\n\n\n" RESET);
	ft_printf("\t" YELLOW "For Mandelbrot fractal launch:" RESET " "
		GREEN "./fractol mandelbrot\n\n\n" RESET);
	ft_printf("\t" YELLOW "For Julia fractal launch:\n" RESET
		"\t   " GREEN "./fractol julia <real_part> <imaginary_part>\n\n" RESET);
	ft_printf("\t" FUCHSIA "example:\n\t\t./fractol julia"
		" -0.79 0.25\n\n\n" RESET);
	ft_printf("\t" YELLOW "For Newton fractal launch:" RESET " "
		GREEN "./fractol newton\n\n\n" RESET);
	ft_printf("\t" CYAN "You can zoom in and out with your mouse,\n"
		"\tand move around with the arrow keys!\n\n\n" RESET);
}
/* void	print_instructions(void)
{
	ft_printf("Usage:\n\n\n\t"
			"For Mandelbrot fractal launch: ./fractol mandelbrot\n\n\n\t"
			"For Julia fractal launch:\n"
			"           ./fractol julia  <real_part>  <imaginary_part>"
			"\n\n\texample:\n\t\t./fractol julia -0.79 0.25\n\n\n\t"
			"For Newton fractal lauch: ./fractol Newton\n\n\n"
			"You can zoom in and out with your mouse and move around with"
			"key arrows!\n");
} */
