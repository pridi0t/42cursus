#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "libft.h"

int main(void)
{
	char * s1 = "apple";
	char * s2 = "not human";
	char c1 = 'c';
	char c2 = '0';
	int n = 0;

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
	printf("%c = %d \n", 'c', isalpha(c1));

	printf("2. ft_isalpha ----------\n");
	printf("a = %d \n", ft_isalpha('a'));
	printf("A = %d \n", ft_isalpha('A'));
	printf("z = %d \n", ft_isalpha('z'));
	printf("1 = %d \n", ft_isalpha('1'));
	printf("%c = %d \n", 'c', ft_isalpha(c1));

	printf("========== ft_isdigit ==========\n");
	printf("1. isdigit ----------\n");
	printf("'0' = %d \n", isdigit(c2));
	printf("'0'= %d \n", isdigit('0'));
	printf("0 = %d \n", isdigit(0));
	
	printf("2. ft_isdigit ----------\n");
	printf("'0' = %d \n", ft_isdigit(c2));
	printf("'0' = %d \n", ft_isdigit('0'));
	printf("0 = %d \n", ft_isdigit(0));

	printf("========== ft_isalnum ==========\n");
	printf("1. isalnum ----------\n");
	while (n <= 128)
	{
		printf("%c = %d\n", n, isalnum(n));
		n++;
	}

	n = 0;
	printf("2. ft_isalnum ----------\n");
	while (n <= 128)
	{
		printf("%c = %d\n", n, ft_isalnum(n));
		n++;
	}

	n = -1;
	printf("========== ft_isascii ==========\n");
	printf("1. isascii ----------\n");
	while (n <= 129)
	{
		printf("%c = %d\n", n, isascii(n));
		n++;
	}

	n = -1;
	printf("2. ft_isascii ----------\n");
	while (n <= 129)
	{
		printf("%c = %d\n", n, ft_isascii(n));
		n++;
	}

	n = 31;
	printf("========== ft_isprint ==========\n");
	printf("1. isprint ----------\n");
	while (n <= 126)
	{
		printf("%c = %d\n", n, isprint(n));
		n++;
	}

	n = 31;
	printf("2. ft_isprint ----------\n");
	while (n <= 126)
	{
		printf("%c = %d\n", n, ft_isprint(n));
		n++;
	}
	return 0;
}
