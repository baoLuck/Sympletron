#define NUM_OF_LINES 100
#define NUM_OF_COLUMNS 10

enum operations {
    inputWord = 10,
    outputWord = 11,
    putToAcc = 20,
    outputFromAcc = 21,
    addition = 30,
    subtracting = 31,
    multiplying = 32,
    halt = 43
};

void commandRecord(int a[][NUM_OF_COLUMNS])
{
    int command = 0, checkCommand = 0, counter = 0, numCol = 0, numLine = 0;

    printf("* Enter your commands one at a time *\n"
           "* 43000 to end entering commands and then -99999 to start program execution *\n\n");

    while (command != -99999){

        if (counter < 10)
            printf("00%d?  ", counter);
        else if (counter < 100)
            printf("0%d?  ", counter);
        else
            printf("%d?  ", counter);
        scanf("%d", &command);

        if (command != -99999)
            checkCommand = command / 1000;
        else
            checkCommand = -99999;

        switch (checkCommand) {
            case inputWord:
            case outputWord:
            case putToAcc:
            case outputFromAcc:
            case addition:
            case subtracting:
            case multiplying:
            case halt:

                a[numLine][numCol] = command;
                numCol++;
                if (numCol == NUM_OF_COLUMNS) {
                    numLine++;
                    numCol = 0;
                }
                counter++;
                break;

            case -99999:
                printf("\n*** The download of the program has been completed. ***\n"
                       "*** Starting the program execution. ***\n\n");
                break;

            default:
                printf("*  Error! Wrong command! Try again.  *\n");
                break;
        }

    }
}
