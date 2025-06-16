/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:57:22 by pdessant          #+#    #+#             */
/*   Updated: 2025/02/11 12:39:29 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

int	len_keeper(char *keeper)
{
	int	i;

	i = 0;
	while (keeper[i] && keeper[i] != '\n')
		i++;
	if (keeper[i] == '\n')
		i++;
	return (i);
}

char	*dup_after_n(char *keeper)
{
	int		i;
	int		j;
	char	*after_n;

	i = len_keeper(keeper);
	if (!keeper[i])
	{
		free(keeper);
		return (NULL);
	}
	j = 0;
	after_n = get_calloc(get_strlen(&keeper[i]) + 1, sizeof(char));
	if (!after_n)
		return (NULL);
	while (keeper[i + j])
	{
		after_n[j] = keeper[i + j];
		j++;
	}
	free(keeper);
	return (after_n);
	return (after_n);
}

char	*sdup_to_n(char *s)
{
	char	*c;
	size_t	len;
	int		i;

	len = get_strlen(s);
	i = 0;
	if (s[i] == '\0')
		return (NULL);
	c = get_calloc(len + 1, sizeof(char));
	if (!c)
		return (NULL);
	while (s[i] && s[i] != '\n')
	{
		c[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		c[i++] = '\n';
	c[i] = '\0';
	return (c);
}

void	buff_alloc(char **buff)
{
	if (BUFFER_SIZE <= 0)
		return ;
	*buff = get_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!*buff)
		return ;
}

char	*get_next_line(int fd)
{
	static char		*keeper[1024] = {NULL};
	t_s				get;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buff_alloc(&get.buffer);
	if (!get.buffer)
		return (NULL);
	get.bytes = 1;
	while (!(get_strchr(keeper[fd], '\n')) && get.bytes)
	{
		get.bytes = read(fd, get.buffer, BUFFER_SIZE);
		if (get.bytes < 0)
		{
			free_alloc(&keeper[fd]);
			free_alloc(&get.buffer);
			return (NULL);
		}
		get.buffer[get.bytes] = '\0';
		keeper[fd] = get_strjoin(keeper[fd], get.buffer);
	}
	free_alloc(&get.buffer);
	get.line = sdup_to_n(keeper[fd]);
	keeper[fd] = dup_after_n(keeper[fd]);
	return (get.line);
}
