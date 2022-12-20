/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:48:14 by croy              #+#    #+#             */
/*   Updated: 2022/11/18 16:48:15 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief allocates a memory area and returns a new node
 * The member variable ’content’ is initialised with value of param ’content’.
 * The variable ’next’ is initialized to NULL
 *
 * @param content content to create the node with
 * @return t_list* new node
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*dst;

	dst = malloc(sizeof(t_list));
	if (dst)
	{
		dst->content = content;
		dst->next = NULL;
	}
	return (dst);
}
