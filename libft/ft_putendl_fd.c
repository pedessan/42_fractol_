/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:31:26 by pdessant          #+#    #+#             */
/*   Updated: 2024/11/26 17:19:10 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write (fd, "\n", 1);
}
/* int	main()
{
	char	s[] = "ciao! come stai?";
	int	fd;
	fd = open("prova.txt", O_WRONLY);
	ft_putendl_fd(s, fd);
	close(fd);
	return (0);
} */
