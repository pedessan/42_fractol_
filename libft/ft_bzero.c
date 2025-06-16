/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:36:37 by pdessant          #+#    #+#             */
/*   Updated: 2024/11/19 18:00:30 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*a;

	a = (char *)s;
	i = 0;
	while (i < n)
	{
		a[i] = '\0';
		i++;
	}
}

/* int	main()
{
	char	s[] = "ciao sono Petra!";
	char	a[] = "ciao sono Petra!";
	bzero(s + 3, 4);
	ft_bzero(a + 3, 4);
	printf("%s\n%s\n", s, a);
	return (0);
} */
