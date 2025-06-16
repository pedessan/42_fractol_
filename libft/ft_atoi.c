/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:33:58 by pdessant          #+#    #+#             */
/*   Updated: 2025/03/28 17:31:47 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	sign;

	res = 0;
	i = 0;
	sign = 1;
	while ((nptr[i] == 32) || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while ((nptr[i] >= '0') && (nptr[i] <= '9'))
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * sign);
}

/* int	main()
{
	const char	s[] = "  -	42ab";
	const char	s[] = " +42";
	int	a = atoi(s);
	int	b = ft_atoi(s);
	printf("%d\n%d\n", a, b);
	return (0);
} */
