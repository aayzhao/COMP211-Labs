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
Declarations for the heap struct and its helper functions are located here 
as well. 

### output.h
Contains declarations for functions to print arrays to console. Currently 
supports printing long and int arrays.

### arraystruct.h
Contains declarations for the array-t struct, which mimics arrays in java;
helper functions for manipulating array-t structs; and the heap type struct and
associate 

### binops.h
Contains declarations for binary operation functions, such as printing the
binary representation of a given int. Also has itob functions for converting
ints into their binary representation as a char buffer.

## Signing
As of 9/14/2023, all commits will be signed with a verified SSH key. Github 
commits should reflect this in the commit history.
