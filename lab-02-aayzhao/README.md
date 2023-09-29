# Lab 02

## Introduction
In this lab, you will gain familiarity with several methods to represent numbers with bits and understand what their representation really means. This lab is based heavily on the lecture discussions on information encoding and representation, so make sure you have an understanding of these concepts before starting!

#### Background Reading
* Refer to the following for information on signed magnitude representation, two's complement representation, and the negation of a two's complement value:
  * [Supplement: Binary Math and Signed Representations](https://uncch.instructure.com/users/9947/files/4534602?verifier=V0fp04VZnOi0ytrumtvCTbL2Xnz1zR5AUmj2H2S3&wrap=1)
  * Sections 2.1, 2.2, and 2.3 of [Computer Systems: A Programmer's Perspective](https://uncch.instructure.com/users/9947/files/4526297?verifier=GsaGSp6QkNQvZGMOCCiuAT4eyRWq70bxIKOgxjZr&wrap=1). The associated lectures may also be useful.
* C
  * Read section 5.10 in [The C Programming Language](https://uncch.instructure.com/users/9947/files/4526296?verifier=bzWbUsKclOVAAJ7MfuwOyS5v8DDILep0R7HtGh7t&wrap=1) for an explanation about how command line arguments work in C. In this lab, you will need to supply arguments through the command line for use in your C program.
  * See section 7.2 in The C Programming Language for a note on string formatting and how the `printf` function in C works.

#### Compiling and Executing / Naming Executables
In the previous lab, you were taught how to compile a C program on the command-line and execute the resulting file `a.out`. However, it is possible to give your executable file a custom name. By convention, compiled programs typically share the same name as the source code, but without the `.c` file extension.

The syntax to use on the command-line to do this is:
```sh
gcc SourceProgram -o ExecutableName 
./ExecutableName
```
In the above example, `ExecutableName` is the name of your executable (i.e. the equivalent of what was previously `a.out`), and `SourceProgram` is the name of the `.c` file you are compiling (note that it should have a `.c` file extension). We then run the executable program on the command-line with the command `./ExecutableName`.

Suppose you have written a program called `myprogram.c` and you want the executable to be called `myprogram`. The following syntax to compile the code and execute on the command-line will be:
```sh
gcc myprogram.c -o myprogram
./myprogram
```

#### Source Code Header
Each source file in COMP 211 should begin with the standard header comment below. Note this header is checked by the autograder for an exact match. Please be sure to format your PID as a single 9-digit number with no spaces nor dashes. Additionally, be sure your capitalization and punctuation of the honor code pledge are correct. Since we do grade manually for style, do not include names on code listings to avoid biasing the grading.
```c
// PID: 9DigitPidNoSpacesOrDashes
// I pledge the COMP 211 honor code.
```
# The Assignment

## Part 1. Signed Integers
Write a program named `signed.c` that takes a base-10 integer preceded by a positive or negative sign as a command-line argument, and outputs a 16-bit string of 1's and 0's corresponding to the integer's 16-bit signed magnitude representation. You may assume that the number provided as an argument is a valid input; that is, there will always be a + or - sign, followed immediately by a decimal number. If the provided argument cannot be represented as a 16-bit signed number, return that the representation is "not possible".

**Note:** Assume that +0 and -0 are both valid inputs, and that they have different representations from one another.

The following examples illustrate the expected input/output for a selection of numbers.
```
learncli$ ./signed +211
The signed 16-bit representation of +211 is: 0000000011010011.
```
```
learncli$ ./signed -211
The signed 16-bit representation of -211 is: 1000000011010011.
```
```
learncli$ ./signed +100000
The signed 16-bit representation of +100000 is: not possible.
```

**Hint**: You can use the standard library function `atoi` to convert an ascii string to an integer, i.e. `int num = atoi(input)`. Remember to include `<stdio.h>` at the top of the file to support input and output operations and `<stdlib.h>` for acess to standard library functions.

**Note**: make sure the output of your program matches the expected output exactly. Similar to the previous lab, the autograder is spelling, case, and spacing sensitive. 

***Extra important note:*** The programs in this lab are _not_ using standard input for input, but rather are using command line arguments. So, you should not be using `getchar`, `fgets`, or `scanf`; you should be working with `argv` directly.

## Part 2. Two's Complement
Write a program named `twos.c` that takes a base-10 integer preceded by a positive or negative sign as a command-line argument, and outputs a 16-bit string of 1's and 0's corresponding to the integer's representation in 16-bit 2's complement. You may assume that the number provided as an argument is a valid input; that is, there will always be a + or - sign, followed immediately by a decimal number. If the provided argument cannot be represented as a 16-bit signed number, indicate that the representation is "not possible".

**Note:** Assume that +0 and -0 are both valid inputs. Unlike the signed representation, both numbers map to the same encoding.

The following examples illustrate the expected input/output for a selection of numbers.
```
learncli$ ./twos +211
The two's complement 16-bit representation of +211 is: 0000000011010011.
```
```
learncli$ ./twos -211
The two's complement 16-bit representation of -211 is: 1111111100101101.
```
```
learncli$ ./twos +100000
The two's complement 16-bit representation of +100000 is: not possible.
```

## Part 3. Negation of Two's Complement
Write a program named `negate-2.c` that takes an integer in 32-bit 2's complement representation as a command-line argument, and outputs a 32-bit string of 1's and 0's corresponding to the negated version of the number in 32-bit 2's complement. You may assume that the binary string provided as an argument has 32 bits; that is, you do not need to write code to handle improper inputs.

**Hint:** The algorithm for negating a number in 2's complement is to flip all the bits (all 0's become 1's and all 1's become 0's) and then add 1 to the result.

The following example illustrates the expected input/output for a selection of numbers.
```
learncli$ ./negate-2 00000000000000000000000011010011
The negation of the 32-bit two's complement integer 00000000000000000000000011010011 is: 11111111111111111111111100101101.
```

## Submit your assignment
Assignment submissions will be made through [GradeScope](https://www.gradescope.com).

To submit your assignment, you must commit and push your work to this repository using git. You are likely unfamiliar with git at this point, so just follow these steps:

1. Navigate to the base folder of the repository within Docker using the ```cd``` commmand.
2. Type `git status`. You should see a list of changes that have been made to the repository.
3. Type `git add -A`. This signals that you want to place all modified / new files on the "stage" so that their changes can take effect.
4. Type `git commit -m "Your Message Here"`. This shows that you are "committing" to the changes you put on the stage. Instead of Your Message Here, you should write a meaningful message about what changes you have made.
5. Type `git push`. This takes the commit that was made locally on your machine and "pushes" it to GitHub. Now, when you view this repository on GitHub you should be able to see the changes you've made, namely the addition of your source files!
6. Go to the COMP 211 course in GradeScope and click on the assignment called **Lab 02**.
7. Click on the option to **Submit Assignment** and choose GitHub as the submission method.
8. You should see a list of your public repositories. Select the one named **lab-02-yourname** and submit it.
9. Your assignment should be autograded within a few seconds and you will receive feedback for the autograded portion.
10. If you receive all the points, then you have completed this lab! Otherwise, you are free to keep pushing commits to your GitHub repository and submit for regrading up until the deadline of the lab.

## Grading
### Autograder tests (8 pts)
Remember, you can submit as many times as you like before the due date to get full credit.

### Style (2pts)
* Variable Names (.5 pts)
	* Single-character variable names are only used for counting/indexing, or when used to represent a variable whose type has only one instance.
	* All "magic numbers" are defined as constants.
	* Variable names are either related to the usage of the variable, or the meaning is commented.
	* No unused variables are declared.
* Readability (.75 pts)
	* Proper indentation (use the following Vim trick: (1G=G) )
	* Consistent whitespace theme used throughout.
	* Logically distinct blocks of code are separated by whitespace.
	* No more than two consecutive lines of empty whitespace.
	* No old debug code is present (including in the comments).
* Correctness of Code (.75 pts)
	* For all functions (including main if applicable), every path of execution leads to a return statement.
	* No libraries are included that weren't provided in the starter code or mentioned in the README.

For this assignment, it's important that your code implements algorithms that take advantage of binary's "power of two" properties, and that no libraries are imported other than `stdio.h`, `stdlib.h`, and optionally, `stdbool.h`, and `limits.h`.

Test your answers locally before submitting to Gradescope! If you are sure that you are converting the numbers correctly, but not passing the tests, make sure your output is *exactly* the same as the examples. For example, the string you output in part 1, should be *exactly* "The signed 16-bit representation of *\<provided number and sign\>* is:
" followed by a string of the converted number and a period.

