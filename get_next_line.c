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

char *ft_strjoin(char const *s1, char const *s2)
{
    size_t len;
    char *res;
    char *res1;
    size_t over;

    over = 0;
    if (!s1 || !s2)
        return (NULL);
    len = strlen(s1) + strlen(s2);
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

int get_next_line(const int fd, char **line)
{
    char static *hueta[4096];
    char *start;
    char *strnew;
    int len;

    len = 0;
    if (fd < 0 || !line || fd > 4864)
        return (-1);
    if (!hueta[fd])
        hueta[fd] = strread(fd);
    start = hueta[fd];
    while (*hueta[fd])
    {
        len++;
        hueta[fd]++;
        if (*hueta[fd] == '\n')
        {
            *line = ft_strsub(start, 0, len);
            hueta[fd]++;
            strnew = strdup(hueta[fd]);
            free(start); // Тут ломается
            hueta[fd] = strdup(strnew);
            //printf("%s\n", *line);
            return (1);
        }
    }
    //printf("%s", *line);
    return (0);
}


int main(void)
{
    int fd;
    int fd1;
    int ret;
    char buf[BUFF_SIZE + 1];
    char **line = (char **) malloc(sizeof(char) * 32); // Need static?
    char **line1 = (char **) malloc(sizeof(char) * 32);

    fd = open("C:\\Users\\HumanAlone\\CLionProjects\\PrataStephen\\text.txt", O_RDONLY);
    fd1 = open("C:\\Users\\HumanAlone\\CLionProjects\\PrataStephen\\text1.txt", O_RDONLY);

    printf("%d text\n", get_next_line(fd, line));
    printf("%d text\n", get_next_line(fd, line));
    printf("%d text1\n", get_next_line(fd1, line1));
    printf("%d text\n", get_next_line(fd, line));
    printf("%d text1\n", get_next_line(fd1, line1));
    printf("%d text1\n", get_next_line(fd1, line1));
    printf("%d text1\n", get_next_line(fd1, line1));
    printf("%d text1\n", get_next_line(fd1, line1));
    printf("%d text\n", get_next_line(fd, line));
    printf("%d text1\n", get_next_line(fd1, line1));
    printf("%d text\n", get_next_line(fd, line));
    printf("%d text1\n", get_next_line(fd1, line1));

    return (0);
}


//int main(void)
//{
//    int fd;
//    int ret;
//    char buf[BUFF_SIZE + 1];
//    char static **line; // Need static?
//    char *resstring = NULL;
//
//    fd = open("C:\\Users\\HumanAlone\\CLionProjects\\PrataStephen\\text.txt", O_RDONLY);
//    while ((ret = read(fd, buf, BUFF_SIZE)))
//    {
//        buf[ret] = '\0';
//        if (!resstring)
//        {
//            resstring = (char *) malloc(sizeof(char) * (ret + 1));
//            strcpy(resstring, buf);
//        }
//        else
//        {
//            resstring = ft_strjoin(resstring, buf);
//        }
//
//    }
//    printf("%s", resstring);
//    line = ft_strsplit(resstring, '\n');
//    while (*line != NULL)
//    {
//        printf("Tuta!");
//        printf("%s", *line);
//        line++;
//    }
//    return (0);
//}