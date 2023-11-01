This program takes a username and a password.
After reverse engineering it, we can see that it uses fgets to get the input.
Also the .pass file is stored but not being used in any cases.

The breach comes from a non secured printf function that is used to print the username. (printf(username);)
We can use this to leak the stack and find the address of the .pass file.

The buffer we want to print is at RBP - 0xa0 ; 160 The size of the stack frame is 0x120 ; 288

Parameter offset to reach our buffer = (288 - 160) / 8 + 1 = 22

The length of the flag string is 40 so we will want to print 5 \* 8.

python -c 'print "%22$p%23$p%24$p%25$p%26$p"' | ./level02

the script to use is in the ressource folder
