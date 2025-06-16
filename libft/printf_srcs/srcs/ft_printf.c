/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:16:10 by pdessant          #+#    #+#             */
/*   Updated: 2025/02/03 10:47:15 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	direct_print(const char *f, va_list	ag, int i, int *ret)
{
	if (f[i] == 'c' || f[i] == 's' || f[i] == '%')
		print_char_string(ag, f, i, ret);
	else if (f[i] == 'i' || f[i] == 'd' || f[i] == 'u')
		print_num(ag, f, i, ret);
	else if (f[i] == 'x' || f[i] == 'X' || f[i] == 'p')
		print_hexa(ag, f, i, ret);
}

//devi ritornare la lunghezza di cio' che e' stato ritornato compreso '\0'!

int	ft_printf(const char *f, ...)
{
	va_list	ag;
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	va_start(ag, f);
	while (f[i])
	{
		if (f[i] == '%')
		{
			i++;
			direct_print(f, ag, i, &ret);
		}
		else
			ft_putchar_and_count_fd(f[i], 1, &ret);
		i++;
	}
	va_end(ag);
	return (ret);
}
