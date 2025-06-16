/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:12:38 by pdessant          #+#    #+#             */
/*   Updated: 2024/11/19 10:57:19 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	ssize_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/* int	main()
{
	char	s1[] = "lalala";
	ssize_t n1 = strlen(s1);
	ssize_t n2 = ft_strlen(s1);
	printf ("%zd\n%zd\n", n1, n2);
	return (0);
} */
