#include <stdio.h>
#include <string.h>

size_t ft_strlen(char *string);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dest, const char *src);

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