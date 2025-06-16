/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:59:51 by pdessant          #+#    #+#             */
/*   Updated: 2025/02/11 12:39:48 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "stdio.h"
# include "unistd.h"
# include "stdlib.h"
# include "fcntl.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct n_struct
{
	char	*buffer;
	char	*newline_pos;
	char	*line;
	int		bytes;
}	t_s;

int		get_strlen(const char *str);
int		len_keeper(char *keeper);
int		back_slash_n(char *s);

char	*get_strchr(const char *s, int c);
char	*get_strjoin(char *s1, char *s2);
char	*dup_after_n(char *keeper);
char	*sdup_to_n(char *s);
char	*get_next_line(int fd);

void	*get_calloc(size_t nmemb, size_t size);
void	*get_calloc(size_t nmemb, size_t size);
void	free_alloc(char **s);
void	buff_alloc(char **buff);

#endif
