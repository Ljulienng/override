int get_unum()
{
	int nb;

	fflush(STDOUT);
	scanf("%u", nb);
	clear_stdin();
	return (nb);
}

int read_number(char *buff)
{
	int index;

	printf("Index:");
	index = get_unum();
	printf("Number at data[%u] is %u", index, buff[index]);
	return (0);
}

int store_number(char *buff)
{
	int index;
	int number;

	printf("Number:");
	number = get_unum();
	printf("Index:");
	index = get_unum();
	if (index % 3 == 0 || number >> 24 == 183)
	{
		puts("Error index reserved");
		return 1;
	}
	buff[index] = number;
	return 0;
}

int main(int argc, char **argv, char **env)
{
	char buff[400];
	char cmd[20];
	int ret = 1;

	memset(buff, 0, 400);
	for (int i = 0; argv[i]; i++)
		memset(argv[i], 0, strlen(argv[i]));
	for (int i = 0; env[i]; i++)
		memset(env[i], 0, strlen(env[i]));
	puts("Welcome ...");
	while (1)
	{
		printf("Input command");
		fgets(cmd, 20, STDIN);
		if (strncmp(cmd, "store", 5) == 0)
			ret = store_number(buff);
		else if (strncmp(cmd, "read", 4) == 0)
			ret = read_number(buff);
		else if (strncmp(cmd, "quit", 4) == 0)
			return (0);
		if (ret == 0)
			printf("success");
		else
			printf("fail");
	}
}