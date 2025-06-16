/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:58:31 by pdessant          #+#    #+#             */
/*   Updated: 2025/04/28 11:24:15 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	charset_checker(char c, char ch)
{
	if (ch == c)
		return (1);
	return (0);
}

void	portion(const char *str, char c, int counter, char *buff)
{
	int	flag;
	int	i;
	int	j;

	flag = 0;
	i = 0;
	j = 0;
	while (str[i] && counter > 0)
	{
		if (charset_checker(str[i], c) == 0)
		{
			if (counter == 1)
				buff[j++] = str[i];
			flag = 1;
		}
		else if (flag == 1)
		{
			counter--;
			flag = 0;
		}
		i++;
	}
	buff[j] = '\0';
}

int	ft_str_counter(const char *str, char c)
{
	int	counter;
	int	flag;
	int	i;

	counter = 0;
	flag = 0;
	i = 0;
	while (str[i])
	{
		if (charset_checker(str[i], c) == 0 && flag == 0)
		{
			counter++;
			flag = 1;
		}
		else if (charset_checker(str[i], c) == 1)
			flag = 0;
		i++;
	}
	return (counter);
}

void	free_all(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

char	**ft_split(char const *s, char c)
{
	char	buff[500];
	char	**ar;
	int		num_words;
	int		i;
	int		counter;

	i = 0;
	num_words = ft_str_counter(s, c);
	ar = (char **)malloc((num_words + 1) * sizeof(char *));
	if (!ar)
		return (NULL);
	counter = 1;
	while (i < num_words)
	{
		portion(s, c, counter++, buff);
		ar[i] = ft_strdup(buff);
		if (!(ar[i]))
		{
			ft_free_s_matrix(ar);
			return (NULL);
		}
		i++;
	}
	ar[num_words] = NULL;
	return (ar);
}

/* int	main()
{
	char	s[] = "\0ciao\0sono petra\0come stai?";
	char	**a = ft_split(s, '\0');
	int	i = 0;
	while (a[i])
	{
		printf("%s\n", a[i]);
		i++;
	}
	free_all(a);
	return (0);
} */
