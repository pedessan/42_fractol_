/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:52:32 by pdessant          #+#    #+#             */
/*   Updated: 2024/11/26 17:23:27 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*c;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	c = (void *)malloc(nmemb * size);
	if (!c)
		return (NULL);
	ft_bzero(c, nmemb * size);
	return (c);
}
