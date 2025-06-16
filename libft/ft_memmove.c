/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:44:22 by pdessant          #+#    #+#             */
/*   Updated: 2024/11/26 17:18:16 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	d = (char *)dest;
	s = (const char *)src;
	if (d == s || n == 0)
		return (dest);
	if (d > s)
	{
		i = n;
		while (i > 0)
		{
			i--;
			d[i] = s[i];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
/* 
int	main()
{
	char	s[] = "ciaoooo sn pe!";
	char	dst[] = "come stai?jgjddhgkgkjjjjjj";
	char	dst2[] = "come stai?jgjddhgkgkjjjjjj";
	memmove(dst, s, 16);
	ft_memmove(dst2, s, 16);
	printf ("%s\n%s\n", dst, dst2);
	return (0);
} */
