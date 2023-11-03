#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../includes/algo.h"
int next_hashtable_size(int current)
{
    switch (current) 
    {
        case 53:
            return 97;
        case 97:
            return 193;
        case 193:
            return 389;
        case 389:
            return 769;
        case 769:
            return 1543;
        case 1543:
            return 3079;
        case 3079:
            return 6151;
        case 6151:
            return 12289;
        case 12289:
            return 24593;
        case 24593:
            return 49157;
        case 49157:
            return 98317;
        case 98317:
            return 196613;
        case 196613:
            return 393241;
        case 393241:
            return 786433;
        case 786433:
            return 1572869;
        case 1572869:
            return 3145739;
        case 3145739:
            return 6291469;
        case 6291469:
            return 12582917;
        case 12582917:
            return 25165843;
        case 25165843:
            return 50331653;
        case 50331653:
            return 100663319;
        case 100663319:
            return 201326611;
        case 201326611:
            return 402653189;
        case 402653189:
            return 805306457;
        case 805306457:
            return 1610612741;
        default:
            return current * 2;
    }
}

bucket_node_t* create_bucket_node()
{
    bucket_node_t* node = malloc(sizeof(bucket_node_t));
    node->val = 0;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void destroy_bucket_node(bucket_node_t* node)
{
    if (node == NULL) return;

    while (node->next != NULL)
    {
        node = node->next;
        free(node->prev);
        node->prev = NULL;
    }
    free(node);
}

bucket_node_t* add_node(bucket_node_t* node, int val, int* changed)
{
    *changed = FAIL_VAL;
    if (node == NULL)
    {
        bucket_node_t* new_node = create_bucket_node();
        new_node->val = val;
        *changed = SUCCESS_VAL;
        return new_node;
    }

    bucket_node_t* it = node;
    while (it->next != NULL) // no duplicate values
    {
        if (it->val == val) return node;
        it = it->next;
    }
    if (it->val == val) return node;
    it->next = create_bucket_node();
    it->next->val = val;
    it->next->prev = it;
    *changed = SUCCESS_VAL;
    return node;
}

bucket_node_t* remove_node(bucket_node_t* node, int val, int* changed)
{
    *changed = FAIL_VAL;
    bucket_node_t* it = node;
    while (it != NULL)
    {
        if (it->val == val)
        {
            *changed = SUCCESS_VAL;
            if (it->prev == NULL) // head node 
            {
                if (it->next == NULL) // head node and tail node 
                {
                    destroy_bucket_node(it);
                    return NULL;
                }
                it = it->next;
                it->prev->next = NULL;
                destroy_bucket_node(it->prev);
                it->prev = NULL;
                return it;
            } 
            else if (it->next == NULL) // tail node (and not head node)
            {
                it->prev->next = NULL;
                destroy_bucket_node(it);
                return node;
            }
            else // body node
            {
                bucket_node_t* target = it;
                it = it->prev;
                it->next = it->next->next;
                if (it->next != NULL) it->next->prev = it;
                target->next = NULL;
                target->prev = NULL;
                destroy_bucket_node(target);
                return node;
            }
        }
        else it = it->next;
    }

    return node;
}

void resize_hashset(hashset_t* set);

hashset_t* create_hashset()
{
    hashset_t* set = malloc(sizeof(set));
    set->arr = malloc(sizeof(bucket_node_t*) * DEFAULT_SIZE);
    set->cap = DEFAULT_SIZE;
    set->size = 0;

    return set;
}

void destroy_hashset(hashset_t* set)
{
    if (set == NULL) return;
    
    for (int i = 0; i < set->cap; i++)
    {
        if (set->arr[i] != NULL) destroy_bucket_node(set->arr[i]);
    }

    free(set);
}

void printhashset(hashset_t* set)
{
    printf("\n-----------------------------\n");
    printf("HashSet max capacity: %d\nHashSet size: %d\n", set->cap, set->size);
    printf("\nHashSet bucket contents:\n");
    for (int i = 0; i < set->cap; i++)
    {
        printf("Bucket %d: ", i);
        if (set->arr[i] == NULL) printf("EMPTY\n");
        else 
        {
            bucket_node_t* it = set->arr[i];
            while (it != NULL) 
            {
                printf("%d ", it->val);
                it = it->next;
            }
            printf("\n");
        }
    }
    printf("\n----------------------------\n");
}

unsigned int hash_func(unsigned int x)
{
    x = ((x >> 16) ^ x) * HASHING_CONST32;
    x = ((x >> 16) ^ x) * HASHING_CONST32;
    x = (x >> 16) ^ x;
    
    return x;
    // return (x * KNUTH_HASH_CONST) % (unsigned int) 0xFFFFFFFF; 
}

int hashset_add(hashset_t* set, int val)
{
    unsigned int idx = hash_func(val) % set->cap;
    int ret_val;

    set->arr[idx] = add_node(set->arr[idx], val, &ret_val);
    if (ret_val == SUCCESS_VAL) set->size++;

    // check if resizing is necessary
    int max_load = set->cap * DEFAULT_L_FACTOR;
    if (set->size > max_load)
    {
        resize_hashset(set);
    }

    return ret_val;
}

int hashset_contains(hashset_t* set, int val)
{
    unsigned int idx = hash_func(val) % set->cap;
    bucket_node_t* it = set->arr[idx];

    while (it != NULL)
    {
        if (it->val == val) return SUCCESS_VAL;
        it = it->next;
    }

    return FAIL_VAL;
}

int hashset_remove(hashset_t* set, int val)
{
    unsigned int idx = hash_func(val) % set->cap;
    int ret_val;
    set->arr[idx] = remove_node(set->arr[idx], val, &ret_val);
    if (ret_val == SUCCESS_VAL) set->size--;

    return ret_val;
}

int hashset_is_empty(hashset_t* set)
{
    if (set->size == 0) return SUCCESS_VAL;
    return FAIL_VAL;
}

void resize_hashset(hashset_t* set)
{
    int old_cap = set->cap; // save old capacity temporarily
    int count = set->size; // DEBUG - save size, check after add to make sure is consistent
    set->cap = next_hashtable_size(set->cap); // update hashset capacity
    set->size = 0;

    bucket_node_t** old_arr = set->arr; // create array pointer for old array
    set->arr = malloc(sizeof(bucket_node_t*) * set->cap); // allocate new array
    

    for (int i = 0; i < old_cap; i++)
    {
        if (old_arr[i] != NULL)
        {
            bucket_node_t* it = old_arr[i];
            while (it != NULL)
            {
                hashset_add(set, it->val);
                it = it->next;
            }
            destroy_bucket_node(old_arr[i]);
        }
    }

    if (count != set->size) printf("ERROR! RESIZE FAILED!");
}

void bubbledown(int* arr, int idx, int to);
void lbubbledown(long* arr, int idx, int to);
void dequeue(int* arr, int from, int to);
void ldequeue(long* arr, int from, int to);
void bubbleup(int* arr, int idx);

heap_t* create_heap(int cap)
{
    heap_t* heap = (heap_t*) malloc(sizeof(heap_t));
    heap->cap = cap;
    heap->arr = malloc(sizeof(int) * cap);
    heap->size = 0;
    
    return heap;
}

void destroy_heap(heap_t* heap)
{
    if (heap == NULL) return;
    free(heap->arr);
    free(heap);
    heap = NULL;
}

void heapify(heap_t* heap)
{
    int* arr = heap->arr;
    int i = heap->size;    
    
    if (i % 2 == 0) i = (i - 2) / 2;
    else i = (i - 1) / 2;

    for ( ; i >= 0; i--)
    {
        bubbledown(arr, i, heap->size);
    }
}

int push(heap_t* heap, int elem)
{
    int size = heap->size;
    int* arr = heap->arr;
    if (size == heap->cap) return 0;

    arr[size] = elem;
    
    bubbleup(arr, size);
    heap->size++;
    return 1;
}

int pop(heap_t* heap)
{
    if (heap_empty(heap)) return 0;
    int* arr = heap->arr;
    int head = arr[0];
    
    heap->size--;
    arr[0] = arr[heap->size];
    arr[heap->size + 1] = 0;
    
    bubbledown(arr, 0, heap->size);

    return head;
}

int peek(heap_t* heap)
{
    if (heap_empty(heap)) return 0;
    else return heap->arr[0];
}

int heap_empty(heap_t* heap)
{
    if (heap->size == 0) return 1;
    else return 0;
}

void heapsort(int* arr, int from, int to)
{
    int i = to;
    
    //heapify array section (min heap)
    if (i % 2 == 0) i = (i - 2) / 2;
    else i = (i - 1) / 2;
    
    for ( ; i >= from; i--)
    {
        bubbledown(arr, i, to);
    }

    // dequeue all elements in the pseudo heap
    while (to >= from)
    {
        dequeue(arr, from, to--);
    }
}

void lheapsort(long* arr, int from, int to)
{
    int i = to;
    
    //heapify array section (min heap)
    if (i % 2 == 0) i = (i - 2) / 2;
    else i = (i - 1) / 2;
    
    for ( ; i >= from; i--)
    {
        lbubbledown(arr, i, to);
    }
    
    //dequeue
    while (to >= from)
    {
        ldequeue(arr, from, to--);
    }
}

void bubbledown(int* arr, int idx, int to)
{
    int i = idx;
    int target;
    int left = idx * 2 + 1;
    int right = idx * 2 + 2;
    if (left <= to && right <= to) {
        if (arr[left] > arr[right]) target = left;
        else target = right;
        if (arr[target] > arr[idx]) i = target;
    }
    else if (left <= to) {
        target = left;
        if (arr[target] > arr[idx]) i = target;
    }
    else if (right <= to) {
        target = right;
        if (arr[target] > arr[idx]) i = target;
    }
    
    if (i != idx)
    {
        int temp = arr[idx];
        arr[idx] = arr[i];
        arr[i] = temp;
        bubbledown(arr, i, to);
    }
}

void bubbleup(int* arr, int idx)
{
    if (idx == 0) return;
    int parent = (idx - 1) / 2;
    
    if (arr[idx] > arr[parent]) 
    {
        int temp = arr[idx];
        arr[idx] = arr[parent];
        arr[parent] = temp; 
        bubbleup(arr, parent);    
    }
}

void lbubbledown(long* arr, int idx, int to)
{
    int i = idx;
    int target;
    int left = idx * 2 + 1;
    int right = idx * 2 + 2;
    if (left <= to && right <= to) {
        if (arr[left] > arr[right]) target = left;
        else target = right;
        if (arr[target] > arr[idx]) i = target;
    }
    else if (left <= to) {
        target = left;
        if (arr[target] > arr[idx]) i = target;
    }
    else if (right <= to) {
        target = right;
        if (arr[target] > arr[idx]) i = target;
    }
    
    if (i != idx)
    {
        int temp = arr[idx];
        arr[idx] = arr[i];
        arr[i] = temp;
        lbubbledown(arr, i, to);
    }
}

void dequeue(int* arr, int from, int to)
{
    if (to <= from) return;

    int temp = arr[to];
    arr[to] = arr[from];
    arr[from] = temp;

    bubbledown(arr, from, --to);
}

void ldequeue(long* arr, int from, int to)
{
    if (to <= from) return;

    int temp = arr[to];
    arr[to] = arr[from];
    arr[from] = temp;

    lbubbledown(arr, from, --to);
}

int csorted(int* arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < arr[i - 1]) return 0;
    }
    return 1;
}

int lcsorted(long* arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < arr[i - 1]) return 0;
    }
    return 1;
}

int binsearch(int* arr, int lower, int upper, int target)
{
    int mid = -1;
    upper++;
    while (lower < upper)
    {
        mid = (lower + upper) / 2;
        if (arr[mid] < target)
        {
            lower = mid + 1;
        }
        else if (arr[mid] > target)
        {
            upper = mid;
        }
        else 
        {
            return mid;
        }
    }

    return -1;
}

int lbinsearch(long* arr, int lower, int upper, long target)
{
    int mid = -1;
    upper++;
    while (lower < upper)
    {
        mid = (lower + upper) / 2;
        if (arr[mid] < target)
        {
            lower = mid + 1;
        }
        else if (arr[mid] > target)
        {
            upper = mid;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int counti(int *arr, int size, int elem)
{
    int count = 0;
    for (int i = 0; i < size; i++) if (elem == arr[i]) count++;
    return count;
}

int countl(long *arr, int size, long elem)
{
    int count = 0;
    for (int i = 0; i < size; i++) if (elem == arr[i]) count++;
    return count;
}

int arr_max(int *arr, int size)
{
    int max = INT_MIN;
    for (int i = 0; i < size; i++) if (arr[i] > max) max = arr[i];
    return max;
}

int arr_min(int *arr, int size)
{
    int min = INT_MAX;
    for (int i = 0; i < size; i++) if (arr[i] < min) min = arr[i];
    return min;
}

void fillasc(int arr[], int size, int val)
{
    int _val = val;
    for (int i = 0; i < size; i++)
    {
        arr[i] = _val++;
    }
}

void filldesc(int arr[], int size, int val)
{
    int _val = val;
    for (int i = 0; i < size; i++)
    {
        arr[i] = _val--;
    }
}

void fill(int arr[], int size, int val)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = val;
    }
}

void lfillasc(long arr[], int size, long val)
{
    int _val = val;
    for (int i = 0; i < size; i++)
    {
        arr[i] = _val++;
    }
}

void lfilldesc(long arr[], int size, long val)
{
    int _val = val;
    for (int i = 0; i < size; i++)
    {
        arr[i] = _val--;
    }
}

void lfill(long arr[], int size, long val)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = val;
    }
}
