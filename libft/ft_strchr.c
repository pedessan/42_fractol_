/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:14:43 by pdessant          #+#    #+#             */
/*   Updated: 2024/11/21 11:44:51 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
/*char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != c)
		s++;
	if (c == '\0' && !*s)
		return ((char *)s);
	if (!*s && (*s != c))
		return (NULL);
	return ((char *)s);
}*/

/* int	main()
{
	char	*s;
	char	*m;
	s = strchr("ciao 42!", ' ');
	m = ft_strchr("ciao 42!", ' ');
	printf("%s\n%s\n", s, m);
	//printf("%s\n", s);
	return (0);
} */
