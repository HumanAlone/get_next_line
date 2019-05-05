/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrost-g <bfrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:10:05 by bfrost-g          #+#    #+#             */
/*   Updated: 2019/02/21 20:43:44 by bfrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	trimlen(char const *s)
{
	size_t		len;
	char const	*begin;
	char const	*end;

	len = ft_strlen(s);
	begin = s;
	end = s;
	while (*end)
		end++;
	end--;
	while (*begin == ' ' || *begin == '\t' || *begin == '\n')
	{
		len--;
		begin++;
	}
	if (len == 0)
		return (0);
	while (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\0')
	{
		len--;
		end--;
	}
	return (len);
}

char			*ft_strtrim(char const *s)
{
	char	*res;
	char	*res1;
	size_t	len;
	size_t	over;

	over = 0;
	if (!s)
		return (NULL);
	len = trimlen(s);
	if (len == over - 1)
		return (NULL);
	if ((res = (char *)malloc(sizeof(char) * (len + 1))) != NULL)
	{
		res1 = res;
		while (*s == ' ' || *s == '\t' || *s == '\n')
			s++;
		while (len)
		{
			*res1++ = *s++;
			len--;
		}
		*res1 = '\0';
		return (res);
	}
	return (NULL);
}
