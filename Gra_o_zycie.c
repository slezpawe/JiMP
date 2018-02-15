#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define arrayWidth 50
#define arrayHeight 50
#define revivalChance 1
#define programCycles 1000

int readProbability();
void generateTable(int tab[][arrayWidth]);
void drawTable(int tab[][arrayWidth]);
void lifeCycle(int tab[][arrayWidth]);
int countLivingNeighbours(int tab[][arrayWidth], int i, int j);
void maybeRevive(int tab[][arrayWidth], int i, int j);
void checkBorders(int i, int j);
int aliveCells(int tab[][arrayWidth]);
void writeTofile(int aliveCells, int i);


int main() {

    int gameTable[arrayWidth][arrayHeight];
    int aliveCells;

    generateTable(gameTable);
    drawTable(gameTable);

    int i;
    for (i = 0; i < programCycles; i++) {
        Sleep(200);
        system("cls");
        lifeCycle(gameTable);
        drawTable(gameTable);
        aliveCells = countAlive(gameTable);
        writeTofile(aliveCells, i);

    }

    return 0;
}

void writeTofile(int aliveCells, int i) {
    FILE *fp;
    if ((fp=fopen("wynik.txt", "ab+")) == NULL) {
        printf("Nie mozna otworzyc pliku");
        exit(1);
    }
    fprintf(fp, "Test #%d Komorki zywe: %d\r\nKomorki martwe: %d\r\n", i,aliveCells, arrayHeight * arrayWidth - aliveCells);
}

void lifeCycle(int tab[][arrayWidth]) {
    int i,j;

    int newTable[arrayWidth][arrayHeight];
    for (i = 0; i < arrayHeight; i++) {
        for (j = 0; j < arrayWidth; j++) {
                newTable[i][j] = tab[i][j];
        }
    }

    int livingNeighbours;
    int deadNeighbours;

    for (i = 0; i < arrayHeight; i++) {
        for (j = 0; j < arrayWidth; j++) {
            livingNeighbours = countLivingNeighbours(tab, i, j);
            deadNeighbours = 8 - livingNeighbours;

            if ((tab[i][j] == 1) && ((livingNeighbours == 3) || (livingNeighbours == 2)))
                continue;
            else if (tab[i][j] == 1)
                newTable[i][j] = 0;

            else if ((tab[i][j]) == 0 && (livingNeighbours == 3))
               newTable[i][j] = 1;

            if (newTable[i][j] == 0)
                maybeRevive(newTable, i , j);
        }
    }

    for (i = 0; i < arrayHeight; i++) {
        for (j = 0; j < arrayWidth; j++) {
                tab[i][j] = newTable[i][j];
        }
    }
}

void maybeRevive(int tab[][arrayWidth], int i, int j) {
    if ((rand() % 10000) < revivalChance)
        tab[i][j] = 1;
}

int countLivingNeighbours(int tab[][arrayWidth], int i, int j) {
    int counter = 0;
    int k, l;

    k = i - 1;
    l = j - 1;
    checkBorders(&k, &l);
    if( tab[k][l] == 1)
        counter++;

    k = i - 1;
    l = j;
    checkBorders(&k, &l);
    if (tab[k][l] == 1)
        counter++;

    k = i - 1;
    l = j + 1;
    checkBorders(&k, &l);
    if (tab[k][l] == 1)
        counter++;

    k = i;
    l = j - 1;
    checkBorders(&k, &l);
    if (tab[k][l] == 1)
        counter++;

    k = i;
    l = j + 1;
    checkBorders(&k, &l);
    if (tab[k][l] == 1)
        counter++;

    k = i + 1;
    l = j - 1;
    checkBorders(&k, &l);
    if (tab[k][l] == 1)
        counter++;

    k = i + 1;
    l = j;
    checkBorders(&k, &l);
    if (tab[k][l] == 1)
        counter++;

    k = i + 1;
    l = j + 1;
    checkBorders(&k, &l);
    if (tab[k][l] == 1)
        counter++;

    return counter;
}

void checkBorders(int i, int j) {
    if (i < 0)
        i = arrayHeight - 1;
    else if (i >= arrayHeight)
        i = 0;

    if (j < 0)
        j = arrayWidth - 1;
    else if (i >= arrayWidth)
        j = 0;
}

int readProbability() {
    printf("Podaj poczatkowe prawdopodobienstwo powstania komorki(liczba od 1 do 99): ");
    int p;

    do {
        scanf("%d", &p);
    }while (p > 99 || p < 1);

    printf("\n");

    return p;
}

void generateTable(int table[][arrayWidth]) {
    int probability = readProbability();

    int i,j;

    for (i = 0; i < arrayHeight; i++) {
        for (j = 0; j < arrayWidth; j++) {

            if ((rand() % 100) < probability)
                table[i][j] = 1;
            else
                table[i][j] = 0;
        }
        printf("\n");
    }
}

void drawTable(int tab[][arrayWidth]) {
    int i, j;

    for (i = 0; i < arrayWidth; i++) {
        printf("-");
    }

    printf("\n");

    for (i = 0; i < arrayHeight; i++) {
        printf("|");
        for (j = 0; j < arrayWidth; j++) {
            if(tab[i][j] == 1)
                printf("0");
            else
                printf(" ");
        }
        printf("|\n");
    }

    for (i = 0; i < arrayWidth; i++) {
        printf("-");
    }
}

int countAlive(int tab[][arrayWidth]) {
    int i, j;
    int living = 0;

    for (i = 0; i < arrayHeight; i++) {
        for (j = 0; j < arrayWidth; j++) {
            if (tab[i][j] == 1)
                living++;
        }
    }

    return living;
}

