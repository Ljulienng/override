After reverse engineering the program, we found 3 functions: main, test and decrypt

test() checks the argument passed to the stdin is at 0x15 (21) or inferior to 0x1337d00d (322424845 in decimal)

if the argument doesn't respect the conditions, it calls decrypt() with a random number as argument
else it calls decrypt() with our int with a byte left shifted by 2.

we can simply try to bruteforce the number by trying all the numbers between 0 and 21 and see if we get the flag

The int must be given from 322424845 minus 1 - 21:

we found that 322424845 - 18 = 322424827
