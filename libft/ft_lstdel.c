/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrost-g <bfrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 18:21:22 by bfrost-g          #+#    #+#             */
/*   Updated: 2019/02/14 17:08:09 by bfrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	if (alst && del)
	{
		while ((*alst) != NULL)
		{
			del((**alst).content, (**alst).content_size);
			temp = (*alst)->next;
			free(*alst);
			*alst = temp;
		}
	}
}
