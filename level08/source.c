void log_wrapper(void)
{
	// write log file
}

int main(int argc, char **argv)
{
	char buf[96];
	int fildes;
	int log_fp;
	int pass_fp;

	// canary stuff

	ptr = 255;
	fildes = -1;

	if (argc != 2)
	{
		printf("Usage: %s filename\n", argv[0]);
	}

	if ((log_fp = fopen("./backups/.log", "w")) == 0)
	{
		printf("ERROR: Failed to open %s\n", "./backups/.log");
		exit(1);
	}

	log_wrapper(log_fp, "Starting back up: ", argv[1]);

	if ((pass_fp = fopen(argv[1], "r")) == 0)
	{
		printf("ERROR: Failed to open %s\n", argv[1]);
		exit(1);
	}

	memcpy(buf, "./backups/", 10);
	strncat(buf, argv[1], 89);

	if ((fildes = open(buf, 193)) == 0)
	{
		printf("ERROR: Failed to open %s%s\n", "./backups/", argv[0]);
		exit(1);
	}

	while ((ptr = fgetc(pass_fp)) != -1)
		write(fildes, &ptr, 1);

	log_wrapper(log_fp, "Finished back up ", argv[1]);

	fclose(log_fp);
	fclose(pass_fp);

	// check canary

	return 1;
}