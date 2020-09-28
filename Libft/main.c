#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "libft.h"

size_t ft_strlen(const char *s);

int main(void)
{
	char * s1 = "apple";
	char * s2 = "not human";
	char c = 'c';

	printf("========== strlen ==========\n");
	printf("1. ft_strlen ----------\n");
	printf(" = %zu \n", strlen(""));
	printf("%s = %zu \n", s1, strlen(s1));
	printf("%s = %zu \n", s2, strlen(s2));
	printf("length = %zu \n", strlen("length"));

	printf("2. ft_strlen ----------\n");
	printf(" = %zu \n", ft_strlen(""));
	printf("%s = %zu \n", s1, ft_strlen(s1));
	printf("%s = %zu \n", s2, ft_strlen(s2));
	printf("length = %zu \n", ft_strlen("length"));

	printf("========== isalpha ==========\n");
	printf("1. isalpha ----------\n");
	printf("a = %d \n", isalpha('a'));
	printf("A = %d \n", isalpha('A'));
	printf("z = %d \n", isalpha('z'));
	printf("1 = %d \n", isalpha('1'));
	printf("%c = %d \n", 'c', isalpha(c));

	printf("2. ft_isalpha ----------\n");
	printf("a = %d \n", ft_isalpha('a'));
	printf("A = %d \n", ft_isalpha('A'));
	printf("z = %d \n", ft_isalpha('z'));
	printf("1 = %d \n", ft_isalpha('1'));
	printf("%c = %d \n", 'c', ft_isalpha(c));

	return 0;
}
