/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrost-g <bfrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 15:10:15 by bfrost-g          #+#    #+#             */
/*   Updated: 2019/02/21 21:04:39 by bfrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			len;
	char			*new_string;
	char			*new_string1;
	size_t			over;

	over = 0;
	if (!s || !f || (len = ft_strlen(s)) == over - 1)
		return (NULL);
	if ((new_string = (char *)malloc(sizeof(char) * (len + 1))) != NULL)
	{
		new_string1 = new_string;
		i = 0;
		while (len)
		{
			*new_string1 = f(i++, *s);
			new_string1++;
			len--;
			s++;
		}
		*new_string1 = '\0';
		return (new_string);
	}
	return (NULL);
}
