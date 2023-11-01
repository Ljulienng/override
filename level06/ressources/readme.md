This program has a call to /bin/sh but it is protected by a number of conditional jumps. We have two inputs: a login string and a serial number (unsigned int).

If the auth() function called by main returns 0, the /bin/sh call will occur. It appears that the auth() function creates a hash number based on the login string then compares it to our serial number and returns zero if the hashed login and Serial number are the same.

A few conditions for the login string to be valid:

Size superior to 5.
no characters inferior to 32 (ascii).
Using gdb we can enter a valid string, find out its value after being turned to a hash, then restart the program using that hash value as serial!

The program checks if it is already being traced and will close if it is (eg ltrace, gdb). Therefore if we want to use gdb we will have to avoid this check.

gdb level06
(gdb) b *0x080487b5 ; just before ptrace
(gdb) b *0x08048866 ; after the hashing loop
(gdb) r
-> Enter Login: jnguyen
-> Enter Serial: 0 ; not important

Breakpoint 1, 0x080487b5 in auth ()
(gdb) jump *0x080487ed
(gdb) p *(int*)($ebp-0x10) ; used to dereference and print the integer value stored at the memory location $ebp-0x10
$1 = 6233795

./level06
-> Enter Login: bonjour
-> Enter Serial: 6233795
Authenticated!
$ cat /home/users/level07/.pass

