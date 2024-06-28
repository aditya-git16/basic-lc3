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

// Main loop
int main(int argc , const char* argv[]){

    // Load Arguements
    if (argc < 2){

        // Show usage string
        printf("lc3 [image-file] ...\n");
        exit(2);
    }

    for (int j=1 ; j < argc ; ++j){
        if(!read_image(argv[j])){
            printf("failed to load image: %s \n" , argv[j]);
            exit(1);
        }
    }

    // Setup

    reg[R_COND] = FL_ZRO;

    // Set PC to starting position
    // 0x3000 is the default

    enum {
        PC_START = 0x3000
    };
    reg[R_PC] = PC_START;

    int running = 1 ;
    while (running)
    {
        // Fetch
        uint16_t instr = mem_read(reg[R_PC]++);
        uint16_t op = instr >> 12;

        switch(op)
        {
            case OP_ADD:
            // logic
            break;
            case OP_AND:
            //logic
            break;
            case OP_NOT:
            // logic
            break;
            case OP_BR:
            // Logic
            break;
            case OP_JMP:
            // Logic
            break;
            case OP_JSR:
            // Logic
            break;
            case OP_LD:
            // Logic
            break;
            case OP_LDI:
            // logic
            break;
            case OP_LDR:
            // logic 
            break;
            case OP_LEA:
            // logic
            break;
            case OP_ST:
            // logic
            break;
            case OP_STI:
            // logic
            break;
            case OP_STR:
            // logic
            break;
            case OP_TRAP:
            // logic
            break;
            case OP_RES:
            case OP_RTI:
            default:
            // Bad Opcode logic
            break;
        } 
    }
    // Shutdown
    
}