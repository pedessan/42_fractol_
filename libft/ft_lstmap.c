/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdessant <pdessant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:34:24 by pdessant          #+#    #+#             */
/*   Updated: 2024/11/26 16:43:17 by pdessant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;

	if (!lst)
		return (NULL);
	new = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
			ft_lstdelone(node, del);
		else
			ft_lstadd_back(&new, node);
		lst = lst->next;
	}
	return (new);
}
