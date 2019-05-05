/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrost-g <bfrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:09:59 by bfrost-g          #+#    #+#             */
/*   Updated: 2019/02/21 20:42:35 by bfrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	char	*sub1;
	size_t	over;

	over = 0;
	if ((len == over - 1) || !s)
		return (NULL);
	if ((sub = (char *)malloc(sizeof(char) * (len + 1))) != NULL)
	{
		sub1 = sub;
		while (len)
		{
			*sub1++ = s[start++];
			len--;
		}
		*sub1 = '\0';
		return (sub);
	}
	return (NULL);
}
