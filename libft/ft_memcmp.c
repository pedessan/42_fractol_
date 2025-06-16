/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:45:43 by pdessant          #+#    #+#             */
/*   Updated: 2024/11/26 17:22:47 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*a;
	const unsigned char	*b;
	size_t				i;

	a = (const unsigned char *)s1;
	b = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	return (0);
}

/* int	main()
{
	const char	s1[] = "ciao";
	const char	s2[] = "ciao";
	int	n = 20;
	int	a = memcmp(s1, s2, n);
	int	b = ft_memcmp(s1, s2, n);
	printf ("%d\n%d\n\n", a, b);
	printf ("%d\n%d\n", memcmp(s1, s2, n), ft_memcmp(s1, s2, n));
	return (0);
} */
