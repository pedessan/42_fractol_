/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:51:33 by pdessant          #+#    #+#             */
/*   Updated: 2025/05/22 13:00:49 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (parsing_args(ac, av) == 0)
	{
		init_values(&fractol, av);
		fractol.win.mlx = mlx_init();
		fractol.win.win = mlx_new_window(fractol.win.mlx, WIDTH, \
				HEIGHT, "fractol");
		fractol.img.img = mlx_new_image(fractol.win.mlx, WIDTH, HEIGHT);
		fractol.img.addr = mlx_get_data_addr(fractol.img.img, \
				&fractol.img.bpp, &fractol.img.line_len, &fractol.img.endian);
		mlx_hook_event(&fractol);
		mlx_loop_hook(fractol.win.mlx, render_if_needed, &fractol);
		mlx_loop(fractol.win.mlx);
	}
	return (0);
}
