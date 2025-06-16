/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_count_word.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:48:14 by pdessant          #+#    #+#             */
/*   Updated: 2025/04/04 16:29:58 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_split_count_word(char *s)
{
	int	i;
	int	flag;
	int	words;

	i = 0;
	flag = 1;
	words = 0;
	while (s[i])
	{
		if (ft_split_is_word(s[i]) && flag == 1)
		{
			words++;
			flag = 0;
		}
		else if (!ft_split_is_word(s[i]) && flag == 0)
			flag = 1;
		i++;
	}
	return (words);
}
