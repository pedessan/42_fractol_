/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:09:05 by pdessant          #+#    #+#             */
/*   Updated: 2024/11/26 17:02:38 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (!(c >= 'A' && c <= 'Z'))
		return (c);
	return (c + 32);
}
/* 
int	main()
{
	int	a;
	int	b;

	a = tolower('A');
	b = ft_tolower('A');
	printf("%c\n%c\n", a, b);
	return (0);
} */
