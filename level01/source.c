#include <stdio.h>
#include <string.h>

int verify_user_name(char *user_name)
{
	const char *expected_user_name = "dat_will";
	return strcmp(user_name, expected_user_name) == 0;
}

int verify_user_pass(char *user_pass)
{
	const char *expected_user_pass = "your_expected_user_pass";
	return strcmp(user_pass, expected_user_pass) == 0;
}

int main()
{
	char user_name[256];
	char user_pass[100];

	memset(user_name, 0, 256); // Initialize user_name with 0s.
	memset(user_pass, 0, 100); // Initialize user_pass with 0s.

	puts("********* ADMIN LOGIN PROMPT *********");
	printf("Enter user name: ");
	fgets(user_name, 256, stdin);

	if (!verify_user_name(user_name))
	{
		puts("Invalid user name.\n");
		return 1;
	}

	puts("Enter password: ");
	fgets(user_pass, 100, stdin);

	if (!verify_user_pass(user_pass))
	{
		puts("Invalid password.\n");
		return 2;
	}

	puts("Login successful.\n");
	return 0;
}
