/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:59:44 by pdessant          #+#    #+#             */
/*   Updated: 2025/05/22 17:22:40 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	parsing_args(int ac, char **av)
{
	int	check;

	check = 0;
	if ((ac == 2) && (ft_strncmp(av[1], "mandelbrot", 11) == 0))
		return (0);
	else if ((ac == 4) && (ft_strncmp(av[1], "julia", 5) == 0))
	{
		check = check_string(av[2]) + check_string(av[3]);
		if (check != 0)
			print_instructions();
		return (check);
	}
	else if ((ac == 2) && (ft_strncmp(av[1], "newton", 6) == 0))
		return (0);
	else
		print_instructions();
	return (1);
}
