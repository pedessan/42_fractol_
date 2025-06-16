/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:24:14 by pdessant          #+#    #+#             */
/*   Updated: 2024/11/26 17:05:03 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (i < len && big[i])
	{
		j = 0;
		while (i + j < len && big[i + j] && big[i + j] == little[j])
		{
			j++;
			if (!little[j])
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}

/* int	main()
{
	const char	a[] = "Ciao sono Petra!";
	const char	b[] = "Petra";
	char	*p;
	char	*p2;
	int		len = 20;
	p = strnstr(a, b, len);
	p2 = ft_strnstr(a, b, len);
	printf("%s\n%s\n", p, p2);
	return (0);
} */
