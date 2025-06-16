/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atodouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:05:51 by pdessant          #+#    #+#             */
/*   Updated: 2025/05/20 17:08:01 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	initialize_val(double *res, double *dec, double *sign, double *div)
{
	*res = 0.0;
	*dec = 0.0;
	*sign = 1.0;
	*div = 10.0;
}

static const char	*before_num(const char *str, double *sign)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign = -1.0;
		str++;
	}
	return (str);
}

double	ft_atodouble(const char *str)
{
	double	result;
	double	decimal;
	double	sign;
	double	div;

	initialize_val(&result, &decimal, &sign, &div);
	str = before_num(str, &sign);
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			decimal += (*str - '0') / div;
			div *= 10.0;
			str++;
		}
	}
	return (sign * (result + decimal));
}
