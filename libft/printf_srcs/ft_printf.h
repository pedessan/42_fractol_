/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 14:16:45 by pdessant          #+#    #+#             */
/*   Updated: 2025/02/18 17:13:59 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//# include "libft/libft.h"
# include "../libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

void	ft_put_u_nbr(unsigned int u, int fd, int *ret);
void	put_p_printer(uintptr_t p, int fd, int *ret);
void	put_p(uintptr_t p, int fd, int *ret);
void	put_hexa_lower(unsigned int n, int fd, int *ret);
void	put_hexa_upper(unsigned int n, int fd, int *ret);
void	print_char_string(va_list ag, const char *f, int index, int *ret);
void	print_num(va_list ag, const char *f, int index, int *ret);
void	print_hexa(va_list ag, const char *f, int index, int *ret);
void	direct_print(const char *f, va_list	ag, int i, int *ret);
int		ft_printf(const char *f, ...);

#endif
