/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_and_count_fd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:44:01 by pdessant          #+#    #+#             */
/*   Updated: 2025/02/19 10:58:33 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_and_count_fd(char *s, int fd, int *ret)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr_and_count_fd("null", fd, ret);
		return ;
	}
	while (s[i])
	{
		ft_putchar_and_count_fd(s[i], fd, ret);
		i++;
	}
}
