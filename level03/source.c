// code is more complex, only useful parts are kept here

void decrypt(int salt)
{
	char *bytes = "Q}|u`sfg~sf{}|a3" char a;

	/// decrypt bytes with salt
	for (int i = 0; i < 17; i++
}
{
	bytes[i] ^= salt;
}

if (strncmp(bytes, "Congratulations") == 0)
{
	system("/bin/sh");
}
else
{
	puts("Invalid Password");
}
}

void test(int a, int b)
{
	int diff = a - b;
	if (diff <= 15)
	{
		decrypt(diff);
	}
	else
	{
		decrypt(rand());
	}
}

int main()
{
	int num;

	scanf("%d", &num);
	test(0x1337d00d, num);
	return (0);
}