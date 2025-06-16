/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_close_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:00:16 by pdessant          #+#    #+#             */
/*   Updated: 2025/05/22 13:00:19 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	cleanup(t_fractol *fractol)
{
	if (fractol->img.img)
		mlx_destroy_image(fractol->win.mlx, fractol->img.img);
	if (fractol->win.win)
		mlx_destroy_window(fractol->win.mlx, fractol->win.win);
	if (fractol->win.mlx)
	{
		mlx_destroy_display(fractol->win.mlx);
		free(fractol->win.mlx);
	}
}

int	close_window_hook(t_fractol *fractol)
{
	cleanup(fractol);
	exit(0);
	return (0);
}

void	exit_with_error(t_fractol *fractol, const char *msg)
{
	ft_putendl_fd((char *)msg, 2);
	cleanup(fractol);
	exit(1);
}
// oppure printf(stderr)
