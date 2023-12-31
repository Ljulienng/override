int main(int c, char **argv)
{
	pid_t ach;
	char s[32];
	int32_t v = 0;
	long wstatus = 0;

	ach = fork();
	memset(s, 0, 32);

	if (!ach)
	{
		prctl(PR_SET_PDEATHSIG, SIGHUP);
		ptrace(PTRACE_TRACEME, 0, 0, 0);
		puts("Give me some shellcode, k");
		gets(s);
		return 0;
	}

	while (1)
	{
		wait(wstatus);
		if (wstatus == 127 || 0xff & ((wstatus & 127) + 1) >> 1 <= 0)
		{
			puts("child is exiting...");
			return 0;
		}
		v = ptrace(PTRACE_PEEKUSER, ach, 44, 0);
		if (v == 11) // enter if syscall is made on child
		{
			puts("no exec() for you");
			kill(ach, 9);
			return 0;
		}
	}

	return 0;
}