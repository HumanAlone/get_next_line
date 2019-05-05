/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrost-g <bfrost-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:58:02 by bfrost-g          #+#    #+#             */
/*   Updated: 2019/05/04 20:36:17 by bfrost-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*strread(const int fd)
{
	int			ret;
	char		*buf;
	char		*resstring;
	char		*buffer_free;

	resstring = ft_strnew(0);
	if ((buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))) != NULL)
	{
		if ((ret = read(fd, buf, BUFF_SIZE)))
		{
			if (ret == -1)
				return (NULL);
			buf[ret] = '\0';
			buffer_free = resstring;
			resstring = ft_strjoin(resstring, buf);
			free(buffer_free);
		}
		free(buf);
	}
	return (resstring);
}

static void		strfree(const int fd, char *buf, char *strarr[], char *nptr)
{
	buf = strarr[fd];
	strarr[fd] = ft_strdup(nptr);
	free(buf);
}

static int		fdread(const int fd, char *strarr[], char *new, char **line)
{
	char		*nptr;
	char		*buffer_free;

	while (((new = strread(fd)) && new[0] != '\0') || strarr[fd][0] != '\0')
	{
		buffer_free = strarr[fd];
		strarr[fd] = ft_strjoin(strarr[fd], new);
		free(buffer_free);
		free(new);
		if ((nptr = ft_strchr(strarr[fd], '\n')) != NULL)
		{
			*line = ft_strsub(strarr[fd], 0, nptr++ - strarr[fd]);
			strfree(fd, buffer_free, strarr, nptr);
			return (1);
		}
		if (strarr[fd][0] != '\0' && new[0] == '\0')
		{
			*line = ft_strdup(strarr[fd]);
			free(strarr[fd]);
			strarr[fd] = NULL;
			return (1);
		}
	}
	return ((new == NULL) ? -1 : 0);
}

int				get_next_line(const int fd, char **line)
{
	char static	*strarr[7168];
	char		*strnew;
	int			res;

	strnew = NULL;
	if (fd < 0 || !line || fd > 7168 || BUFF_SIZE < 1)
		return (-1);
	if (!strarr[fd])
		strarr[fd] = ft_strnew(0);
	if (!strarr[fd])
		return (-1);
	res = fdread(fd, strarr, strnew, line);
	if (res == 1)
		return (1);
	else if (res == -1)
		return (-1);
	return (0);
}
