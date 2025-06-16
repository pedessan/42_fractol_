/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:20:41 by pdessant          #+#    #+#             */
/*   Updated: 2024/11/26 17:22:22 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	if_in_set(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		i;
	int		len;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(s1);
	while (if_in_set((char *)set, s1[i]) == 1)
		i++;
	while (if_in_set((char *)set, s1[len - 1]) == 1)
		len--;
	if (len < i)
		new = (char *)malloc(1);
	else
		new = (char *)malloc((len - i + 1) * sizeof(char));
	if (!new)
		return (NULL);
	while (i < len && s1[i])
		new[j++] = s1[i++];
	new[j] = '\0';
	return (new);
}
/* 
int	main()
{
	char	a[] = "Mondo! Come va?!";
	char	set[] = "ciao!";
	char	*n = ft_strtrim(a, set);
	printf ("%s\n", n);
	return (0);
} */
