/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:52:04 by pdessant          #+#    #+#             */
/*   Updated: 2025/04/22 11:29:48 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0' || s2[i] == '\0')
			break ;
		i++;
	}
	return (0);
}
/* int	main()
{
	int	a;
	int	b;
	char	s1[] = "ciao";
	const char	s2[] = "ciaeo";
	int n = 5;
	a = ft_strncmp(s1, s2, n);
	b = ft_strncmp(s1, s2, n);
	printf("%d\n", a);
	printf("%d\n", b);
	return (0);
}  */
