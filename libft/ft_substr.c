/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:00:04 by pdessant          #+#    #+#             */
/*   Updated: 2024/11/26 13:08:43 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*sub;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

/* int	main()
{
	char	s[] = "Ciao sono Petra come stai?";
	unsigned int	n = 7;
	size_t	len = 20;
	char	*sub = ft_substr(s, n, len);
	printf("%s\n", sub);
	free(sub);
	return (0);
} */
/* char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int	i;
	int	s2_len;
	char	*sub;

	i = 0;
	if (!s)
		return (NULL);
	if (s + start)
		s = s + start;
	s2_len = ft_strlen(s);
	if (len > s2_len)
		sub = (char *)malloc((len - s2_len + 1) * sizeof(char));
	else if (len < s2_len)
		sub = (char *)malloc((s2_len - len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (i < len && *s)
	{
		sub[i] = *s;
		s++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
} */
