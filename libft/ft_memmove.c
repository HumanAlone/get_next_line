/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrost-g <bfrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 12:54:55 by bfrost-g          #+#    #+#             */
/*   Updated: 2018/12/28 11:31:12 by bfrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*ptr1;
	char const	*ptr2;

	ptr1 = (char *)dest;
	ptr2 = (const char *)src;
	if (ptr2 >= ptr1)
	{
		while (n)
		{
			*ptr1++ = *ptr2++;
			--n;
		}
	}
	else
	{
		while (n)
		{
			--n;
			ptr1[n] = ptr2[n];
		}
	}
	return (dest);
}
