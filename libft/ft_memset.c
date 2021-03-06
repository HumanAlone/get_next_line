/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrost-g <bfrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 12:54:57 by bfrost-g          #+#    #+#             */
/*   Updated: 2018/12/26 12:28:51 by bfrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char *p;

	p = (char *)s;
	while (n)
	{
		*p++ = (char)c;
		--n;
	}
	return (s);
}
