/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrost-g <bfrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 19:13:29 by bfrost-g          #+#    #+#             */
/*   Updated: 2019/02/23 19:18:48 by bfrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countwords(char const *s, char c)
{
	size_t			count;
	unsigned short	flag;

	count = (s) ? 1 : 0;
	while (*s == c)
		s++;
	while (*s)
	{
		flag = 0;
		if (*s == c)
		{
			while (*s == c)
				s++;
			flag = (*s == '\0') ? 0 : 1;
		}
		if (flag)
			count++;
		s++;
	}
	return (count);
}
