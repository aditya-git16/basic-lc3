// Building the LC-3 VM
// Dependencies
#include <stdio.h>
#include <stdint.h>
#include <signal.h>
/* unix only */
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/termios.h>
#include <sys/mman.h>

// Memory
#define MEMORY_MAX (1 << 16)
uint16_t memory[MEMORY_MAX]; /*65536 locations*/

// Registers 
enum {
    R_R0 = 0,
    R_R1,
    R_R2,
    R_R3,
    R_R4,
    R_R5,
    R_R6,
    R_R7,
    R_PC,
    R_COND,
    R_COUNT
};

// Store registers in an array
uint16_t reg[R_COUNT];

// Conditional flags
enum{
    FL_POS = 1 << 0,
    FL_ZRO = 1 << 1,
    FL_NEG = 1 << 2,
};

// Opcodes
enum{
    OP_BR = 0,
    OP_ADD, // Add
    OP_LD, // Load
    OP_ST, // Store
    OP_JSR, // Jump register
    OP_AND, // Bitwise and
    OP_LDR, // Load register
    OP_STR, // Store register
    OP_RTI, // Unused
    OP_NOT, // Bitwise not
    OP_LDI, // Load direct
    OP_STI, // Store indirect
    OP_JMP, // Jump
    OP_RES, // Reserved(unused)
    OP_LEA, // Load effective address
    OP_TRAP // Execute Trap
};

