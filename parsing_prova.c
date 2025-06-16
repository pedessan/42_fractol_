/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_prova.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:52:56 by pdessant          #+#    #+#             */
/*   Updated: 2025/05/22 17:22:52 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_string(const char *s)
{
	int	i;
	int	point;

	i = 0;
	point = 0;
	if (!s || !*s)
		return (0);
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] == '.')
		{
			if (point || i == 0 || !s[i + 1])
				return (1);
			point = 1;
		}
		else if (s[i] < '0' || s[i] > '9')
			return (1);
		i++;
	}
	return (0);
}
