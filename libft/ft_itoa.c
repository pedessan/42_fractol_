/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:26:31 by pdessant          #+#    #+#             */
/*   Updated: 2024/11/26 17:06:58 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*itoa_conv(char *s, int n, int sign, int i)
{
	while ((sign == 0 && i >= 0) || (sign == 1 && i > 0))
	{
		s[i] = n % 10 + 48;
		n /= 10;
		i--;
	}
	if (sign == 1)
		s[i] = 45;
	return (s);
}

void	if_negative(int *n, int *sign, int *i)
{
	if (*n < 0)
	{
		*sign = 1;
		*i = 2;
		*n *= -1;
	}
}

char	*ft_itoa(int n)
{
	char	*s;
	int		checker;
	int		i;
	int		sign;

	i = 1;
	sign = 0;
	if (n == -2147483648)
	{
		s = ft_strdup("-2147483648");
		return (s);
	}
	if_negative(&n, &sign, &i);
	checker = n;
	while (checker / 10 > 0 && i++)
		checker /= 10;
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	s[i] = '\0';
	i--;
	itoa_conv(s, n, sign, i);
	return (s);
}
/* int	main()
{
	//int	n = -2147483648;
	int	n = 42;
	char	*num = ft_itoa(n);
	printf("%s\n", num);
	free (num);
	return (0);	
} */
