struct user
{
	char name[40];
	char msg[140];
	int len;
}

void
secret_backdoor()
{
	char string[128];

	fgets(string, 128, stdin);
	system(string);

	return;
}

void set_msg(char *arg1)
{
	char s[1024];

	bzero(&s, 16);
	puts("Message @Unix-Dude");
	printf(">>: ");
	fgets(&s, 1024, stdin);
	strncpy(arg1[180], s, arg1[180]);

	return;
}

void set_username(char *arg1)
{
	char s[128];

	bzero(&s, 16);
	puts(">: Enter your username");
	printf(">>: ");
	fgets(&s, 128, stdin);

	for (int i = 0; i <= 40 && s[i]; i++)
		arg1[0][i] = s[i];
	printf(">: Welcome, %s", arg1[0]);

	return;
}

void handle_msg(void)
{
	struct user var_c0h;

	var_c0h->name = {};
	var_c0h->len = 140;

	set_username(&var_c0h);
	set_msg(&var_c0h);
	puts(">: Msg sent!");

	return;
}

int main(int argc, char **argv, char **envp)
{
	puts("--------------------------------------------\n|   ~Welcome to l33t-m$n ~    v1337        |\n--------------------------------------------");
	handle_msg();

	return 0;
}