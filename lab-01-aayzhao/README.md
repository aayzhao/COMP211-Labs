# Lab 01
You should be able to do these exercises with knowledge only from **chapter 1** in the [C Programming Language](https://uncch.instructure.com/users/9947/files/4526296?verifier=bzWbUsKclOVAAJ7MfuwOyS5v8DDILep0R7HtGh7t&wrap=1) textbook. `If you're having trouble, then revisit sections 1.5 and 1.6 and carefully study the code examples.` At the end of this file there are some tips for testing your code.

In this assignment, you **can only** use the `stdlib.h`, `stdio.h`, and `stdbool.h` headers. That is, you **may not** include the `string.h` header and use any of the string functions in the string library. **If you use the string library in your program, then any points received by the autograder will be removed.** In short, **If have any questions, then you must ask!**

## Part 0: Getting Started

### Linux command-line workflow
Like you learned in the first lab, the workflow to write, compile, and run C programs is outlined below:
1. Start the learncli docker image and clone this repository by entering `git clone <repository>`, where `<repository>` is the SSH-based URL of your repository; e.g. `git clone git@github.com:Comp211-FA23/lab-01-username.git`. You can get this URL by clicking Code -> SSH.
2. Enter the directory with `cd lab-01-<username>`
3. Start writing your C program in a file in vim by entering, e.g., `vim <name-of-program>.c`
4. Whenever you want to run your program, you must first return to the terminal and compile it with the following steps:
  - `gcc <name-of-program>.c` will compile the program and store the binary in a file called `a.out`. If there were any compilation errors (like bad syntax), gcc will warn you and the code will not compile. Whenever you compile your code again, the previous `a.out` will be overwritten with the new program.
  - `./a.out` runs the program. In Linux, typing `./` before the filename will attempt to execute that file.
  - `echo <some-text-input> | ./a.out` this will pipe `<some-text-input>` into the standard input of the program. It's as if you typed `<some-text-input>` to the program yourself while it was running.
  - `./a.out <arg1> <arg2>` will run the program, supplied with some command line arguments. We will not be handling arguments in Lab 01.

## Part 1: Going All Lower
Go into to the directory named `1-going-all-lower` (hint: use the `cd` command).

A recent Reddit thread you made regarding code style has caused a heated debate online. After spending 30 minutes reading many all-caps comments, your eyes are strained. Rather than leave the debate unfinished, you decieded to write a new C program in a file named `lower.c` that will convert all characters from the standard input to lowercase. For example:

```
learncli$ echo "TAR HEELS" | ./a.out
tar heels
```
Note that none of the tests will be concerned with newlines, but other non-alphabetical characters (such as punctuation) should be preserved in the output.

*Hint: There are better and easier ways to do this than writing 26 `if` statements. Think about how to use ASCII codes to your advantage and remember that the `char` type can be treated like an unsigned number (similar to `int`, `short`, etc.).*

## Part 2: Compatibility
Go into the directory named `2-compatibility`.

Your friend's monitor is too small and can only display up to 50 characters on a line before they run off the screen. They aren't good with computers, so you decide to write a C program in a file named `truncator.c` that will reprint input so that no line is longer than 50 characters. Specifically, for lines less than or equal to 50 characters, simply reprint the line. For lines greater than 50 characters, insert a newline at each 50-character interval.

**Note**: If the 51st character of a line in the input is a newline `'\n'`, then you should not print it (to avoid unnatural double newlines in the text). Depending on your solution, you may not need extra code for this. So worry about this case last.

***Tip**: Write your own file with test input for the case where the 51st character is a newline. In the bottom-right corner of Vim, you can see the line and column number of your cursor and plan your 51-character input accordingly.*

Furthermore, to give developers feedback on their programs for 50-character-displays, you decide to add additional functionality to your program by displaying the line numbers of all lines over 50 characters long and the total number of these offending lines.

For example:
```
learncli$ cat test0.txt
This line is under 50 characters long
This line is just over 50 characters long, you see?
This line is soooooooooooooooooo looooouoooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooong!

learncli$ cat test0.txt | ./a.out
This line is under 50 characters long
This line is just over 50 characters long, you see
?
This line is soooooooooooooooooo looooouoooooooooo
oooooooooooooooooooooooooooooooooooooooooooooooooo
oooooong!

Total lines over 50 chars: 2
Offending lines: 1, 2,
learncli$
```
*Some additional things to note:*
 - The first line is the 0th line.
 - You can assume that none of the test input will contain over 100 illegal lines, so you can use an array of length 100 to store the line numbers in.
 - There should be a newline `\n` after the reformatted output and a newline after the line that says "Offending lines..."*
 - The test input will not contain any tabs, which generally take up as much space as multiple characters.
 - Windows uses [carriage return](https://www.easytechjunkie.com/what-is-carriage-return.htm), so if a new file is created in Windows, for each new line character, there will be a carriage return (`'\r'`) before it. Also, sometimes certain bad editors on Windows will insert carriage returns when editing or opening a file. This can be avoided by doing all work inside of the container, or using the `dos2unix` command (after installing it with `apt install dos2unix`), or ignoring that character.

## Tips for testing
- Some test inputs and results are included for you to check for correctness. You can also write your own tests.
- You can test for the correctness of your programs by running:
    ```
  learncli$ gcc <progam-name.c>
  learncli$ cat test0.txt | ./a.out > myresult
  learncli$ diff myresult test0-result.txt
  ```
  The first command compiles the c program to `a.out`. The second pipes the text in `test0.txt` to the standard input of your program and redirects the output of your program to a new file called `myresult` (instead of just printing it to the screen). And the third command runs the `diff` program on `myresult` and `test0-result.txt`, which will show any differences between the output from your program and the correct output. If nothing prints after running the diff command, then your output matches!

  You can also run all three commands on the same line by separating them with a semicolon `;`:
    ```
  learncli$ gcc <progam-name.c>; cat test0.txt | ./a.out > myresult; diff myresult test0-result.txt
  ```

## Submission
Submit the assignment to Gradescope the same way you did for Lab 00. Don't forget to add your PID and honor code to each .c file as below!
```c
// PID: 9DigitPidNoSpacesOrDashes
// I pledge the COMP 211 honor code.
```
1. Navigate to the base folder of the repository within Docker using the ```cd``` command.
2. Type `git status`. You should see a list of changes that have been made to the repository.
3. Type `git add -A`. This signals that you want to place all modified / new files on the "stage" so that their changes can take effect.
4. Type `git commit -m "Your Message Here"`. This shows that you are "committing" to the changes you put on the stage. Instead of Your Message Here, you should write a meaningful message about what changes you have made.
5. Type `git push`. This takes the commit that was made locally on your machine and "pushes" it to GitHub. Now, when you view this repository on GitHub you should be able to see the changes you've made, namely the addition of your source files!
6. Go to the COMP 211 course in GradeScope and click on the assignment called **Lab 01**.
7. Click on the option to **Submit Assignment** and choose GitHub as the submission method.
8. You should see a list of your public repositories. Select the one named **COMP211-FA23/lab01-yourname** and submit it.
9. Your assignment should be autograded within a few seconds and you will receive feedback for the autograded portion.
10. If you receive all the autograder points, then you have completed this lab! Otherwise, you are free to keep pushing commits to your GitHub repository and submit for regrading up until the deadline of the lab.

**Note**: You may have noticed that after executing `git add -A`, your binary `a.out` files were not added to staging. This is because we specified in the `.gitignore` to not include executable files. It is considered bad practice to have compiled binaries in your published git repository!
  - if an a.out or other file gets added accidentally to staging, `git reset <file-name>` will remove the file from staging without actually deleting the file.
  - Check which files are on the stage be commited at any time by entering `git status`.

You shouldn't need to worry about this, the important thing for grading is that all your C source files are in the correct directories.

## Grading
### Autograder tests (8 pts)
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

We reserve the right to deduct points from the autograder if we notice that you have hardcoded any test cases and not actually fully implemented the program, especially if your solution to part uses 26 (or more!) `if` statements.
