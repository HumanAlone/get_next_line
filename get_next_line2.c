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

char *strread(const int fd)
{
    int ret;
    char *buf;
    char *resstring;
    char *buffer_free;

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

int static fdread(const int fd, char *strarr[], char *strnew, char **line)
{
    char *nptr;
    char *buffer_free;

    while (((strnew = strread(fd)) && strnew[0] != '\0') || strarr[fd][0] != '\0')
    {
        buffer_free = strarr[fd];
        strarr[fd] = ft_strjoin(strarr[fd], strnew);
        free(buffer_free);
        free(strnew);
        if ((nptr = strchr(strarr[fd], '\n')) != NULL)
        {
            *line = ft_strsub(strarr[fd], 0, nptr++ - strarr[fd]);
            buffer_free = strarr[fd];
            strarr[fd] = ft_strdup(nptr);
            free(buffer_free);
            return (1);
        }
        if (strarr[fd][0] != '\0' && strnew[0] == '\0')
        {
            *line = ft_strdup(strarr[fd]);
            free(strarr[fd]);
            strarr[fd] = NULL;
            return (1);
        }
    }
    return ((strnew == NULL) ? -1 : 0);
}

int get_next_line(const int fd, char **line)
{
    char static *strarr[4864];
    char *strnew;
    int res;

    strnew = NULL;
    if (fd < 0 || !line || fd > 4864 || BUFF_SIZE < 1)
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
