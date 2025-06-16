/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:44:49 by pdessant          #+#    #+#             */
/*   Updated: 2024/11/26 17:10:19 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		tot_len;

	tot_len = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc((tot_len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		new[i] = *s2;
		i++;
		s2++;
	}
	new[i] = '\0';
	return (new);
}
/* int	main()
{
	char	a[] = "Ciao";
	char	b[] = " sono Pe!";
	char	*n = ft_strjoin(a, b);
	printf ("%s\n", n);
	free (n);
	return (0);
} */
