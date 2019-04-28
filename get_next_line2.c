#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char *strread(int fd)
{
    int ret;
    char *buf;
    //char buf[BUFF_SIZE + 1];
    char *resstring;
    char *buffer_free;

    resstring = ft_strnew(0);
    buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
    if ((ret = read(fd, buf, BUFF_SIZE)))
    {
        if (ret == -1)
            return (NULL);
        buf[ret] = '\0';
        buffer_free = resstring;
        resstring = ft_strjoin(resstring, buf);
        free(buffer_free);
    }
    return (resstring);
}

int get_next_line(const int fd, char **line)
{
    char static *strarr[4864];
    char *nptr;
    char *strnew;
    char *buffer_free;
    char *buffer_free2;


    if (fd < 0 || !line || fd > 4864 || BUFF_SIZE < 1)
        return (-1);
    if (!strarr[fd])
        strarr[fd] = ft_strnew(0);
    if (!strarr[fd])
        return (-1);
    while ((strnew = strread(fd)) && strnew[0] != '\0')
    {
        buffer_free = strarr[fd];
        strarr[fd] = ft_strjoin(strarr[fd], strnew);
        if (buffer_free)
            free(buffer_free);
        if ((nptr = strchr(strarr[fd], '\n')) != NULL)
        {
            *line = ft_strsub(strarr[fd], 0, nptr - strarr[fd]);
            nptr++;
            //free(strarr[fd]);
            buffer_free2 = strarr[fd];
            strarr[fd] = ft_strdup(nptr);
            if (buffer_free2)
                free(buffer_free2);
            printf("*line - %s", *line);
            return (1);
        }
    }
    if (strnew == NULL)
        return (-1);

    while (strarr[fd][0] != '\0')
    {
        if ((nptr = strchr(strarr[fd], '\n')) != NULL)
        {
            *line = ft_strsub(strarr[fd], 0, nptr - strarr[fd]);
            nptr++;
            buffer_free2 = strarr[fd];
            strarr[fd] = ft_strdup(nptr);
            if (buffer_free2)
                free(buffer_free2);
            printf("*line - %s", *line);
            return (1);
        }
        else
        {
            *line = ft_strdup(strarr[fd]);
            printf("*line - %s", *line);
            free(strarr[fd]);
            strarr[fd] = NULL;
            return (1);
        }
    }
    return (0);
}
