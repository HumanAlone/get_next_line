/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrost-g <bfrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 14:11:22 by bfrost-g          #+#    #+#             */
/*   Updated: 2019/02/14 19:21:58 by bfrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	intlen(int n)
{
	size_t	len;

	len = (n < 0) ? 2 : 1;
	while ((n / 10) != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char		*makestrzer(void)
{
	char *res;

	res = (char *)malloc(sizeof(char) + 1);
	res[0] = '0';
	res[1] = '\0';
	return (res);
}

char			*ft_itoa(int n)
{
	size_t			len;
	char			*string;
	char			*res;
	int				sign;
	unsigned int	num;

	sign = (n < 0) ? 1 : 0;
	num = (n < 0) ? (n * -1) : n;
	len = intlen(n);
	if ((string = (char *)malloc(sizeof(char) * (len + 1))) != NULL)
	{
		res = string;
		res[len] = '\0';
		res--;
		while (len && num)
		{
			res[len] = '0' + num % 10;
			num /= 10;
			len--;
		}
		if (sign)
			res[len] = '-';
		return ((n == 0) ? makestrzer() : string);
	}
	return (NULL);
}
