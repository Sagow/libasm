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
char	*ft_strdup(const char *s);

int	main(void)
{
	char	*string1 = "Je suis la string 1";
	char	*string2 = "Et moi la string 2";
	char	*string3;
	char	*string4;
	char	*string5 = NULL;
	char	*string6 = NULL;
	int		fd1 = open("test1.txt", O_WRONLY | O_CREAT | O_APPEND);
	int		fd2 = open("test2.txt", O_WRONLY | O_CREAT | O_APPEND);
	int		fd3 = open("Makefile", O_RDONLY);
	int		fd4 = open("Makefile", O_RDONLY);
	char	buffer1[6];
	char	buffer2[6];

	printf("ft_strlen :\n");
	printf("La vraie  : |%s| fait %ld caracteres\n", string1, strlen(string1));
	printf("La mienne : |%s| fait %ld caracteres\n", string1, ft_strlen(string1));
	//envoyer NULL fait segfault l'originale, donc a tester separement

	printf("\nft_strcmp :\n");
	printf("La vraie  : |%s| et |%s| font %d\n", string1, string2, strcmp(string1, string2));
	printf("La mienne : |%s| et |%s| font %d\n", string1, string2, ft_strcmp(string1, string2));
	printf("La vraie  : |%s| et |%s| font %d\n", string1, string1, strcmp(string1, string1));
	printf("La mienne : |%s| et |%s| font %d\n", string1, string1, ft_strcmp(string1, string1));
	printf("La vraie  : |%s| et |%s| font %d\n", string2, string1, strcmp(string2, string1));
	printf("La mienne : |%s| et |%s| font %d\n", string2, string1, ft_strcmp(string2, string1));
	//envoyer un seul NULL fait segfault l'original
	//printf("La vraie  : |%s| et |%s| font %d\n", NULL, string2, strcmp(NULL, string2));
	//printf("La mienne : |%s| et |%s| font %d\n", NULL, string2, ft_strcmp(NULL, string2));
	//printf("La vraie  : |%s| et |%s| font %d\n", string1, NULL, strcmp(string1, NULL));
	//printf("La mienne : |%s| et |%s| font %d\n", string1, NULL, ft_strcmp(string1, NULL));
	printf("La vraie  : |%s| et |%s| font %d\n", NULL, NULL, strcmp(NULL, NULL));
	printf("La mienne : |%s| et |%s| font %d\n", NULL, NULL, ft_strcmp(NULL, NULL));

	printf("\nft_strcpy :\n");
	string3 = malloc(sizeof(char) * (strlen(string1) + 1));
	string4 = malloc(sizeof(char) * (strlen(string1) + 1));
	strcpy(string3, string1);
	ft_strcpy(string4, string1);
	printf("(malloc de pile la bonne taille) La vraie  : |%s|\n", string3);
	printf("(malloc de pile la bonne taille) La mienne : |%s|\n", string4);
	free(string3);
	free(string4);
	string3 = malloc(sizeof(char) * (strlen(string1) - 5));
	string4 = malloc(sizeof(char) * (strlen(string1) - 5));
	strcpy(string3, string1);
	ft_strcpy(string4, string1);
	printf("(malloc trop petit) La vraie  : |%s|\n", string3);
	printf("(malloc trop petit) La mienne : |%s|\n", string4);
	free(string3);
	free(string4);
	string3 = malloc(sizeof(char) * (strlen(string1) + 10));
	string4 = malloc(sizeof(char) * (strlen(string1) + 10));
	strcpy(string3, string1);
	ft_strcpy(string4, string1);
	printf("(malloc trop grand) La vraie  : |%s|\n", string3);
	printf("(malloc trop grand) La mienne : |%s|\n", string4);
	free(string3);
	free(string4);
	string3 = malloc(sizeof(char) * (strlen(string1) + 1));
	string4 = malloc(sizeof(char) * (strlen(string1) + 1));
	//copier NULL fait segfault l'original
	//strcpy(string3, NULL);
	//ft_strcpy(string4, NULL);
	//printf("La vraie  : |%s|\n", string3);
	//printf("La mienne : |%s|\n", string4);
	free(string3);
	free(string4);

	printf("\nft_strdup :\n");
	string3 = strdup(string1);
	string4 = ft_strdup(string1);
	printf("La vraie  : |%s|\n", string3);
	printf("La mienne : |%s|\n", string4);
	free(string3);
	free(string4);
	//NULL fait segfault l'original
	//string3 = strdup(NULL);
	//string4 = ft_strdup(NULL);
	//printf("La vraie  : |%s|\n", string3);
	//printf("La mienne : |%s|\n", string4);
	//free(string3);
	//free(string4);
	
	printf("\nft_write :\n");
	printf("write a renvoye    : %ld\n", write(fd1, "pouet\n", 6));
	printf("ft_write a renvoye : %ld\n", ft_write(fd2, "pouet\n", 6));
	printf("write a renvoye    : %ld\n", write(fd1, "pouet\n", 3));
	printf("ft_write a renvoye : %ld\n", ft_write(fd2, "pouet\n", 3));
	printf("write a renvoye    : %ld\n", write(fd1, "pouet\n", 16));
	printf("ft_write a renvoye : %ld\n", ft_write(fd2, "pouet\n", 16));
	printf("write a renvoye    : %ld\n", write(fd1, NULL, 6));
	printf("ft_write a renvoye : %ld\n", ft_write(fd2, NULL, 6));
	printf("write a renvoye    : %ld\n", write(fd1, "pouet\n", 0));
	printf("ft_write a renvoye : %ld\n", ft_write(fd2, "pouet\n", 0));
	close(fd1);
	close(fd2);

	printf("\nft_read :\n");
	buffer1[5] = '\0';
	buffer2[5] = '\0';
	printf("read a renvoye    : %ld |%s|\n", read(fd3, buffer1, 5), buffer1);
	printf("ft_read a renvoye : %ld |%s|\n", ft_read(fd4, buffer2, 5), buffer2);
	buffer1[5] = '\0';
	buffer2[5] = '\0';
	printf("read a renvoye    : %ld |%s|\n", read(fd3, buffer1, 2), buffer1);
	printf("ft_read a renvoye : %ld |%s|\n", ft_read(fd4, buffer2, 2), buffer2);
	buffer1[5] = '\0';
	buffer2[5] = '\0';
	printf("read a renvoye    : %ld |%s|\n", read(fd3, buffer1, 8), buffer1);
	printf("ft_read a renvoye : %ld |%s|\n", ft_read(fd4, buffer2, 8), buffer2);
	buffer1[5] = '\0';
	buffer2[5] = '\0';
	printf("read a renvoye    : %ld |%s|\n", read(fd3, buffer1, 0), buffer1);
	printf("ft_read a renvoye : %ld |%s|\n", ft_read(fd4, buffer2, 0), buffer2);
	close(fd3);
	close(fd4);
	printf("\n\n FINIIIII (le stack smashing, c'est les lignes 124 et 125, avec une size trop grande)\n\n");
	return (0);
}
