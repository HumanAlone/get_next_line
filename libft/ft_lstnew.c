/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrost-g <bfrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 18:21:11 by bfrost-g          #+#    #+#             */
/*   Updated: 2019/02/13 18:33:37 by bfrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *head;

	if ((head = (t_list *)malloc(sizeof(t_list))) != NULL)
	{
		if (content == NULL)
		{
			head->content = NULL;
			head->content_size = 0;
			head->next = NULL;
			return (head);
		}
		if ((head->content = (void *)malloc(content_size)) != NULL)
		{
			ft_memcpy(head->content, content, content_size);
			head->content_size = content_size;
			head->next = NULL;
			return (head);
		}
		free(head);
	}
	return (NULL);
}
