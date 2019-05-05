/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrost-g <bfrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 12:54:47 by bfrost-g          #+#    #+#             */
/*   Updated: 2018/12/26 12:22:10 by bfrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char const *ptr;

	ptr = (unsigned char const *)s;
	while (n)
	{
		if (*ptr == (unsigned char)c)
			return ((void *)ptr);
		n--;
		ptr++;
	}
	return (NULL);
}
