/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct_print_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:06:38 by pdessant          #+#    #+#             */
/*   Updated: 2025/02/03 10:51:48 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	print_char_string(va_list ag, const char *f, int index, int *ret)
{
	char	c;
	char	*s;

	if (f[index] == '%')
		ft_putchar_and_count_fd('%', 1, ret);
	else if (f[index] == 'c')
	{
		c = va_arg(ag, int);
		ft_putchar_and_count_fd(c, 1, ret);
	}
	else if (f[index] == 's')
	{
		s = va_arg(ag, char *);
		if (!s)
		{
			write (1, "(null)", 6);
			*ret += 6;
		}
		else
			ft_putstr_and_count_fd(s, 1, ret);
	}
}

void	ft_put_u_nbr(unsigned int u, int fd, int *ret)
{
	if (u > 9)
	{
		ft_put_u_nbr(u / 10, fd, ret);
		ft_put_u_nbr(u % 10, fd, ret);
	}
	else
		ft_putchar_and_count_fd(u + 48, fd, ret);
}

void	print_num(va_list ag, const char *f, int index, int *ret)
{
	int				n;
	unsigned int	u;

	if (f[index] == 'i' || f[index] == 'd')
	{
		n = va_arg(ag, int);
		ft_putnbr_and_count_fd(n, 1, ret);
	}
	else if (f[index] == 'u')
	{
		u = va_arg(ag, int);
		ft_put_u_nbr(u, 1, ret);
	}
}

void	print_hexa(va_list ag, const char *f, int index, int *ret)
{
	unsigned int	n;
	uintptr_t		p;

	if (f[index] == 'x' || f[index] == 'X')
	{
		n = va_arg(ag, unsigned int);
		if (f[index] == 'x')
			put_hexa_lower(n, 1, ret);
		else if (f[index] == 'X')
			put_hexa_upper(n, 1, ret);
	}
	else if (f[index] == 'p')
	{
		p = va_arg(ag, uintptr_t);
		put_p(p, 1, ret);
	}
}
