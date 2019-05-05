/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrost-g <bfrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 12:18:39 by bfrost-g          #+#    #+#             */
/*   Updated: 2018/12/26 14:43:31 by bfrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *memory;
	char *begin;

	if ((memory = (char *)malloc(sizeof(char) * size)))
	{
		begin = memory;
		while (size)
		{
			*begin++ = 0;
			size--;
		}
		return (memory);
	}
	return (NULL);
}
