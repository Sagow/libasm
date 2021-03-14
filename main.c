#include <stdio.h>
#include <string.h>

size_t ft_strlen(char *string);

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

int main()
{
	//main ft_strcmp
	int		ret;
	char	*str1 = "blabla";
	char	*str2 = "blb";

	printf("diff entre %s et %s = %d\n", str1, str2, ret);
	return (0);
}