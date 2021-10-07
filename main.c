#include <stdio.h>
#include <stdlib.h>
#include "greeting.h"
#include "commands.h"
#include "commandrec.c"
#include "execution.c"
#include "output.c"

#define NUM_OF_LINES 100
#define NUM_OF_COLUMNS 10

void greeting();
void commands();
void commandRecord(int [][NUM_OF_COLUMNS]);
void execution(int [][NUM_OF_COLUMNS], int [][NUM_OF_COLUMNS], int , int , int , int , int);
void output(int [][NUM_OF_COLUMNS], int , int , int , int , int );

int main()
{
    char a;
    int memory[NUM_OF_LINES][NUM_OF_COLUMNS] = { {0} }, memorySafe[NUM_OF_LINES][NUM_OF_COLUMNS] = { {0} };
    int accumulator = 0, instructionCounter = 0, instructionRegister = 0,
        operationCode = 0, memoryCell = 0;

    greeting();
    commands();
    commandRecord(memorySafe);
    execution(memorySafe, memory, accumulator, instructionCounter, instructionRegister, operationCode, memoryCell);
    a = getchar();
    return 0;
}
