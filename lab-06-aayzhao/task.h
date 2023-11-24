// -----------------------------------
// 	COMP 211 - Systems Fundamentals
//
//	Fall 2022 - Lab 6
// -----------------------------------

#include <math.h>

#ifndef _TASK_H_
#define _TASK_H_
typedef struct task_struct {
    unsigned int priority;		// priority (zero or postive integer)
    unsigned int pid;		// process id (zero or postive integer)
    int remaining_cycles;	// count of the remaining cpu cycles needed to complete this task
    struct task_struct* next;	// next task_struct in the linked list
} task_struct;
#endif


// ------------------------------------
// Function prototype
// ------------------------------------
//  Description:
//      Remove all task_structs in the linked list
//      (i.e., size = 0 ).
//
//      ** This includes unallocating memory used by
//      each task_struct in the linked list. **
//
//  Arguments:
//      None
//
//  Return:
//      None

void clear();

// ------------------------------------
// Function prototype
// ------------------------------------
//  Description:
//      Total number of task_structs in the linked list
//
//  Arguments:
//      None
//
//  Return:
//      non-negative integer value (if 0, then the list is empty)

unsigned int size();

// ------------------------------------
// Function prototype
// ------------------------------------
//  Description:
//      Create a new task_struct:
//          - allocate memory,
//          - set task_struct priority to specified priority,
//          - set task_struct pid to specified pid.
//          - set task_struct remaining_cycles to specified cycles.
//      Then append the task_struct to the end of the linked list
//
//  Arguments:
//      pid: unsigned integer value (zero or positive integer number)
//      priority: unsigned integer value (zero or positive integer number)
//      cycles: integer value
//
//  Return:
//      0 (TASK_OP_PASS):	append operation is successful
//      1 (TASK_OP_ERROR):	append operation is not successful
//                      i.e., duplicate pid in the linked list

unsigned int append_task(unsigned int pid, unsigned int priority, int cycles);

// ------------------------------------
// Function prototype
// ------------------------------------
//  Description:
//      Create a new task_struct:
//          - allocate memory,
//          - set task_struct priority to specified priority,
//          - set task_struct pid to specified pid.
//          - set task_struct remaining_cycles to specified cycles.
//      Then insert the task_struct at the specified index position
//      in the linked list.
//
//      Note: Shifts the task_struct currently at specified index
//      position (if any) and any subsequent task_structs to the
//      right (effectively adding one to their index position).
//
//  Arguments:
//      index: unsigned integer value (zero or positive integer value)
//      pid: unsigned integer value (zero or positive integer value)
//      priority: unsigned integer value (zero or positive integer value)
//      cycles: integer value
//
//  Return:
//      0 (TASK_OP_PASS):	insert operation is successful
//      1 (TASK_OP_ERROR):	insert operation is not successful
//                      i.e., duplicate pid in the linked list -or- index is out of range (index < 0 || index > size())

unsigned int insert_task(unsigned int index, unsigned int pid, unsigned int priority, int cycles);

// ------------------------------------
// Function prototype
// ------------------------------------
//  Description:
//      Change the location of an existing task_struct (using pid)
//      in the linked list to the specified index position.
//
//      Note: Shifts the task_struct currently at specified index
//      position that (if any) and any subsequent task_structs to
//      the right (effectively adding one to their index position).
//
//  Arguments:
//      index: unsigned integer value (zero or positive integer value)
//      pid: unsigned integer value (zero or positive integer value)
//
//  Return:
//      0 (TASK_OP_PASS):	set operation is successful
//      1 (TASK_OP_ERROR):	set operation is not successful
//                      i.e., pid is not in the linked list -or- index is out of range ( index < 0 || index >= size() )

unsigned int set_task(unsigned int index, unsigned int pid);

// ------------------------------------
// Function prototype
// ------------------------------------
//  Description:
//      Remove a task_struct (using pid) in the linked list and
//      return it.
//
//      ** This operation does not unallocate memory occupied
//      by the task_struct. **
//
//      Note: Shifts any subsequent task_structs to the left
//      in the linked list (effectively subtracts one from their
//      index position).
//
//  Arguments:
//      pid: unsigned integer value (zero or positive integer value)
//
//  Return:
//      task_stuct*:	if the operation is successful
//      NULL:	if the pid is not in the linked list

task_struct* remove_task(unsigned int pid);

// ------------------------------------
// Function prototype
// ------------------------------------
//  Description:
//      Get the task_struct for the specified pid value
//      in the linked list and returns the task_struct.
//
//      ** This operation does not unallocate memory occupied
//      by the task_struct. **
//
//  Arguments:
//      pid: unsigned integer value (zero or positive integer value)
//
//  Return:
//      task_stuct*:	operation is successful
//      NULL:	pid is not in the linked list

task_struct* exists(unsigned int pid);

// ------------------------------------
// Function prototype
// ------------------------------------
//  Description:
//      Get the task_struct at the specified index position
//      in the linked list and returns the task_struct.
//
//      ** This operation does not unallocate memory occupied
//      by the task_struct. **
//
//  Arguments:
//      index: unsigned integer value (zero or positive integer value)
//
//  Return:
//      task_stuct*:	operation is successful
//      NULL:	index is out of range ( index < 0 || index >= size() )

task_struct* get_task(unsigned int index);

// ------------------------------------
// Function prototype
// ------------------------------------
//  Description:
//      Swap the position of two pids (e.g., pid_1 and pid_2)
//      in the linked list
//
//      Note: there is an easy and a hard way to achieve
//      operation, you decide :)
//
//  Arguments:
//      pid_1: unsigned integer value (zero or positive integer value)
//      pid_2: unsigned integer value (zero or positive integer value)
//
//  Return:
//      0 (TASK_OP_PASS):	swap operation is successful
//      1 (TASK_OP_ERROR):	swap operation is not successful
//                      i.e., pid_1 and/or pid_2 are not in the linked list -or-
//                              pid_1 == pid_2
//

unsigned int swap(unsigned int pid_1, unsigned int pid_2);

// ------------------------------------
// Function prototype
// ------------------------------------
//  Description:
//      Perform the min heapify algorithm on the linked list.
//      See Heaps.pdf documentation in github repo.
//
//  Arguments:
//      None
//
//  Return:
//      None
//

void schedule();

// ------------------------------------
// Function prototype
// ------------------------------------
//  Description:
//      Print the pid and priority of each task_struct in the
//      linked list.
//
//  ** DO NOT MODIFY THE CODE IN THIS FUNCTION **
//  ** USED BY THE AUTOGRADER TO EVALUATE TESTCASES **
//
//  Arguments:
//      None
//
//  Return:
//      None
//

void print_tasks();

// ------------------------------------
// Function implementation
// ------------------------------------
//  Description:
//      Compares two floating point numbers.
//
//  ** DO NOT MODIFY THE CODE IN THIS FUNCTION **
//  ** USED BY THE AUTOGRADER TO EVALUATE TESTCASES **
//
//  Arguments:
//      a: float
//      b: float
//
//  Return:
//       0: |a - b| < epsilon
//       Otherwise:
//       1:  a < b
//      -1:  a > b
//

int compare_floats(float a, float b);
