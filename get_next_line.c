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

#define BUFF_SIZE 32

char	*ft_strcpy(char *dst, const char *src)
{
    int i;

    i = 0;
    while ((dst[i] = src[i]) != '\0')
    {
        i++;
    }
    return (dst);
}

size_t	ft_strlen(const char *s)
{
    size_t len;

    len = 0;
    while (*s++)
        len++;
    return (len);
}

char  *ft_strjoin(char const *s1, char const *s2)
{
    size_t len;
    char *res;
    char *res1;
    size_t over;

    over = 0;
    if (!s1 || !s2)
        return (NULL);
    len = ft_strlen(s1) + ft_strlen(s2);
    if (len == over - 1)
        return (NULL);
    if ((res = (char *) malloc(sizeof(char) * (len + 1))) != NULL)
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


char *ft_strsub(char const *s, unsigned int start, size_t len)
{
    char *sub;
    char *sub1;
    size_t over;

    over = 0;
    if ((len == over - 1) || !s)
        return (NULL);
    if ((sub = (char *) malloc(sizeof(char) * (len + 1))) != NULL)
    {
        sub1 = sub;
        while (len)
        {
            *sub1++ = s[start++];
            len--;
        }
        *sub1 = '\0';
        return (sub);
    }
    return (NULL);
}

char	*ft_strdup(const char *src)
{
    char	*dest;
    int		length;
    int		i;

    length = 0;
    i = 0;
    while (src[length] != '\0')
        length++;
    if ((dest = (char*)malloc(sizeof(char) * (length + 1))) != NULL)
    {
        while (src[i] != '\0')
        {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }
    return (dest);
}

char *strread(int fd)
{
    int ret;
    char buf[BUFF_SIZE + 1];
    char *resstring = NULL;
    char *buffer_free;
    while ((ret = read(fd, buf, BUFF_SIZE)))
    {
        if (ret == -1)
            return (NULL);
        buf[ret] = '\0';
        if (!resstring)
        {
            resstring = (char *)malloc(sizeof(char) * (ret + 1));
            ft_strcpy(resstring, buf);
        }
        else
        {
            buffer_free = resstring;
            resstring = ft_strjoin(resstring, buf);
            free(buffer_free);
        }
    }
    return (resstring);
}

static size_t	trimlen(char const *s)
{
    size_t		len;
    char const	*end;

    len = ft_strlen(s);
    end = s;
    while (*end)
        end++;
    end--;
    if (len == 0)
        return (0);
    while (*end == '\n' || *end == '\0')
    {
        len--;
        end--;
    }
    return (len);
}

char			*ft_rstrtrim(char const *s)
{
    char	*res;
    char	*res1;
    size_t	len;
    size_t	over;

    over = 0;
    if (!s)
        return (NULL);
    len = trimlen(s);
    if (len == over - 2)
        return (NULL);
    if ((res = (char *)malloc(sizeof(char) * (len + 2))) != NULL)
    {
        res1 = res;
//        while (*s == ' ' || *s == '\t' || *s == '\n')
//            s++;
        while (len)
        {
            *res1++ = *s++;
            len--;
        }
        *res1 = '\n';
        res1++;
        *res1 = '\0';
        return (res);
    }
    return (NULL);
}

int get_next_line(const int fd, char **line)
{
    char static *strarr[4864];
    char *start;
    char *strnew;
    int len;

    len = 0;
    if (fd < 0 || !line || fd > 4864)
        return (-1);
    if (!strarr[fd])
    {
        strarr[fd] = ft_rstrtrim(strread(fd));
        //printf("%s\n\n", strarr[fd]);
        if (!strarr[fd])
            return (-1);
    }
    //printf("%s\n", strarr[fd]);
    start = strarr[fd];
    while ((*strarr[fd] || len) )
    {
        if ((*strarr[fd] == '\n' || *strarr[fd] == '\0'))
        {
            *line = ft_strsub(start, 0, len);
            strarr[fd]++;
            strnew = ft_strdup(strarr[fd]);
            free(start);
            strarr[fd] = ft_strdup(strnew);

            printf("%s\n", *line);
            return (1);
        }
        len++;
        strarr[fd]++;
    }
    return (0);
}
