#include <stdio.h>
#include "libft.h"

size_t ft_strlen(const char *s);

int main(void)
{
	char * s1 = "apple";
	char * s2 = "not human";

	printf("=== strlen result ===\n");
	printf(" = %zu \n", ft_strlen(""));
	printf("%s = %zu \n", s1, ft_strlen(s1));
	printf("%s = %zu \n", s2, ft_strlen(s2));
	printf("length = %zu \n", ft_strlen("length"));
	return 0;
}
