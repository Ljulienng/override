This binary takes the file at path specified in av[1] and makes a backup copy. To do this it uses two fopen() calls and one open() call. If any of the calls fail the program will exit.

first fopen(): opens /backups/.log we can create our own in /tmp/

second fopen(): opens file specified in av[1] path

open(): creates a file at ./backups/ + av[1] path copies contents from second fopen into it

If we create in /tmp/ a fake directory architecture that matches the path to /level09/.pass, the program will open it, and backup its contents.