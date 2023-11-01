#include <stdio.h>

int main()
{
	printf("%s\n", "***********************************\n* 	     -Level00 -		  *\n ***********************************\n");
	printf("%s\n", "Password:");

	int input_value;
	scanf("%d", &input_value);

	if (input_value == 5276)
	{
		printf("Authenticated!\n");
		system("/bin/sh");
	}
	else
	{
		printf("Invalid Password!\n");
		return 1;
	}

	return 0;
}
