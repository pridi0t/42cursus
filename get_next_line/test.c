#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
	int fd;
	int result;
	char *line;

	result = 1;
	fd = open("a.txt", O_RDONLY);
	while (result != 0)
	{
		result = get_next_line(fd, &line);
		printf("%s\n", line);
	}
	return 0;
}
