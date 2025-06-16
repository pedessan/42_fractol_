/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hexa_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:48:55 by pdessant          #+#    #+#             */
/*   Updated: 2025/02/03 10:52:34 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	put_hexa_lower(unsigned int n, int fd, int *ret)
{
	if (n < 16)
		ft_putchar_and_count_fd("0123456789abcdef"[n], fd, ret);
	else if (n >= 16)
	{
		put_hexa_lower(n / 16, fd, ret);
		put_hexa_lower(n % 16, fd, ret);
	}
}

void	put_hexa_upper(unsigned int n, int fd, int *ret)
{
	if (n < 16)
		ft_putchar_and_count_fd("0123456789ABCDEF"[n], fd, ret);
	else if (n >= 16)
	{
		put_hexa_upper(n / 16, fd, ret);
		put_hexa_upper(n % 16, fd, ret);
	}
}

void	put_p_printer(uintptr_t p, int fd, int *ret)
{
	if (p < 16)
		ft_putchar_and_count_fd("0123456789abcdef"[p], fd, ret);
	else if (p >= 16)
	{
		put_p_printer(p / 16, fd, ret);
		put_p_printer(p % 16, fd, ret);
	}
}

void	put_p(uintptr_t p, int fd, int *ret)
{
	if (p == 0)
		ft_putstr_and_count_fd("(nil)", fd, ret);
	else
	{
		ft_putstr_and_count_fd("0x", fd, ret);
		put_p_printer(p, fd, ret);
	}
}
