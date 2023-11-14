// PID: 730615143
// I pledge the COMP 211 honor code.

// -----------------------------------
// COMP 211 - Systems Fundamentals
// Fall 2021
// cache.c source file
// 
// Lab 05
//
// -----------------------------------
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "bit_utils.h"
#include "cache.h"
#include "memory.h"

// define start bits and end bits for bitsel ops
#define DM_TAG_START_BIT 7
#define DM_TAG_END_BIT 5
#define DM_LINE_START_BIT 4
#define DM_LINE_END_BIT 2
#define OFFSET_START_BIT 1
#define OFFSET_END_BIT 0
#define FA_TAG_START_BIT 7
#define FA_TAG_END_BIT 2



extern unsigned int* phy_memory;
extern unsigned int* block_location;
extern unsigned int addr_bits;

int block_size = exp2(NUM_BLOCK_OFFSET_BITS); // define block size
cache_line** cache;

void load_block_DM(int line, int tag);
void load_block_FA(int line, int tag);

int initializeCache(unsigned int number_of_lines){
    unsigned int line;
    int ret_val;

    ret_val = OK;

    // Allocate memory for the cache (array of cache lines).
    cache = malloc(sizeof(cache_line*) * number_of_lines);

    // For each cache line, allocate memory and initialize the cache line.
    if(cache != NULL){
        for (line=0; line<number_of_lines; line++){
            cache[line] = (cache_line*) malloc(sizeof(cache_line));
            cache[line]->tag = EMPTY;
            cache[line]->hit_count = ZERO;
        }
    }else
        ret_val = FAIL;

    return ret_val;

} // end initializeCache function


int cread(unsigned int cmf, unsigned int* hex_addr, unsigned int* found, unsigned int* replace){
    // retVal is either FAIL or the value of the requested hexadecimal address.
    // open_line indicates a line that is open, and thus usable.
    // replace_line indicates the cache line that should be replaced (in the direct mapping case).
    // min_hit_cnt is used in the fully associative case, and used to keep track of the LFU cache line.

    int ret_val = FAIL;
    int line, open_line, min_hit_cnt, min_line;

    open_line = EMPTY;
    min_hit_cnt = (int)1E10;
    min_line = 0;

    // tag is the tag bits
    // block_offset is the number of bits into a block the location is (Hint: Need to initialize).
    unsigned int tag, block_offset;

    // Variables to be passed by reference. - we want to indicate to the driver class whether we found the item we wanted in the cache and whether we had to overwrite and replace something
    (*found) = MISS;
    (*replace) = NO;

    if((cmf == DM) && ((*hex_addr) < exp2(addr_bits)))
    {
        tag = bit_select(*hex_addr, DM_TAG_START_BIT, DM_TAG_END_BIT);
        line = bit_select(*hex_addr, DM_LINE_START_BIT, DM_LINE_END_BIT);        
        block_offset = bit_select(*hex_addr, OFFSET_START_BIT, OFFSET_END_BIT); 
        
        if (cache[line]->tag != (int) tag) 
        {
            if (cache[line]->tag != EMPTY) {
                (*replace) = YES;
            }
            load_block_DM(line, tag);
            cache[line]->tag = tag; 
        }
        else 
        {
            (*found) = HIT;
        }
        cache[line]->hit_count++;
        ret_val = cache[line]->block[block_offset];

    }else if((cmf == FA) && ((*hex_addr) < exp2(addr_bits))){
        tag = bit_select(*hex_addr, FA_TAG_START_BIT, FA_TAG_END_BIT);
        block_offset = bit_select(*hex_addr, OFFSET_START_BIT, OFFSET_END_BIT);

        open_line = -1;
        min_line = -1;

        
        for (line = 0; line < NUM_OF_LINES; line++) // check if tag exists, or, if not, what line to replace
        {
            if (cache[line]->tag == (int) tag) 
            { 
                (*found) = HIT;
                break; 
            }
            else if (cache[line]->tag == EMPTY && open_line == -1) 
            {
                open_line = line;
            }
            else if (cache[line]->hit_count < min_hit_cnt)
            {
                min_hit_cnt = cache[line]->hit_count;
                min_line = line;
            }
        }
        
        if ((*found) != HIT) // if we did not get a cache hit, load in block of memory with address 
        {
            if (open_line != -1) {
                load_block_FA(open_line, tag);
                line = open_line;
            }
            else
            {
                load_block_FA(min_line, tag);
                (*replace) = YES;
                line = min_line;
            }
        }
        ret_val = cache[line]->block[block_offset];
        cache[line]->hit_count++; 
    }

    // Print out the state of the cache after the mapping algorithm has been applied.
    cprint();

    return ret_val;

} // end cread function

void cprint() {
    unsigned int line;

    printf("\n---------------------------------------------\n");
    printf("line\ttag\tnum of hits\n");
    printf("---------------------------------------------\n");

    for(line = 0; line < NUM_OF_LINES; line++){ 
        if(cache[line]->tag == EMPTY){
            printf("%d\t%d\t%d\n", line, cache[line]->tag, cache[line]->hit_count);
        }else{
            printf("%d\t%02X\t%d\n", line, cache[line]->tag, cache[line]->hit_count);
        }
    }

} // end cprint function

void load_block_DM(int line, int tag) // load block of memory at address given by tag and line into the corresponding cache
{
    int location = block_location[tag * (int) exp2(NUM_OF_TAG_BITS_DM) + line]; // convert tag and line into address
    for (int i = 0; i < block_size; i++) 
    {
        cache[line]->block[i] = phy_memory[location + i];
    }
    cache[line]->tag = tag;
    cache[line]->hit_count = ZERO;
}

void load_block_FA(int line, int tag) 
{
    int location = block_location[tag];
    for (int i = 0; i < block_size; i++)
    {
        cache[line]->block[i] = phy_memory[location + i];
    }
    cache[line]->tag = tag;
    cache[line]->hit_count = ZERO;
}
