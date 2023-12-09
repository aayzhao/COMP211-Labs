# COMP211-Labs
Code for labs, classwork, and practice in COMP 211, UNC Fall 2023.

Software is licensed under a modified version of the MIT license,
specifically disallowing use of this software in conflict with 
academic honor codes.

Labs are located in their respective folders. Scratchwork created in class
is located in /classwork/, and helper libraries designed to aid in open-CLI 
quizzes are located with header .h files and source .c files 
in /includes/ and /source/, respectively.

## Classwork
Files for following along and experimentation during classes

## Lab 00
Simple "Hello, World" lab. 

## Lab 01
Basic string library function implmentations. Part 1 is converting strings to 
lowercase, Part 2 is very rudimentary text justification and truncation, using 
stdio.h functions.

## Lab 02
Lab dealing with binary operations. Part 1 is converting ints to 16-bit
representation with MSB indicating positive or negative. Part 2 is
converting ints to 16-bit representation in 2's complement. Part 3 is negating
2's complement, given a string of binary. 

## Lab 03
Lab about further binary operations, specifically masking, negating, setting,
and selecting. Also implements a itob function that prints an 2's complement
integer to console for use in debugging.

## Lab 04
MIPS instruction comprehension lab. Simulates translating a 32 bit instruction
into the assembly code, then the operations performed by the assembly 
instructions.

## Lab 05
This lab simulates caching operations done by the CPU, specifically read-data
instructions. Implementation requires both Direct Mapping and Fully Associative
cache mapping techniques.

## Lab 06
A lab simulating the way CPUs schedule and execute tasks. Includes implementations of 
heapify, linkedlist, and other structures in order for the simulation to run. 
Scheduling commands are guaranteed to execute in O (n) time.

## Project
Final project for COMP 211. A working shell written in C that can execute built-in
and native linux commands. Uses fork() and execv() to execute programs. 

## /tests/
This file has some self practice for things outside of the classroom. 
It also holds sanity tests, mainly for open-CLI quizzes.

## /bin/, /includes/, and /source/
Includes is where headers for helper functions are located. Said functions
are defined in Source, and binaries built for the files will be located
in Bin. These files can be automatically compiled and linked with the
makefile located in /tests/.

### algo.h
Contains declarations for algorithms. Includes algorithms such as binary
search (for sorted arrays), algorithms for filling arrays, and heapsort. 

Declarations for the heap struct and its helper functions are located here.

Declarations for the hashset struct and its helper functions are located here.

Non-exhuastive list of Implemented algorithms:
- Binary Search (for sorted int and long arrays)
- Heapsort (for int and long arrays)
- HashSet add, remove, contains (CURRENTLY CAUSES SEG FAULT, DO NOT USE)
- Heap push, pop, contains 

### output.h
Contains declarations for functions to print arrays to console. Currently 
supports printing long and int arrays. Can print simply the elements, or perform
formatting adjustments, such as adding braces and commas.

### arraystruct.h
Contains declarations for the array-t struct, which mimics arrays in java;
helper functions for manipulating array-t structs; and the heap type struct and
associate 

### binops.h
Contains declarations for binary operation functions, such as printing the
binary representation of a given int. Also has itob functions for converting
ints into their binary representation as a char buffer.

ftob functions are also provided for converting IEEE-754 floating point
precision numbers into char buffers, along with size declarations. Also
has a printfloat() function that prints each individual part of the float 
for visual and formatting purposes.

## Signing
As of 9/14/2023, all commits will be signed with a verified SSH key. Github 
commits should reflect this in the commit history.
