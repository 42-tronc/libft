#include "get_next_line.h"

int main(void)
{
	int fd = open("empty.txt", O_RDONLY);

	//char *dst = gnl_str_join("lol", " loli");
	printf("\n1: '%s'", get_next_line(fd));
	printf("\n2: '%s'", get_next_line(fd));
	return (0);
}
