/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrost-g <bfrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 12:40:46 by bfrost-g          #+#    #+#             */
/*   Updated: 2019/02/21 20:44:05 by bfrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*string;
	char	*begin;
	size_t	over;

	over = 0;
	if (size == over - 1)
		return (NULL);
	if ((string = (char *)malloc(sizeof(char) * (size + 1))))
	{
		begin = string;
		while (size)
		{
			*begin++ = '\0';
			size--;
		}
		*begin = '\0';
		return (string);
	}
	return (NULL);
}
