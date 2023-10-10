# Lab 03

This will be a simple lab exploring bitwise operators in C. You will create a file called `bit_utils.c` and implement the functions specified in `bit_utils.h` within `bit_utils.c`. 

At the top of `bit_utils.c`, include the honor code and the header file like so:
```c
// PID: _________
// I pledge the COMP 211 honor code.

#include "bit_utils.h"
```
**Don't use** any more include statements; by including `bit_utils.h`, your `bit_utils.c` file will have access to `stdio.h`, `stdlib.h`, and `stdbool.h`, and so you have access to all associated functions and constants. You should only edit the `bit_utils.c` file, and the `test.c` file for testing. It's important that your code implements algorithms that take advantage of binary's "power of two" properties. 

**Important Note**: We reserve the right to deduct points from the autograder if we notice that you have hard-coded any test cases that did not actually fully implemented the functions, or included libraries that are not approved. If you have a question related to our policies, then you **must ask**.

## Background Reading
- C Programming Language Section 7.8.5 - malloc
- C Programming Language Section 2.9 - Bitwise Operators

### Vim Tips
If you have decided to stick with solely using Vim for this course, firstly you are cooler and have a greater potential power level than everyone that isn't, and secondly you are probably used to basic navigation in Vim with keystrokes like `h`/`l` and `j`/`k`. Hopefully, you may also remember `w`,`b`,`e`, deleting words and lines by combining the delete key with directional keystrokes like `dw`, `dd`, `d2j`, undoing things with `u`, and directional movements like `gg` and `G`. If you are not familiar, it is recommended that you consider revisiting the `vimtutor` from time to time so that editing documents becomes easier.

Another important concept in Vim is Visual Mode: you can enter visual mode from normal mode simply by pressing `v`. Visual mode allows you to select text. The text between your cursor when you press `v` and where you move your cursor after pressing `v` will be selected (it should be highlighted in vim). Press `y` (yank) to copy the selected text or `d` to delete it (this will also copy it). After pressing y or d, you will have copied the selected text and returned to normal mode, where you can press `p` and paste the copied text after your cursor. This is useful for moving chunks of code around a file or between tabs.

Note you can also use `V` (`shift` + `v`) to enter visual line mode, which allows you to select entire lines at once or `ctrl` + `v` to enter visual block mode, which allows you to select "blocks" of text (Something not possible in normal editors!). Try it out!

Search: to search for a word in vim, simply type `/<word-to-search>` in Normal mode. For example to find the next mention of a variable foo, type `/foo` and hit enter. You can press `n` and `<shift> + n` to go to the next and previous matches for `foo`.

More tips for aspiring vim power users [here](https://vim.fandom.com/wiki/Best_Vim_Tips).

### Testing
In this lab, you are creating a mini library rather than a program. So, instead of typical test files, a `test.c` has been provided with two helpful debug functions. To test your code you must write a `main` function and call the debug functions from main, save, compile and run your code.

#### Compiling with Make
In Lab 02, you learned that you could use the following command to give a custom name to your compiled program's executable file:
```sh
gcc -o ExecutableName SourceProgram
```
This is a perfectly reasonable way to compile programs, but it is a bit lengthy, and as more source files become involved, it becomes even more lengthy. In order to produce a working `test` executable file, you have to compile each dependent file and then link it:
```sh
gcc -c bit_utils.c
gcc -c test.c
gcc bit_utils.o test.o -o test
```

This is a lot of work, and doesn't even include `gcc` flags that give important information. Fortunately, GNU has created a tool called *GNU Make*, which lets you compile a program and generate an executable with one short command: `make`.

To use Make, you must provide a file called a `Makefile`. The `Makefile` serves a blueprint with all of the information needed to compile your project, namely all of the commands that would have needed to be previously entered to compile a project. For this lab, a `Makefile` is provided, so you do not need to construct one, but you should take a look at it to try to see what it does. If you are interested in learning more, check out the [official documentation](https://www.gnu.org/software/make/).

Simply, you just need to enter the command `make` and your code will compile, generating an executable called `test`.

### A Note on representation
Integers in C can be declared with a decimal, hexadecimal or octal number. The following three lines of code are equivalent:
``` c
int n = 0x05; int i = 0xa2; // hex
int n = 5;    int i = 162;  // decimal
int n = 05;   int i = 0242; // octal
```
The underlying representation in binary for `162` and `0xa2` is the same. You can use the "%d", "%x", and "%o" string formatters to print integers in the decimal, hex, or octal format respectively. You can use capital or lowercase letters when specifying numbers in hex, the result is the same.

Hex is a very convenient representation because each hex digit always corresponds to the same four bits in binary. i.e. 0x7 = 0111, 0x07 = 0x00000111, 0xE = 1110, and 0xE7 = 11100111. This property of hexadecimal makes it much easier to think about the underlying binary representation of numbers. 

## Part 0: `itob`
To better visualize the bits, we will refactor the code from Lab 02's `twos.c`. Copy your code from twos.c into `bit_utils.c` and convert it to a function called `itob` that takes two integer parameters, `num` and `size` (the size of `num` in bits) and returns the binary representation of `num` as a string of '1's and '0's. `Note`: If you’re not comfortable using your twos.c code, you may use our code in this [zip](https://uncch.instructure.com/users/9947/files/5332980/download?download_frd=1) file.
 

Note that the memory allocated for variables declared inside a function will be overwritten after the function call returns, so simply declaring a string as a character array and returning it's address from the `itob` function will not work. You will have to use `malloc` to allocate space to the string you eventually return from `itob`. This should not involve any major changes to the code from lab 02 besides putting it in a function that returns a string and using malloc to allocate space initially for the string that is returned.

Make sure your `itob` function is working properly before moving on!
You can test it by printing some values from main. For example:
```c
printf("A: %s\n", itob('A', 8));
printf("65: %s\n", itob(65, 8));
printf("0x41 : %s\n", itob(0x41, 8));
printf("%s\n", itob(0xFFFFFFFF, 32));
```
Should print out:
```
A: 01000001
65: 01000001
0x41 : 01000001
11111111111111111111111111111111
```
**Note**:  Theoretically `itob` can handle any size number, but in C, integers are represented with 32 bits, so 0xFFFFFFFF is the largest number you should pass to `itob`. We're also using two's complement here because that is what C uses. Using another representation might give us unexpected results.

## Part 1: Bitwise Operators
Write three functions, `mask_bits`, `set_bits`, and `inverse_bits` in `bit_utils.c`. These functions should each take two integer parameters: the first one is a number to be operated on and the second is the bits that will be masked, set, or inversed. Each function should return the number with the applied mask, set, or inverse.

For example,
- `mask_bits(0x00F7, 0x000F)` should return `0x0007`.
- `set_bits(0x00F7, 0x000F)` should return `0x00FF`.
- `inverse_bits(0x00F7, 0x000F)` should return `0x00F8`.

These functions should only take one or two lines of code.

You can test these with the provided `debug` function like so:
```c
// debug(number, bits_to_mask_set_or_inverse, function_name)
debug(0x1111, 0xFF00, mask_bits);
```

Note that all integers in C are 32 bits and when you declare an integer with hex, it gets zero-padded. So passing 0x0F to mask_bits is equivalent to passing 0x0000000F. These functions are always dealing with 32-bit values.

## Part 2: bit_select
Now we'll make a slightly more complicated function. Write a function called `bit_select` that takes three integer parameters: a number, the most significant bit to select and the least significant. The function should return the bits between the starting bit and the ending bit of the number (including the starting and the ending bit).

For example:
- `bit_select(0xE7E7, 3, 0)` should return `0x7`,
- `bit_select(0xE7E7, 7, 0)` should return `0xe7`, and
- `bit_select(0xE7E7, 6, 1)` should return `0x33`;

Remember the difference between shift right logical and shift right arithmetic. You may need to use C's `unsigned int` primitive variable type to prevent arithmetic right shifting.

## Submit your assignment
1. Use git to push your finished code to this Github repository.
2. Go to the COMP 211 course in GradeScope and click on the assignment called **Lab 03**.
3. Click on the option to **Submit Assignment** and choose GitHub as the submission method.
4. You should see a list of your public repositories. Select the one named **lab-03-yourname** and submit it.
5. Your assignment should be autograded within a few seconds and you will receive feedback for the autograded portion.
6. If you receive all the points, then you have completed this lab! Otherwise, you are free to keep pushing commits to your GitHub repository and submit for regrading up until the deadline of the lab.

## Grading
### Autograder tests (8 pts)
Remember, you can submit as many times as you like before the due date to get full credit.

### Style (2 pts)
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
