/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_and_count_fd.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:46:33 by pdessant          #+#    #+#             */
/*   Updated: 2025/02/19 10:47:40 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_and_count_fd(char *s, int fd, int *ret)
{
	ft_putstr_and_count_fd(s, fd, ret);
	write (fd, "\n", 1);
}
