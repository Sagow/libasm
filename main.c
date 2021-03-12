#include <stdio.h>
#include <string.h>

size_t ft_strlen(char *string);

int main()
{
	unsigned long int	ret;
	char *string = "Blabla";

	char *n = NULL;
	ret = 0;
	ret = ft_strlen(NULL);
	printf("%s compte %d caracteres\nb = %d\n", string, (int)ret, 'B');
	return (0);
}