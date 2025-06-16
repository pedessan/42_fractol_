/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:17:30 by pdessant          #+#    #+#             */
/*   Updated: 2024/11/26 17:04:23 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*a;
	char	*b;

	a = (char *)src;
	b = (char *)dest;
	if (!a && !b)
		return (0);
	i = 0;
	while (i < n)
	{
		b[i] = a[i];
		i++;
	}
	return (dest);
}
/* 
int	main()
{
	char	*la = NULL;
	char	dst[12];
	char	dst2[12];
	memcpy(dst, la, 11);
	ft_memcpy(dst2, la, 11);
	dst[11] = '\0';
	dst2[11] = '\0';
	printf("%s\n%s\n", dst, dst2);
	return (0);
} */
