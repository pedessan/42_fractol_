/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:18:15 by pdessant          #+#    #+#             */
/*   Updated: 2024/11/26 17:13:46 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*cpy;

	cpy = s;
	while (n > 0)
		cpy[--n] = (unsigned char)c;
	return (s);
}
/* int	main()
{
	char	a[50];
	char	b[50];
	char c;
	c = 32;
	//int	i = 0;
	memset(a, c, 5);
	ft_memset(b, c, 5);
	printf ("%s\n%s\n", a, b);
	return (0);
} */
