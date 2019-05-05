/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrost-g <bfrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 12:41:02 by bfrost-g          #+#    #+#             */
/*   Updated: 2018/12/28 11:45:34 by bfrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t needlen;

	if (!*needle)
		return (char *)haystack;
	needlen = ft_strlen(needle);
	while (*haystack && len-- >= needlen)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle, needlen) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
