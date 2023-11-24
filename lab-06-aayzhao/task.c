// PID: 730615143
// I pledge the COMP211 honor code.

// -----------------------------------
// 	COMP 211 - Systems Fundamentals
//
//	Fall 2022 - Lab 6
// -----------------------------------

#include "task.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define TASK_OP_PASS 0
#define TASK_OP_ERROR 1
#define NOT_FOUND 0
#define DEBUG 0

task_struct* head = NULL;
task_struct* tail = NULL;

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

void clear() 
{
    task_struct* prev;
    while (head != NULL)
    {
        prev = head;
        head = head->next;
        free(prev);
    }
    tail = NULL;
} // end clear() function

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

unsigned int size() 
{
    if (head == NULL) return 0;
    int count = 0;
    task_struct* it = head;
    while (it != NULL)
    {
        count++;
        it = it->next;
    }
    return count;
} // end size() function

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

unsigned int append_task(unsigned int pid, unsigned int priority, int cycles) 
{
    task_struct* it = head;
    while (it != NULL) // check for duplicates
    {
        if (pid == it->pid) return TASK_OP_ERROR;
        it = it->next;
    }

    // init task struct
    task_struct* task = malloc(sizeof(task_struct));
    task->next = NULL;
    task->pid = pid;
    task->priority = priority;
    task->remaining_cycles = cycles;

    if (head == NULL) // empty list case
    {
        head = task;
        tail = task;
    }
    else
    {
        tail->next = task;
        tail = task;
    }
    return TASK_OP_PASS; 
    
} // end append_task() function

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

unsigned int insert_task(unsigned int index, unsigned int pid,
                         unsigned int priority, int cycles) {
    if (index > size()) return TASK_OP_ERROR;
    
    // check for duplicates
    task_struct* it = head;
    while (it != NULL)
    {
        if (it->pid == pid) return TASK_OP_ERROR;
        it = it->next;
    }
    
    if (index == size()) return append_task(pid, priority, cycles); // inserting at tail

    // create task struct
    task_struct* task = malloc(sizeof(task_struct));
    task->next = NULL;
    task->pid = pid;
    task->priority = priority;
    task->remaining_cycles = cycles;

    if (index == 0) // if insert at head
    {
        task->next = head;
        head = task;
        return TASK_OP_PASS;
    }

    // insert in between tail and head
    it = head;
    for (unsigned int i = 0; i < index - 1; i++) it = it->next;
    task->next = it->next;
    it->next = task;

    return TASK_OP_PASS; 
} // end insert_task() function

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

unsigned int set_task(unsigned int index, unsigned int pid) 
{
    if (exists(pid) == NULL) return TASK_OP_ERROR; // PID not found
    unsigned int node_num = size();
    // check valid index/size
    if (index >= node_num || node_num == 0) return TASK_OP_ERROR;
    else if (node_num == 1) return TASK_OP_PASS; // only one node, no swap necessary
    
    // remove target from list
    task_struct* target = remove_task(pid);
    
    // reinsert task
    unsigned int res = insert_task(index, target->pid, target->priority, target->remaining_cycles);

    //free old task memory
    free(target);

    return res;
} // end set_task() function

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

task_struct* remove_task(unsigned int pid) 
{
    if (head == NULL) return NULL; // no tasks in list
    if (head == tail && head->pid == pid) // if only 1 task in list
    {
        task_struct* res = head;
        head = NULL;
        tail = NULL;
        return res;
    }
    task_struct* it = head;
    task_struct* prev = head;
    while (it != NULL)
    {
        if (it->pid == pid) break;
        prev = it;
        it = it->next;
    }
    if (it == NULL) return NULL; // pid not found   
    else if (it == tail) // task is tail
    {
        tail = prev;
        tail->next = NULL;
        return it;
    }
    else if (it == head) // task is head
    {
        head = it->next;
        it->next = NULL;
        return it;
    }
    else // task is neither tail nor head
    {
        prev->next = it->next;
        it->next = NULL;
        return it;
    }

} // end remove_task() function

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

task_struct* exists(unsigned int pid) 
{
    if (head == NULL) return NULL;
    task_struct* it = head;
    while (it != NULL)
    {
        if (it->pid == pid) break;
        it = it->next;
    }

    return it;
} // end exists() function

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

task_struct* get_task(unsigned int index) 
{
    if (index >= size()) return NULL;
    task_struct* it = head;
    for (unsigned int i = 0; i < index; i++) it = it->next; // iterate to index
    return it;
} // end get_task() function

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

unsigned int swap(unsigned int pid_1, unsigned int pid_2) 
{
    if (pid_1 == pid_2) return TASK_OP_ERROR;

    task_struct* t1 = NULL;
    task_struct* t2 = NULL;
    task_struct* it = head;

    while (it != NULL)
    {
        if (it->pid == pid_1) t1 = it;
        if (it->pid == pid_2) t2 = it;
        it = it->next;
    }

    if (t1 == NULL || t2 == NULL) return TASK_OP_ERROR;

    // swap values for the nodes
    unsigned int temp = t1->pid; // swap PIDs
    t1->pid = t2->pid;
    t2->pid = temp;

    temp = t1->priority; // swap priorities
    t1->priority = t2->priority;
    t2->priority = temp;

    temp = t1->remaining_cycles; // swap cycles
    t1->remaining_cycles = t2->remaining_cycles;
    t2->remaining_cycles = temp;

    return TASK_OP_PASS;
} // end swap() function

// bubble down helper function declaration
void bubbledown(task_struct** arr, unsigned int idx, unsigned int to);

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

void schedule() 
{
    if (head == NULL || head == tail) return;
    unsigned int node_num = size();
    task_struct** arr = malloc(sizeof(task_struct*) * node_num);
    task_struct* it = head;
    
    // init pointers of array to each node in list
    for (unsigned int i = 0; i < node_num; i++, it = it->next) arr[i] = it;

    // heapify array
    unsigned int to = node_num - 1;
    int i = node_num - 1; 
    if (i % 2 == 0) i = (i - 2) / 2;
    else i = (i - 1) / 2;
    
    for ( ; i >= 0; i--) bubbledown(arr, (unsigned int) i, to);

    // modify pointers for each node
    for (unsigned int j = 0; j < node_num - 1; j++) arr[j]->next = arr[j + 1];
    arr[node_num - 1]->next = NULL;

    // set head and tail
    tail = arr[node_num - 1];
    head = arr[0];

    free(arr);
    arr = NULL;
} // end schedule() function

// bubble down function definition
void bubbledown(task_struct** arr, unsigned int idx, unsigned int to)
{
    unsigned int i = idx;
    unsigned int target;
    unsigned int left = idx * 2 + 1;
    unsigned int right = idx * 2 + 2;

    // this if-else chain does the comparisons for bubbledown operations 
    // for heaps. It looks like a complete mess, but all it is doing is calculating 
    // priorities (priority / cycles left) then calling compare_floats() on 
    // the calculations. Storing calculations as actual variables would
    // probably help improve readability.
    if (left <= to && right <= to) {
        if (compare_floats((float) arr[left]->priority / (float) arr[left]->remaining_cycles, (float) arr[right]->priority / (float) arr[right]->remaining_cycles) == -1 || (compare_floats((float) arr[left]->priority / (float) arr[left]->remaining_cycles, (float) arr[right]->priority / (float) arr[right]->remaining_cycles) == 0 && arr[right]->priority < arr[left]->priority)) target = right;
        else target = left;
        if (compare_floats((float) arr[target]->priority / (float) arr[target]->remaining_cycles, (float) arr[idx]->priority / (float) arr[idx]->remaining_cycles) == 1 || (compare_floats((float) arr[target]->priority / (float) arr[target]->remaining_cycles, (float) arr[idx]->priority / (float) arr[idx]->remaining_cycles) == 0 && arr[target]->priority < arr[idx]->priority)) i = target;
    }
    else if (left <= to) {
        target = left;
        if (compare_floats((float) arr[target]->priority / (float) arr[target]->remaining_cycles, (float) arr[idx]->priority / (float) arr[idx]->remaining_cycles) == 1 || (compare_floats((float) arr[target]->priority / (float) arr[target]->remaining_cycles, (float) arr[idx]->priority / (float) arr[idx]->remaining_cycles) == 0 && arr[target]->priority < arr[idx]->priority)) i = target;
    }
    else if (right <= to) {
        target = right;
        if (compare_floats((float) arr[target]->priority / (float) arr[target]->remaining_cycles, (float) arr[idx]->priority / (float) arr[idx]->remaining_cycles) == 1 || (compare_floats((float) arr[target]->priority / (float) arr[target]->remaining_cycles, (float) arr[idx]->priority / (float) arr[idx]->remaining_cycles) == 0 && arr[target]->priority < arr[idx]->priority)) i = target;
    }
    
    if (i != idx)
    {
        task_struct* temp = arr[idx];
        arr[idx] = arr[i];
        arr[i] = temp;
        bubbledown(arr, i, to);
    }
}

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

void print_tasks() {
  task_struct* p_task = head;

  if (p_task == NULL) {
    printf("[ empty ]\n");
  } else {
    printf("(%d)[", size());

    while (p_task != NULL) {
      printf(" %d:%d:%d:%.2f", p_task->pid, p_task->priority, p_task->remaining_cycles, (float)p_task->priority/(float)p_task->remaining_cycles);
      p_task = p_task->next;
    }

    printf(" ]\n");
  }

} // end print_tasks() function

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
//       1:  a < b
//      -1:  a > b
//

int compare_floats(float a, float b) {
    const float epsilon = 0.0001;
    return fabs(a - b) < epsilon ? 0 : a < b ? 1 : -1;
} // end compare_floats() function
