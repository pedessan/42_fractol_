/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:50:45 by pdessant          #+#    #+#             */
/*   Updated: 2024/11/26 17:05:51 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	x;
	size_t	s_l;

	s_l = ft_strlen(src);
	if (ft_strlen(dst) >= size)
		return (s_l + size);
	i = 0;
	while (dst[i])
		i++;
	if (size <= i)
		return (s_l + size);
	x = 0;
	while (((size - i - 1) > x) && src[x])
	{
		dst[i + x] = src[x];
		x++;
	}
	dst[i + x] = '\0';
	return (i + s_l);
}
/* int	main()
{
	//RICORDA DI COMPILARE CON -lbsd  !!
	char	a[] = "la";
	const char	b[] = "lala";
	size_t	l1 = strlcat(a, b, 3);
	size_t	l2 = ft_strlcat(a, b, 50);
	printf("%zu\n%zu\n", l1, l2);
	//printf("%zu\n%s\n", l1, a);
	return (0);
} */
