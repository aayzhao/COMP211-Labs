// PID: 730615143
// I pledge the COMP 211 honor code.
#include <stdint.h>
#include <stdlib.h>

#include "bit_utils.h"
#include "instructions.h"

// ------------------------------------
// Function implementation that determines whether you are
// working with an R type or I type instruction
//
// Arguments:	an unsigned 32-bit integer
//
// Return:      instruction_type: R_TYPE or I_TYPE (see instructions.h)
//
#define NOT_I_CASE1 0b00001 // i-type instructions cannot have 00001X as the opcode 
#define NOT_I_CASE2 0b0100  // i-type instructions cannot have 0100XX as the opcode
#define CASE1_END_BIT 27    // ending bit of the first case        
#define CASE2_END_BIT 28    // ending bit of the second case
instruction_type get_type_of_instruction(uint32_t instruct){
    // check for R type instruction
    if (bit_select(instruct, OPCODE_START_BIT, OPCODE_END_BIT) == R_TYPE_OPCODE) return R_TYPE;
    else if (bit_select(instruct, OPCODE_START_BIT, CASE1_END_BIT) != NOT_I_CASE1 
             && bit_select(instruct, OPCODE_START_BIT, CASE2_END_BIT) != NOT_I_CASE2) return I_TYPE; // check for I type instruction
    else return -1; // some instruction type we don't know, return -1

} // end get_type_of_instruction() function

// ------------------------------------
// Function implementation that creates an R-type instruction
// based on the integer given (see instructions.h)
//
// Arguments:	an unsigned 32-bit integer
//
// Return:      a pointer to an r_instruction (see instructions.h).
//              This consists of the following structure members
//              you will have to set: rs, rt, rd, shamt, func
//
r_instruction* create_r_instruction(uint32_t instruct){
    r_instruction* r_instruct = malloc(sizeof(r_instruction)); // allocate struct on heap memory

    // set each part of r_instruct 
    r_instruct->rs = bit_select(instruct, RS_START_BIT, RS_END_BIT);
    r_instruct->rt = bit_select(instruct, RT_START_BIT, RT_END_BIT);
    r_instruct->rd = bit_select(instruct, RD_START_BIT, RD_END_BIT);
    r_instruct->shamt = bit_select(instruct, SHAMT_START_BIT, SHAMT_END_BIT);
    r_instruct->func = bit_select(instruct, FUNC_START_BIT, FUNC_END_BIT);

    return r_instruct; // return pointer to struct
} // end create_r_instruction() function

// ------------------------------------
// Function implementation that creates an I-type instruction
// based on the integer given (see instructions.h)
//
// Arguments:	an unsigned 32-bit integer
//
// Return:      a pointer to an i_instruction (see instructions.h).
//              This consists of the following structure members
//              you will have to set: opcode, rs, rt, immediate
//
i_instruction* create_i_instruction(uint32_t instruct){
    i_instruction* i_instruct = malloc(sizeof(i_instruction)); // allocate struct on heap memory
    
    // set each part of i_instruct
    i_instruct->opcode = bit_select(instruct, OPCODE_START_BIT, OPCODE_END_BIT);
    i_instruct->rs = bit_select(instruct, RS_START_BIT, RS_END_BIT);
    i_instruct->rt = bit_select(instruct, RT_START_BIT, RT_END_BIT);
    i_instruct->immediate = bit_select(instruct, IMMEDIATE_START_BIT, IMMEDIATE_END_BIT);

    return i_instruct; // return pointer to struct
} // end create_i_instruction() function
