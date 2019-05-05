/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrost-g <bfrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 18:21:15 by bfrost-g          #+#    #+#             */
/*   Updated: 2019/02/14 17:10:46 by bfrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *head;
	t_list *temp;
	t_list *newlis;

	if (!lst || !f)
		return (NULL);
	temp = f(lst);
	if (!(newlis = ft_lstnew(temp->content, temp->content_size)))
		return (NULL);
	head = newlis;
	lst = lst->next;
	while (lst != NULL)
	{
		temp = f(lst);
		if (!(newlis->next = ft_lstnew(temp->content, temp->content_size)))
			return (NULL);
		lst = lst->next;
		newlis = newlis->next;
	}
	return (head);
}
