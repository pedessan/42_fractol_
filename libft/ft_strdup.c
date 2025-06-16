/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:24:07 by pdessant          #+#    #+#             */
/*   Updated: 2024/11/26 17:16:02 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*new;

	i = 0;
	len = ft_strlen(s);
	new = (char *)malloc((len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
/* 
int	main()
{
	char	a[] = "Ciao sono Petra!";
	char	*orig = strdup(a);
	char	*b = ft_strdup(a);
	printf ("%s\n%s\n", orig, b);
	free(orig);
	free(b);
	return (0);
} */
