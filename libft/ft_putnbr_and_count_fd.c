/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_and_count_fd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 10:47:58 by pdessant          #+#    #+#             */
/*   Updated: 2025/02/19 10:49:39 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_and_count_fd(int n, int fd, int *ret)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		*ret += 11;
		return ;
	}
	if (n < 0)
	{
		ft_putchar_and_count_fd('-', fd, ret);
		n *= -1;
	}
	if (n >= 0)
	{
		if (n > 9)
		{
			ft_putnbr_and_count_fd(n / 10, fd, ret);
			ft_putnbr_and_count_fd(n % 10, fd, ret);
		}
		else
		{
			ft_putchar_and_count_fd(n + 48, fd, ret);
		}
	}
}
