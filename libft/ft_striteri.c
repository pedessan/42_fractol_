/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:17:20 by pdessant          #+#    #+#             */
/*   Updated: 2024/11/26 17:10:42 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	f(unsigned int i, char *c)
{
	*c += i;
}  */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}
/* int	main()
{
	char	s[] = "aaaaaaa";
	ft_striteri(s, f);
	printf ("%s\n", s);
	return (0);
} */
