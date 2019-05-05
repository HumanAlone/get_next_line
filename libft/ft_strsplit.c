/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrost-g <bfrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 17:36:47 by bfrost-g          #+#    #+#             */
/*   Updated: 2019/02/21 19:24:18 by bfrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**split(char const *s, char c, char **array)
{
	char	*res;
	char	*start;
	char	*end;
	size_t	i;

	i = 0;
	while (*s)
		if (*s != c && *s != '\0')
		{
			start = (char *)s;
			end = start;
			while (*end != c && *end != '\0')
				end++;
			res = ft_strsub(start, 0, end - start);
			array[i] = (char *)malloc(sizeof(char) * (ft_strlen(res) + 1));
			if (!res || !array[i])
				return (NULL);
			array[i] = res;
			i++;
			s = end;
		}
		else
			s++;
	array[i] = NULL;
	return (array);
}

static size_t	count_words(char const *s, char c)
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

char			**ft_strsplit(char const *s, char c)
{
	char	**array;
	size_t	count;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	if ((array = (char **)malloc(sizeof(char *) * (count + 1))) != NULL)
	{
		array = split(s, c, array);
		return (array);
	}
	return (NULL);
}
