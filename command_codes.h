#ifndef COMMAND_CODES_H
#define COMMAND_CODES_H

#define RESERVE_CELL 00

/*
 * Operations of input/output
 */
#define INPUT_WORD  10
#define OUTPUT_WORD 11

/*
 * Operations with the Accumulator
 */
#define PUT_TO_ACC      20
#define OUTPUT_FROM_ACC 21

/*
 * Arithmetic operations
 */
#define ADDITION    30
#define SUBTRACTING 31
#define MULTIPLYING 32

/*
 * Control transfer operations
 */
#define BRANCH      40
#define BRANCHNEG   41
#define BRANCHZERO  42

/*
 * Interrupt
 */
#define HALT            43
#define START_EXECUTION -99999

#endif
