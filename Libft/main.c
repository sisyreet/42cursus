#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char	move(unsigned int i, char c)
{
	printf("%d-%c", i, c);
	return (c);
}

size_t	ft_strlen(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize);
size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize);
int		ft_atoi(char *nptr);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *str, int ch);
char	*ft_strrchr(const char *str, int ch);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void 	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

int	main(void)
{
	// char	s2[] = " @#^$&!";
	// char	str[] = "Kawabanga!";
	// char	arr[] = "asd!";
	// char	dest[16];
	// char	*restrict src = "Mamma Mia!";
	// char	l = 'D';
	// char	u = 'd';
	// int		i = 117;

	// printf("ft_atoi - %d\n", ft_atoi("  	-123asd"));
	// printf("atoi - %d\n", atoi("  	-123asd"));
	// printf("- - - - - - - - - - - - - - - - -\n");
	// printf("ft_isalnum - %d\n", ft_isalnum(u));
	// printf("isalnum - %d\n", isalnum(u));
	// printf("- - - - - - - - - - - - - - - - -\n");
	// printf("ft_isalpha - %d\n", ft_isalpha(u));
	// printf("isalpha - %d\n", isalpha(u));
	// printf("- - - - - - - - - - - - - - - - -\n");
	// printf("ft_isascii - %d\n", ft_isascii(i));
	// printf("isascii - %d\n", isascii(i));
	// printf("- - - - - - - - - - - - - - - - -\n");
	// printf("ft_isdigit - %d\n", ft_isdigit(i));
	// printf("isdigit - %d\n", isdigit(i));
	// printf("- - - - - - - - - - - - - - - - -\n");
	// printf("ft_isprint - %d\n", ft_isprint(i));
	// printf("isprint - %d\n", isprint(i));
	// printf("- - - - - - - - - - - - - - - - -\n");
	// printf("ft_memset - %s\n", ft_memset(str, '_', 4));
	// printf("memset - %s\n", memset(str, '_', 4));
	// printf("- - - - - - - - - - - - - - - - -\n");
	// ft_bzero(str, 4);
	// printf("ft_bzero - %s\n", str);
	// bzero(str, 4);
	// printf("bzero - %s\n", str);
	// printf("- - - - - - - - - - - - - - - - -\n");
	// printf("ft_memmove - %s\n", ft_memmove(str, arr, 4));
	// printf("memmove - %s\n", memmove(str, arr, 4));
	// printf("- - - - - - - - - - - - - - - - -\n");
	// printf("ft_memcpy - %s\n", ft_memcpy(str, arr, 4));
	// printf("memcpy - %s\n", memcpy(str, arr, 4));
	// printf("- - - - - - - - - - - - - - - - -\n");
	// printf("ft_strlcpy - %zu - len of src. ", ft_strlcpy(dest, src, 12));
	// printf("%s - content of dest\n", dest);
	// printf("- - - - - - - - - - - - - - - - -\n");
	// printf("ft_strlen - %zu\n", ft_strlen(str));
	// printf("strlen - %zu\n", strlen(str));
	// printf("- - - - - - - - - - - - - - - - -\n");
	// printf("ft_tolower - %c\n", ft_tolower(l));
	// printf("tolower - %c\n", tolower(l));
	// printf("- - - - - - - - - - - - - - - - -\n");
	// printf("ft_toupper - %c\n", ft_toupper(u));
	// printf("toupper - %c\n", toupper(u));
	// printf("- - - - - - - - - - - - - - - - -\n");
	// printf("ft_strchr - %s\n", ft_strchr(str, '!'));
	// printf("strchr - %s\n", strchr(str, '!'));
	// printf("- - - - - - - - - - - - - - - - -\n");
	// printf("ft_strrchr - %s\n", ft_strrchr(str, 'b'));
	// printf("strrchr - %s\n", strrchr(str, 'b'));
	// printf("- - - - - - - - - - - - - - - - -\n");
	// printf("ft_strncmp - %d\n", ft_strncmp(s1, s2, 5));
	// printf("strncmp - %d\n", strncmp(s1, s2, 5));
	// printf("- - - - - - - - - - - - - - - - -\n");
	// printf("ft_memchr - %s\n", ft_memchr(s1, '4', 6));
	// printf("memchr - %s\n", memchr(s1, '4', 6));
	// printf("- - - - - - - - - - - - - - - - -\n");
	// printf("ft_memcmp - %d\n", ft_memcmp(s1, s2, 5));
	// printf("memcmp - %d\n", memcmp(s1, s2, 5));

	char	s1[] = "ANdjlkjaSNDpAISNd";
	char	s2[] = "jaS";
	printf("- - - - - - - - - - - - - - - - -\n");
	printf("ft_strnstr - %s\n", ft_strnstr(s1, s2, 15));
	printf("strnstr - %s\n", strnstr(s1, s2, 15));
	printf("- - - - - - - - - - - - - - - - -\n");
	// printf("- - - - - - - - - - - - - - - - -\n");
	// printf("ft_calloc - %s\n", ft_calloc(100, 4));
	// printf("calloc - %s\n", calloc(100, 4));
	// printf("- - - - - - - - - - - - - - - - -\n");
	// printf("ft_strdup - %s\n", ft_strdup(s1));
	// printf("strdup - %s\n", strdup(s1));
	// printf("- - - - - - - - - - - - - - - - -\n");
	// printf("ft_substr - %s\n", ft_substr(s1, 5, 6));
	// printf("- - - - - - - - - - - - - - - - -\n");
	// printf("ft_strjoin - %s\n", ft_strjoin(s1, s2));
	// printf("- - - - - - - - - - - - - - - - -\n");
	// printf("ft_strtrim - %s\n", ft_strtrim(s1, s2));
	// printf("- - - - - - - - - - - - - - - - -\n");
	// char **map = ft_split(s1, ' ');
	// int h = 0;
	// while (map[h])
	// {
	// 	printf("%s\n", map[h]);
	// 	h++;
	// }
	// printf("- - - - - - - - - - - - - - - - -\n");
	// printf("\n%s\n", ft_itoa (1354543));
	//char s1[] = "abc";
	// printf("%s\n", ft_strmapi(s1, move));
	// printf("- - - - - - - - - - - - - - - - -\n");
	// printf("ft_putchar_fd - ");
	// ft_putchar_fd('A', 1);
	// printf("\n");
	// printf("- - - - - - - - - - - - - - - - -\n");
	// printf("ft_putstr_fd - ");
	// ft_putstr_fd(s1, 1);
	// printf("\n");
	// printf("- - - - - - - - - - - - - - - - -\n");
	// printf("ft_putendl_fd - ");
	// ft_putendl_fd(s1, 1);
	// printf("\n");
	// printf("- - - - - - - - - - - - - - - - -\n");
	// printf("ft_putnbr_fd - ");
	// ft_putnbr_fd(123, 1);
	// printf("\n");
	// printf("- - - - - - - - - - - - - - - - -\n");
	return (0);
}


