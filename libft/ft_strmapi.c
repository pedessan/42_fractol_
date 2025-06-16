/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:30:02 by pdessant          #+#    #+#             */
/*   Updated: 2024/11/26 17:14:17 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* char	f(unsigned int i, char c)
{
	c = c + i;
	return (c);
} */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	new = ft_strdup(s);
	if (!new)
		return (NULL);
	while (new[i])
	{
		new[i] = f(i, s[i]);
		i++;
	}
	return (new);
}
/* int	main()
{
	char	s[] = "aaaaaaaaaaaaaaaaa";
	//char	s[] = "";
	char	*new;
	new = ft_strmapi(s, f);
	printf("%s\n", new);
	if (new)
		free(new);
	return (0);
} */
