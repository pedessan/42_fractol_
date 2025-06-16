/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charset_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:23:07 by pdessant          #+#    #+#             */
/*   Updated: 2025/04/28 17:09:34 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_split_allocate_array(int count)
{
	char	**ar;

	ar = malloc(sizeof(char *) * (count + 1));
	if (!ar)
		return (NULL);
	return (ar);
}

static int	ft_split_process_words(char *s, char **ar)
{
	t_split	stru;

	stru.i = 0;
	stru.l = 0;
	stru.flag = 1;
	while (s[stru.i])
	{
		if (ft_split_is_word(s[stru.i]) && stru.flag == 1)
		{
			ar[stru.l] = ft_split_dup_word(&s[stru.i]);
			if (!ar[stru.l])
			{
				ft_free_s_matrix(ar);
				return (-1);
			}
			stru.l++;
			stru.flag = 0;
		}
		else if (!ft_split_is_word(s[stru.i]) && stru.flag == 0)
			stru.flag = 1;
		stru.i++;
	}
	ar[stru.l] = NULL;
	return (0);
}

char	**ft_charset_split(char *s)
{
	char	**ar;
	int		count;

	count = ft_split_count_word(s);
	ar = ft_split_allocate_array(count);
	if (!ar)
		return (NULL);
	if (ft_split_process_words(s, ar) == -1)
		return (NULL);
	return (ar);
}

/*
char	**ft_charset_split(char *s)
{
	char	**ar;
	int		count;
	int		flag;
	int		i;
	int		l;

	i = 0;
	l = 0;
	flag = 1;
	count = ft_split_count_word(s);
	ar = malloc(sizeof(char *) * (count + 1));
	if (!ar)
		return (NULL);
	while (s[i])
	{
		if (ft_split_is_word(s[i]) && flag == 1)
		{
			ar[l] = ft_split_dup_word(&s[i]);
			if (!ar[l])
			{
				ft_free_s_matrix(ar);
				return (NULL);
			}
			l++;
			flag = 0;
		}
		else if (!ft_split_is_word(s[i]) && flag == 0)
			flag = 1;
		i++;
	}
	ar[l] = NULL;
	return (ar);
} */

/* int	main()
{
	char	s[] = "ciao 	+sono petra ,come stai?";
	char	**a = ft_charset_split(s);
	int	i = 0;
	while (a[i])
	{
		printf("%s\n", a[i]);
		i++;
	}
	ft_free_s_matrix(a);
	return (0);
} */
