#include <ctype.h>

int main(void)
{
	int i = 0;
	char buf[100];

	fgets(&buf, 100, stdin);
	for (; *p; ++p)
		*p = tolower(*p); // lowercase

	printf(buf);
	exit(0);
}