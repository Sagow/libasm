#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

size_t ft_strlen(char *string);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dest, const char *src);
ssize_t	ft_read(int fd, void *buffer, size_t size);
ssize_t ft_write(int fd, void *buffer, size_t size);

/*
int main()
{
	//main ft_strlen
	unsigned long int	ret;
	char *string = "Blabla";

	char *n = NULL;
	ret = 0;
	ret = ft_strlen(NULL);
	printf("%s compte %d caracteres\nb = %d\n", string, (int)ret, 'B');
	return (0);
}
*/
/*
int main()
{
	//main ft_strcmp
	char	*str1 = "affff";
	char	*str2 = "gij";
	int		ret = ft_strcmp(str1, str2);

	printf("diff entre %s et %s = %d\n", str1, str2, ret);
	printf("le vrai : %d\n", strcmp(str1, str2));
	return (0);
}
*/
/*
int	main()
{
	//main ft_strcpy
	char	*str1 = "";
	char	str2[2];

	printf("original !%s!\n", str1);
	printf("pointeur !%s!\n", ft_strcpy(str2, str1));
	printf("copie    !%s!\n", str2);
	return (0);
}
*/
/*
int main(void)
{
	int		fd = open("test.txt", O_RDONLY);
	int		fd2 = open("test.txt", O_RDONLY);
	char	buffer[11];
	char	buffer2[11];

	buffer[10] = '\0';
	buffer2[10] = '\0';
	fd = -1;
	fd2 = -1;
	printf("la vraie  : fd = %d, read rend %ld et lu !%s!\n",fd, read(fd, buffer, 10), buffer);
	printf("la mienne : fd = %d, read rend %ld et lu !%s!\n",fd, ft_read(fd2, buffer2, 10), buffer);

}
*/
/*
int main(void)
{
	int		fd = open("test1.txt", O_WRONLY);
	int		fd2 = open("test2.txt", O_WRONLY);
	size_t	size = 15;

	fd = -1;
	fd2 = -1;
	printf("la vraie  : fd = %d, read rend %ld\n",fd, write(fd, "pouet", size));
	printf("la mienne : fd = %d, read rend %ld\n",fd2, ft_write(fd2, "pouet", size));

}
*/
