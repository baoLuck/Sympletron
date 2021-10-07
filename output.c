#define NUM_OF_LINES 100
#define NUM_OF_COLUMNS 10

void output(int m[][NUM_OF_COLUMNS], int acc, int instrCounter, int instrReg, int opCode, int memCell)
{
    int i, k;

    printf("\n---------------------------------------------------------\n"
           "\nREGISTERS:\n%-21s%d\n%-21s%d\n%-21s%d\n%-21s%d\n%-21s%d\n\nMEMORY:\n %10s",
           "accumulator", acc, "instructionCounter", instrCounter,
           "instructionRegister", instrReg, "operationCode", opCode, "operand", memCell, "  |         0|");
    for (i = 1; i < NUM_OF_COLUMNS; i++)
        printf("%10d|", i);

    for (k = 0; k < NUM_OF_LINES; k += 1) {
        printf("\n");
        for (i = 1; i <= 114; i++)
            printf("-");
        printf("\n%3d|", k * NUM_OF_COLUMNS);
        for (i = 0; i < NUM_OF_COLUMNS; i++)
            if (m[k][i] >= 0)
                printf(" %9d|", m[k][i]);
            else
                printf(" %9d|", m[k][i]);
    }
    printf("\n");
    getchar();
}
