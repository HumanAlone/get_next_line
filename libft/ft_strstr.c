/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrost-g <bfrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 12:56:56 by bfrost-g          #+#    #+#             */
/*   Updated: 2018/12/26 12:57:11 by bfrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char *h;
	const char *n;

	if (!*needle)
		return (char *)haystack;
	while (*haystack)
	{
		h = haystack;
		n = needle;
		while ((*h++ == *n++))
		{
			if (*n == '\0')
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
