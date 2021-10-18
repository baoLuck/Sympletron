#ifndef METHODS_H
#define METHODS_H

/*
 * The size of memory
 */
#define NUM_OF_LINES    10
#define NUM_OF_COLUMNS  10

/*
 * Types of command input
 */
#define FROM_KEYBOARD   1
#define FROM_FILE       2

void greeting();
void commandRecord(int [][NUM_OF_COLUMNS]);
void execution(int [][NUM_OF_COLUMNS], int , int , int , int);
void output(int [][NUM_OF_COLUMNS], int , int , int , int );

#endif
