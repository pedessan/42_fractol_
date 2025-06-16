/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:41:52 by pdessant          #+#    #+#             */
/*   Updated: 2024/11/26 17:09:00 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last_occurrence;

	last_occurrence = NULL;
	while (*s)
	{
		if (*s == (char)c)
			last_occurrence = s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((char *)last_occurrence);
}

/* int	main()
{
	char	*s;
	char	*m;
	s = strrchr("ciaoi 42!", '9');
	m = ft_strrchr("ciaoi 42!", '9');
	printf("%s\n%s\n", s, m);
	//printf("%s\n", s);
	return (0);
} */
