#define NUM_OF_LINES 100
#define NUM_OF_COLUMNS 10

void output(int [][NUM_OF_COLUMNS], int , int , int , int, int);

void execution(int mSafe[][NUM_OF_COLUMNS], int m[][NUM_OF_COLUMNS],
               int acc, int instrCounter, int instrReg, int opCode,
               int memCell)
{
    int i = 0, j = 0, userWord, line, column;

    instrCounter = mSafe[0][0];

    while (instrCounter != -99999) {
        instrReg = instrCounter;
        opCode = mSafe[j][i] / 1000;
        memCell = mSafe[j][i] % 1000;
        if ( (mSafe[j][i] != 4300) && (mSafe[j][i] != 0) )
            m[j][i] = mSafe[j][i];
        i++;
        if (i == NUM_OF_COLUMNS) {
            j++;
            i = 0;
        }
        instrCounter = mSafe[j][i];

        line = memCell / NUM_OF_COLUMNS;
        column = memCell % NUM_OF_COLUMNS;

        switch (opCode) {

        case inputWord:
            printf("Enter a word: ");
            scanf("%d", &userWord);
            m[line][column] = userWord;
            break;

        case outputWord:
            printf("\n***   %d   ***\n", m[line][column]);
            break;

        case putToAcc:
            acc = m[line][column];
            break;

        case outputFromAcc:
            m[line][column] = acc;
            break;

        case addition:
            acc += m[line][column];
            break;

        case subtracting:
            acc -= m[line][column];
            break;

        case multiplying:
            acc *= m[line][column];
            break;

        case halt:
            instrCounter = -99999;
            break;

        default:
            printf("\n\n");
            break;
        }
    }

    output(m, acc, instrCounter, instrReg, opCode, memCell);
}
