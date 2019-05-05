/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrost-g <bfrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 19:04:24 by bfrost-g          #+#    #+#             */
/*   Updated: 2019/02/23 19:09:16 by bfrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstlen(t_list *lst)
{
	int		length;
	t_list	*begin;

	length = 0;
	if (lst)
	{
		begin = lst;
		while (begin != NULL)
		{
			length++;
			begin = begin->next;
		}
	}
	return (length);
}
