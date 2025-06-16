/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:35:31 by pdessant          #+#    #+#             */
/*   Updated: 2024/11/26 17:16:25 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
			return ((unsigned char *)s + i);
		i++;
	}
	return (NULL);
}
/* int	main()
{
	char	s[] = "non riesco a concentrarmi";
	char	a[] = "non riesco a concentrarmi";
	char	c = '\0';
	printf("%s\n%s\n", (char *)memchr(s, c, 30), (char *)ft_memchr(a, c, 30));
	return(0);
} */
