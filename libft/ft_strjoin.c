/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrost-g <bfrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:10:10 by bfrost-g          #+#    #+#             */
/*   Updated: 2019/02/21 20:45:40 by bfrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*res;
	char	*res1;
	size_t	over;

	over = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (len == over - 1)
		return (NULL);
	if ((res = (char *)malloc(sizeof(char) * (len + 1))) != NULL)
	{
		res1 = res;
		while (*s1)
			*res1++ = *s1++;
		while (*s2)
			*res1++ = *s2++;
		*res1 = '\0';
		return (res);
	}
	return (NULL);
}
