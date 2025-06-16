/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:25:27 by pdessant          #+#    #+#             */
/*   Updated: 2024/11/26 17:15:30 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
/* int	main()
{
	char	s[] = "ciao! come stai?";
	int	fd;
	fd = open("prova.txt", O_WRONLY);
	ft_putstr_fd(s, fd);
	close(fd);
	return (0);
} */
