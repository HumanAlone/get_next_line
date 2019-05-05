/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrost-g <bfrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:10:13 by bfrost-g          #+#    #+#             */
/*   Updated: 2019/02/21 20:46:09 by bfrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	len;
	char	*new_string;
	char	*new_string1;
	size_t	over;

	over = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	if (len == over - 1)
		return (NULL);
	if ((new_string = (char *)malloc(sizeof(char) * (len + 1))) != NULL)
	{
		new_string1 = new_string;
		while (len)
		{
			*new_string1 = f(*s);
			new_string1++;
			len--;
			s++;
		}
		*new_string1 = '\0';
		return (new_string);
	}
	return (NULL);
}
