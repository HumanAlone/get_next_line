/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrost-g <bfrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 12:58:17 by bfrost-g          #+#    #+#             */
/*   Updated: 2018/12/26 15:00:44 by bfrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char *s;

	s = dest;
	while (*s++)
		;
	s--;
	while (*src && n)
	{
		*s++ = *src++;
		n--;
	}
	*s = '\0';
	return (dest);
}
