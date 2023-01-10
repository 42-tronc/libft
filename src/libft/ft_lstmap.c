/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:36:03 by croy              #+#    #+#             */
/*   Updated: 2023/01/10 10:13:11 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

/**
 * @brief iterates the list 'lst' and applies 'f' on each node
 * get the result of 'f' in a new created list 'dst' being returned.
 * If a malloc fails or if the node can't get the content, delete the content of
 * the node with the 'del' function and free it.
 *
 * @param lst list to iterate and apply 'f' on
 * @param f function to apply on each node of 'lst'
 * @param del function to delete the content of a node
 * @return t_list* new list with the result of 'f' on each node of 'lst'
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dst;
	t_list	*node;

	if (!lst || !f || !del)
		return (NULL);
	dst = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&dst, del);
			return (NULL);
		}
		ft_lstadd_back(&dst, node);
		lst = lst->next;
	}
	return (dst);
}
