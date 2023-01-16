/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: croy <croy@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:48:14 by croy              #+#    #+#             */
/*   Updated: 2023/01/16 17:21:25 by croy             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/libft.h"

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
	if (!dst)
		return (NULL);
	if (dst)
	{
		dst->content = content;
		dst->next = NULL;
	}
	return (dst);
}
