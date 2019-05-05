/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrost-g <bfrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 12:54:50 by bfrost-g          #+#    #+#             */
/*   Updated: 2019/02/23 19:00:14 by bfrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *ptr1;
	const unsigned char *ptr2;
	int					diff;

	ptr1 = (unsigned char const *)s1;
	ptr2 = (unsigned char const *)s2;
	while (n--)
	{
		diff = *ptr1++ - *ptr2++;
		if (diff != 0)
			return (diff);
	}
	return (0);
}
