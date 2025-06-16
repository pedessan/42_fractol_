/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:42:39 by pdessant          #+#    #+#             */
/*   Updated: 2024/11/26 17:08:10 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(src);
	i = 0;
	if (size <= 0)
		return (s_len);
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (s_len);
}
/* int	main()
{
	//RICORDA DI COMPILARE CON -lbsd  !!
	const char	la[] = "come stai???";
	char	what[50];
	char	what2[50];
	size_t	a;
	size_t	b;
	
	a = strlcpy(what, la, 5);
	b = strlcpy(what2, la, 5);
	printf("%zu\n", a);
	printf("%zu\n", b);
	return (0);
	//b = ft_strlcpy(what2, la, 5);
	//printf ("%s\n%s\n", a);
} */
