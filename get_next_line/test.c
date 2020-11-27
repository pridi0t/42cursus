#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int fd;
	int result;
	char *line;

	result = 1;
	fd = open("b.txt", O_RDONLY);
	while (result > 0)
	{
		result = get_next_line(fd, &line);
		printf("result = %d\n",result);
		printf("%s\n", line);
		free(line);
	}
	return 0;
}
