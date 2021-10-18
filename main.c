#include <stdio.h>
#include <stdlib.h>
#include "methods.h"

int main()
{
    char a;
    int memorySafe[NUM_OF_LINES][NUM_OF_COLUMNS] = { {0} };
    int accumulator = 0, instructionCounter = 0,
        operationCode = 0, memoryCell = 0;

    greeting();
    commandRecord(memorySafe);
    execution(memorySafe, accumulator, instructionCounter, operationCode, memoryCell);
    a = getchar();
    return 0;
}
