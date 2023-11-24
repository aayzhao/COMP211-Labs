# Lab 06

## Introduction
In this lab, you will gain familiarity with many concepts, which are pertinent to both C programming and operating systems as a whole. To be concise, you will make use of the following concepts:
* Linked List Data Structure
* Priority Queue
* C Structs
* Pointers
* Memory Allocation and Deallocation

In particular, this lab has four goals:
1. Become familiar with the ```task_struct``` that is used by the OS to manage a program running in memory. Here, we'll only use a subset of fields found in the ```task_struct```, namely the *process id* (pid) and *priority*. The entire ```task_struct``` can be seen in the [sched.h](https://github.com/torvalds/linux/blob/master/include/linux/sched.h) header file that is distributed with the newest [linux kernel code](https://github.com/torvalds/linux). Typically, the pid and priority values are assigned by the OS, however in this lab you'll simulate this OS operation by manually assigning values to these ```task_struct``` fields.
2. Implement a **singly linked list** (or *linked list* for short) which is one of the fundamental data structures used extensively in operating systems. Each element in the linked list is a ```task_struct```. A linked list is a suitable data structure choice because of its efficient use of memory and the potential for constant time O(1) queue operations (enqueue and dequeue) and stack operations (push and pop). However, a linked list has some disadvantages that you'll soon become familiar with at the completion of the lab.  
3. Transform the linked list into a **priority queue** data structure using the **minimum heapify algorithm**. After heapification is performed the first element in the linked list will be a ```task_struct``` that has the highest priority (i.e. one with the smallest priority value). In general, a priority value is used by the OS to determine what **tasks** it should focus on first. For example, an OS would likely give high priority to I/O operations; it's important that the CPU reacts as soon as you type a key on the keyboard. On the other hand, a long download may have lower priority because the result is not expected to be immediate, so a little "slowness" is okay. 
4. Use the priority queue to simulate how an OS might schedule and dispatch a sequence of tasks to the CPU.

#### Background Reading
* Refer to the following for information on the necessary C concepts to complete this lab:
  * Read section 4.5 in *The C Programming Language* for an explanation about how header files work in C. In this lab, you are provided with a header file that specifies the functions that you must implement.
  * Read Chapter sections 5 in *The C Programming Language* to understand pointers and memory allocation and deallocation. 
  * Read Chapter sections 6 in *The C Programming Language* to understand the concept of a struct and how structs can be manipulated. 
* Refer to the following for a review on linked lists and list operations:
	* Read [Linked List Basics](http://cslibrary.stanford.edu/103/LinkedListBasics.pdf)
* Refer to the following for a review on binary heaps and the heapify algorithm:
	* Read [Heaps](Heaps.pdf) PDF file included in this repo.

## Structure
Much like the past couple of labs, you will implement a set of functions to be called by an external program. That is, the correctness of each function in the `task.c` source file will be evaluated using test-cases implemented in the `main` function found in the `lab06.c` source file (information about testing is further down). You may also modify the `main` function provided in the `lab06.c` source file and incorporate your own test-cases to fully evaluate the correctness of each function in the `task.c` source file. 

There are four additional starter files for this lab: 
* `task.h` header file, 
* `task.c` source file, 
* `sim.h` header file, and
* `sim.c` source file.

You **may not** add or remove global variables, alter the given function signatures, or add additional header files. **If this is done, points will be deducted.** Ask your cohort leader for clarification if you have any questions regarding this stipulation.

<!-- You may be familiar with the notion of header files from previous labs, in which you used the `#include` directive to include headers such as `stdio.h` and `stdlib.h` in order to use certain functions. The gcc manual defines two different types of header files:

* System header files declare the interfaces to parts of the operating system. You include them in your program to supply the definitions and declarations you need to invoke system calls and libraries.
* Your own header files contain declarations for interfaces between the source files of your program. Each time you have a group of related declarations and macro definitions all or most of which are needed in several different source files, it is a good idea to create a header file for them.

`stdio.h` and `stdlib.h` are examples of system header files, while `task.h` is a self-defined header file. 

Essentially, `task.h` acts as an interface which promises that the function prototypes contained within will be implemented in a separate source file. Your job for this lab is to modify `task.c` such that you implement the functions which have prototype declarations in `task.h`. -->

In summary, here is a description of each file and what you are expected to do with each one:
* `Makefile`- contains information used to compile your program with one command. **Do not modify.**
* `task.h`- contains prototype declarations of functions that will be included in the final program. **Do not modify.**
* `task.c`- contains implementations of each of the following function prototypes. You will implement the following functions listed below:
	* `clear` : removes all `task_structs` in the linked list.
	* `size` : returns the number of `task_structs` in the linked list.
	* `append_task` : append a new `task_struct` to the end of the linked list.
	* `insert_task` : insert a new `task_struct` at the specified index position in the linked list.
	* `set_task` : Change the location of an existing `task_struct` at the specified index position in the linked list.
	* `remove_task` : removes an existing `task_struct` from the linked list
	* `exists` : checks if an existing `task_struct` is in the linked list
	* `swap` : swaps the position of two existing `task_structs` in the linked list 
	* `schedule` : perform the min heapify algorithm on the linked list
	* `get_task` : returns an existing `task_struct` at the specified index position in the linked list
* `sim.h`- contains prototype declarations of functions that will be included in the final program. **Do not modify.**
* `sim.c`- contains implementations of each of the following function prototypes. You will implement the following functions listed below:
	* `dispatcher` : runs the linked list of `task_structs` using a scheduling queue
	* `run` : 'runs' a given task and for a given number of CPU cycles
* `lab06.c` - contains a main function that scans in values. You may modify the specified section to test your functions.

In `task.h` you will find the definition of a structure called `task_struct` which contains data `(priority, pid, remaining_cycles)` and pointer `next`. 

```c
typedef struct task_struct {
	unsigned int priority;		// priority (zero or postive integer)
	unsigned int pid;		// process id (zero or postive integer)
	int remaining_cycles		// count of the remaining cpu cycles needed to complete this task
	struct task_struct* next;	// next task_struct in the linked list
} task_struct;
```


Lastly, there are **copious** amounts of comments in the `task.h` and `sim.h` headers as well as in the `task.c` and `sim.c` source files. Read the comments carefully, they provide information needed to complete this assignment.

## Part 1. Linked List
First, you will implement the linked list data structure by completing the following functions in `task.c`:
* `clear` : removes all `task_structs` in the linked list.
* `size` : returns the number of `task_structs` in the linked list.
* `append_task` : append a new `task_struct` to the end of the linked list.
* `insert_task` : insert a new `task_struct` at the specified index position in the linked list.
* `set_task` : Change the location of an existing `task_struct` at the specified index position in the linked list.
* `remove_task` : removes an existing `task_struct` from the linked list
* `exists` : checks if an existing `task_struct` is in the linked list
* `swap` : swaps the position of two existing `task_structs` in the linked list 
* `get_task` : returns an existing `task_struct` at the specified index position in the linked list

## Part 2. Scheduling
Next, you will use this data structure in the implementation of the `schedule` function in `task.c`. For this function, you can read `Heaps.pdf` to learn the algorithm.
* `schedule` : perform the min heapify algorithm on the linked list

This function should turn the linked list of `task_structs` into a priority queue. To figure out the position of a task in the priority queue, you must use the `priority` of that task along with the `remaining_cycles` for that task. Specifically, your procedure should use the (`float`) value `priority / remaining_cycles` to prioritize tasks. We provide a `compare_floats` function for you, since comparing floating point numbers can be problematic (see [here](https://www.geeksforgeeks.org/comparison-float-value-c/)). For example, if Task 1 has a priority of 1 and 5 remaining cycles while Task 2 has a priority of 5 and 100 remaining cycles, Task 2 should be at the head of the queue, since 0.05 < 0.2. (Note that `priority` is an `unsigned int` and `remaining_cycles` is an `int`, so you must cast them as `floats` when performing this division.)

If this comes out to be equal, then the task with the lower `priority` should come first. 
If this comes out to be equal *and* the `priorities` of both tasks are equal, then relative ordering of the two tasks should remain the same (i.e. If you are comparing two child nodes, the left one will come first, and if you are comparing a child with its parent, the parent should come first). Note that, depending on your implementation, this second case will likely already be taken care of, since the min heapify algorithm is [*stable*](https://www.geeksforgeeks.org/stable-and-unstable-sorting-algorithms/).

## Part 3. Dispatching
Finally, you will simulate how an OS schedules and runs tasks on a CPU using the minimum heap data structure as a priority queue. This will be accomplished by completing the following functions in `sim.c`:
* `dispatcher` : runs the linked list of `task_structs` using a scheduling queue
* `run` : 'runs' a given task and decreases the number of `remaining_cycles` for that task

The `run` function is pretty simple. Given a `task_struct` and a `num_cycles`, it will decrease its `remaining_cycles` member and print out `Task {pid} run for {num_cycles} cycle(s).` If the task has been completed (i.e. its `remaining_cycles` member is at or below 0), then this function should also print out `Task {pid} Completed.` {pid} is the `pid` of the task.

The `dispatcher` function will be more complicated. It should `schedule` the list of `task_structs` to turn it into a priority queue. Then, it should get the highest priority task (the task at index 0), remove it from the list, and `run` the task for the given number of cycles. If that task is complete, then it should `schedule` the list again, maintaining the priority queue, and repeat for the next task at the head of the queue. If the task is *not* complete, then it should append the task back onto the list, `schedule` the list again, and repeat for the next task at the head of the queue.


## Testing
### Test Parts 1 and 2:
You will be provided with a driver file called `lab06.c` that reads integers to pass to calls of your functions. This driver file expects inputs in the following format:
```
n (number of task_struct)
pid_1 priority_1 remaining_cycles_1
pid_2 priority_2 remaining_cycles_2
...
pid_n priority_n remaining_cycles_n
index_i pid_i priority_i remaining_cycles_i (task to insert)
index_j pid_j (set task to index_j)
index_k (get the task at index_k)
pid_r (remove the task with pid_u)
pid_u pid_v (swap these two tasks)
```

For example, suppose the input is
```
4
12 99 100
13 1 80
14 7 60
15 0 40
0 16 1 55
1 15
4 
100
12 16
```
the output should be
```
----initial tasks----
(4)[ 12:99:100:0.99 13:1:80:0.01 14:7:60:0.12 15:0:40:0.00 ]
----insert task----
insert task{16:1} at index 0 with 55 cycles
(5)[ 16:1:55:0.02 12:99:100:0.99 13:1:80:0.01 14:7:60:0.12 15:0:40:0.00 ]
----set task----
set task {pid:15} to index 1
(5)[ 16:1:55:0.02 15:0:40:0.00 12:99:100:0.99 13:1:80:0.01 14:7:60:0.12 ]
----get task----
task at index 4: pid=14 priority=7 remaining cycles=60
---schedule----
(5)[ 15:0:40:0.00 13:1:80:0.01 12:99:100:0.99 16:1:55:0.02 14:7:60:0.12 ]
----remove_task----
remove task pid=100
(5)[ 15:0:40:0.00 13:1:80:0.01 12:99:100:0.99 16:1:55:0.02 14:7:60:0.12 ]
----swap task----
swap task: pid=12 <-> pid=16
(5)[ 15:0:40:0.00 13:1:80:0.01 16:1:55:0.02 12:99:100:0.99 14:7:60:0.12 ]
----clear all tasks----
[ empty ]
```
We provide several simple test cases in `test_data`. You can use them to test the correctness of your implementation. If you find an issue with any of these files, let your cohort leader know.
Example of Usage:
```sh
make
./lab06 < test_data/case1/input
```
You should see the following output:

```
----initial tasks----
(15)[ 1:32:100:0.32 2:43:100:0.43 54:23:100:0.23 123:99:100:0.99 124:13:100:0.13 12354:12:100:0.12 1023:0:100:0.00 454:2:100:0.02 4452:0:100:0.00 56:24:100:0.24 65:12:100:0.12 3:5:100:0.05 4:7:100:0.07 95:98:100:0.98 568:43:100:0.43 ]
----insert task----
insert task{675:0} at index 9 with 100 cycles
(16)[ 1:32:100:0.32 2:43:100:0.43 54:23:100:0.23 123:99:100:0.99 124:13:100:0.13 12354:12:100:0.12 1023:0:100:0.00 454:2:100:0.02 4452:0:100:0.00 675:0:100:0.00 56:24:100:0.24 65:12:100:0.12 3:5:100:0.05 4:7:100:0.07 95:98:100:0.98 568:43:100:0.43 ]
----set task----
set task {pid:124} to index 15
(16)[ 1:32:100:0.32 2:43:100:0.43 54:23:100:0.23 123:99:100:0.99 12354:12:100:0.12 1023:0:100:0.00 454:2:100:0.02 4452:0:100:0.00 675:0:100:0.00 56:24:100:0.24 65:12:100:0.12 3:5:100:0.05 4:7:100:0.07 95:98:100:0.98 568:43:100:0.43 124:13:100:0.13 ]
----get task----
task at index 0: pid=1 priority=32 remaining cycles=100
---schedule----
(16)[ 4452:0:100:0.00 675:0:100:0.00 1023:0:100:0.00 124:13:100:0.13 12354:12:100:0.12 3:5:100:0.05 454:2:100:0.02 1:32:100:0.32 2:43:100:0.43 56:24:100:0.24 65:12:100:0.12 54:23:100:0.23 4:7:100:0.07 95:98:100:0.98 568:43:100:0.43 123:99:100:0.99 ]
----remove_task----
remove task pid=3
(15)[ 4452:0:100:0.00 675:0:100:0.00 1023:0:100:0.00 124:13:100:0.13 12354:12:100:0.12 454:2:100:0.02 1:32:100:0.32 2:43:100:0.43 56:24:100:0.24 65:12:100:0.12 54:23:100:0.23 4:7:100:0.07 95:98:100:0.98 568:43:100:0.43 123:99:100:0.99 ]
----swap task----
swap task: pid=123 <-> pid=1023
(15)[ 4452:0:100:0.00 675:0:100:0.00 123:99:100:0.99 124:13:100:0.13 12354:12:100:0.12 454:2:100:0.02 1:32:100:0.32 2:43:100:0.43 56:24:100:0.24 65:12:100:0.12 54:23:100:0.23 4:7:100:0.07 95:98:100:0.98 568:43:100:0.43 1023:0:100:0.00 ]
----clear all tasks----
[ empty ]
```

The correct output is in `test_data/case1/output`. You can compare the differences line by line with your eyes.
Another approch is to use command [`diff`](https://www.geeksforgeeks.org/diff-command-linux-examples/). It can compare the differences between two files. So you can first save the output to one file and compare it with the correct one. The following is an example command:

```sh
make
./lab06 < test_data/case0/input > test_data/case0/my_output
diff -s test_data/case0/output test_data/case0/my_output
```

You should see the differences in the terminal. If the files are identical, then congrats and your coding solution passed all the test-cases.

You can evaluate other test-cases in `test_data`. You can also write your own test cases following the format to test the edge cases which are not covered by the provided ones.

**Think about the edge cases when you implement each function. They will be tested by the autograder.**

### Test Part 3
To test Part 3, all you have to do is use the command `./lab06 dispatcher` in place of `./lab06` above. For example, running `./lab06 dispatcher` and then entering

```
2
1 5 10
2 6 15
0 3 1 60
1 3
0 
100
1 2
```
should result in the output 
```
----initial tasks----
(2)[ 1:5:10:0.50 2:6:15:0.40 ]
----insert task----
insert task{3:1} at index 0 with 60 cycles
(3)[ 3:1:60:0.02 1:5:10:0.50 2:6:15:0.40 ]
----set task----
set task {pid:3} to index 1
(3)[ 1:5:10:0.50 3:1:60:0.02 2:6:15:0.40 ]
----get task----
task at index 0: pid=1 priority=5 remaining cycles=10
---schedule----
(3)[ 3:1:60:0.02 1:5:10:0.50 2:6:15:0.40 ]
----remove_task----
remove task pid=100
(3)[ 3:1:60:0.02 1:5:10:0.50 2:6:15:0.40 ]
----swap task----
swap task: pid=1 <-> pid=2
(3)[ 3:1:60:0.02 2:6:15:0.40 1:5:10:0.50 ]
----dispatch tasks----
Task 3 ran for 5 cycle(s).
Task 3 ran for 5 cycle(s).
Task 3 ran for 5 cycle(s).
Task 3 ran for 5 cycle(s).
Task 3 ran for 5 cycle(s).
Task 3 ran for 5 cycle(s).
Task 3 ran for 5 cycle(s).
Task 3 ran for 5 cycle(s).
Task 3 ran for 5 cycle(s).
Task 3 ran for 5 cycle(s).
Task 3 ran for 5 cycle(s).
Task 3 ran for 5 cycle(s).
Task 3 Completed.
Task 2 ran for 5 cycle(s).
Task 1 ran for 5 cycle(s).
Task 2 ran for 5 cycle(s).
Task 1 ran for 5 cycle(s).
Task 1 Completed.
Task 2 ran for 5 cycle(s).
Task 2 Completed.
```
Notice how the `----clear all tasks----` section is replaced with a `----dispatch tasks----` section. The expected outputs for the given tests are also included in the `test_data` folder and can be checked with:

```sh
make
./lab06 dispatcher < test_data/case0/input > test_data/case0/my_output
diff -s test_data/case0/output_dispatcher test_data/case0/my_output

```

## Submit your assignment
1. Use git to push your finished code to this GitHub repository.
2. Go to the COMP 211 course in GradeScope and click on the assignment called **Lab 06**.
3. Click on the option to **Submit Assignment** and choose GitHub as the submission method.
4. You should see a list of your public repositories. Select the one named **lab-06-yourname** and submit it.
5. Your assignment should be autograded within a few seconds and you will receive feedback for the autograded portion.
6. If you receive all the points, then you have completed this lab! Otherwise, you are free to keep pushing commits to your GitHub repository and submit for regrading up until the deadline of the lab.

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

We reserve the right to deduct points from the autograder if we notice that you have hardcoded any test cases and not actually fully implemented the functions.

