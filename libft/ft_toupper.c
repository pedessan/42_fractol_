/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:00:08 by pdessant          #+#    #+#             */
/*   Updated: 2024/11/26 17:01:05 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (!(c >= 'a' && c <= 'z'))
		return (c);
	return (c - 32);
}
/* 
int	main()
{
	int	a;
	int	b;

	a = toupper('a');
	b = ft_toupper('a');
	printf("%c\n%c\n", a, b);
	return (0);
}
 */
