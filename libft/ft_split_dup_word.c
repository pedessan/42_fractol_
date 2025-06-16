/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_dup_word.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:50:17 by pdessant          #+#    #+#             */
/*   Updated: 2025/04/04 16:30:46 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_split_dup_word(char *s)
{
	int		i;
	char	*new;
	int		len;

	i = 0;
	len = ft_split_word_len(s);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
