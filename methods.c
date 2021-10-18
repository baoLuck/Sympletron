#include <stdio.h>
#include "methods.h"
#include "command_codes.h"

void greeting()
{
    printf("*** Sympletron welcomes you! ***\n"
           "*** Please, enter one command (or data word) at a time.    ***\n"
           "*** Enter the commands in the following way: XXYY,         ***\n"
           "*** where XX - the number of command and YY - the          ***\n"
           "*** address number. I will display the current address and ***\n"
           "*** question mark (?) as a prompt. The word you entered    ***\n"
           "*** will be placed at the specified address. To stop       ***\n"
           "*** entering the program, enter the number -99999.         ***\n"
           "\n\nCOMMANDS:\n"
           "10 - input to memory\n"
           "11 - output to screen\n"
           "20 - put the word to the accumulator\n"
           "21 - output the word from the accumulator\n"
           "30 - add\n"
           "31 - subtract\n"
           "32 - multiply\n"
           "40 - go to address\n"
           "41 - go to address if accumulator less then 0\n"
           "42 - go to address if accumulator equals 0\n"
           "43 - halt\n\n");
}

void commandRecord(int memSafe[][NUM_OF_COLUMNS])
{
    int command = 0, checkCommand = 0, counter = 0, numCol = 0, numLine = 0, checkInputType = 0;
    FILE *fileOfCommands;

    printf("Do you want to enter commands from the keyboard (1) or enter program code from a file (2)?\n? ");
    scanf("%d", &checkInputType);
    while(checkInputType < FROM_KEYBOARD || checkInputType > FROM_FILE) {
        printf("Wrong type of input! Please, try again.\n? ");
        scanf("%d", &checkInputType);
    }
    printf("\n");

    if(checkInputType == FROM_KEYBOARD) {
        printf("* Enter your commands one at a time *\n"
               "* 43000 to end entering commands and then -99999 to start program execution *\n\n");
    }
    else
        fileOfCommands = fopen("commands.txt", "r");

    while (command != START_EXECUTION) {

        if (counter < NUM_OF_COLUMNS)
            printf("0%d? ", counter);
        else
            printf("%d? ", counter);

        if(checkInputType == FROM_KEYBOARD)
            scanf("%d", &command);
        else {
            fscanf(fileOfCommands, "%d", &command);
            printf("%d\n", command);
        }

        if (command != START_EXECUTION)
            checkCommand = command / (NUM_OF_LINES * NUM_OF_COLUMNS);
        else
            checkCommand = START_EXECUTION;

        switch (checkCommand) {
            case RESERVE_CELL:
            case INPUT_WORD:
            case OUTPUT_WORD:
            case PUT_TO_ACC:
            case OUTPUT_FROM_ACC:
            case ADDITION:
            case SUBTRACTING:
            case MULTIPLYING:
            case BRANCH:
            case BRANCHNEG:
            case BRANCHZERO:
            case HALT:

                memSafe[numLine][numCol] = command;
                numCol++;
                if (numCol == NUM_OF_COLUMNS) {
                    numLine++;
                    numCol = 0;
                }
                counter++;
                break;

            case START_EXECUTION:
                printf("\n*** The download of the program has been completed. ***\n"
                       "*** Starting the program execution. ***\n\n");
                break;

            default:
                printf("*  Error! Wrong command! Try again.  *\n");
                break;
        }
    }
    if (checkInputType == FROM_FILE)
        fclose(fileOfCommands);
}

void execution(int memSafe[][NUM_OF_COLUMNS], int acc, int instrCounter, int opCode, int memCell)
{
    int currentLine = 0, currentColumn = 0, userWord, line, column;

    instrCounter = memSafe[0][0];

    while (instrCounter != HALT * NUM_OF_LINES * NUM_OF_COLUMNS) {
        opCode = memSafe[currentLine][currentColumn] / (NUM_OF_LINES * NUM_OF_COLUMNS);
        memCell = memSafe[currentLine][currentColumn] % (NUM_OF_LINES * NUM_OF_COLUMNS);
        line = memCell / NUM_OF_COLUMNS;
        column = memCell % NUM_OF_COLUMNS;

        switch (opCode) {

        case RESERVE_CELL:
            break;

        case INPUT_WORD:
            printf("Enter a word: ");
            scanf("%d", &userWord);
            memSafe[line][column] = userWord;
            break;

        case OUTPUT_WORD:
            printf("\n***   %d   ***\n", memSafe[line][column]);
            break;

        case PUT_TO_ACC:
            acc = memSafe[line][column];
            break;

        case OUTPUT_FROM_ACC:
            memSafe[line][column] = acc;
            break;

        case ADDITION:
            acc += memSafe[line][column];
            break;

        case SUBTRACTING:
            acc -= memSafe[line][column];
            break;

        case MULTIPLYING:
            acc *= memSafe[line][column];
            break;

        case BRANCH:
            currentLine = memCell / NUM_OF_LINES;
            currentColumn = memCell % NUM_OF_LINES - 1;
            break;

        case BRANCHNEG:
            if (acc < 0) {
                currentLine = memCell / NUM_OF_LINES;
                currentColumn = memCell % NUM_OF_LINES - 1;
            }
            break;

        case BRANCHZERO:
            if (acc == 0) {
                currentLine = memCell / NUM_OF_LINES;
                currentColumn = memCell % NUM_OF_LINES - 1;
            }
            break;

        case HALT:
            instrCounter = HALT * NUM_OF_LINES * NUM_OF_COLUMNS;
            break;

        default:
            printf("\n\n");
            break;
        }
        currentColumn++;
        if (currentColumn == NUM_OF_COLUMNS) {
            currentLine++;
            currentColumn = 0;
        }
        instrCounter = memSafe[currentLine][currentColumn];
    }
    output(memSafe, acc, instrCounter, opCode, memCell);
}

void output(int m[][NUM_OF_COLUMNS], int acc, int instrCounter, int opCode, int memCell)
{
    int line, column;

    printf("\n---------------------------------------------------------\n"
           "\nREGISTERS:\n%-21s%d\n%-21s%d\n%-21s%d\n%-21s%d\n\nMEMORY:\n %10s",
           "accumulator", acc, "instructionCounter", instrCounter, "operationCode", opCode, "operand", memCell, "  |         0|");
    for (column = 1; column < NUM_OF_COLUMNS; column++)
        printf("%10d|", column);

    for (line = 0; line < NUM_OF_LINES; line++) {
        printf("\n");
        for (column = 1; column <= 114; column++)
            printf("-");
        printf("\n%3d|", line * NUM_OF_COLUMNS);
        for (column = 0; column < NUM_OF_COLUMNS; column++) {
            if (m[line][column] >= 0)
                printf(" %9d|", m[line][column]);
            else
                printf(" %9d|", m[line][column]);
        }
    }
    printf("\n");
    getchar();
}
