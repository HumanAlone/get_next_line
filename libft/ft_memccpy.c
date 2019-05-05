/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrost-g <bfrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 12:54:45 by bfrost-g          #+#    #+#             */
/*   Updated: 2018/12/26 12:23:42 by bfrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*ptr1;
	unsigned const char *ptr2;

	ptr1 = (unsigned char *)dest;
	ptr2 = (unsigned char *)src;
	while (n)
	{
		if ((unsigned char)*ptr2 == (unsigned char)c)
		{
			*ptr1++ = *ptr2;
			return (ptr1);
		}
		*ptr1++ = *ptr2++;
		--n;
	}
	return (NULL);
}
