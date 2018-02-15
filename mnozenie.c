#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int losowanie()
{
    srand(time(NULL));

    int a = rand() % 201 - 100 ;

    return a;
}

void laczenie(int tab1[2][2], int tab2[2][2], int tab[2][2][2])
{
    tab[0][0][0]=tab1[0][0];
    tab[0][0][1]=tab1[0][1];
    tab[0][1][0]=tab1[1][0];
    tab[0][1][1]=tab1[1][1];

    tab[1][0][0]=tab1[0][0];
    tab[1][0][1]=tab1[0][1];
    tab[1][1][0]=tab1[1][0];
    tab[1][1][1]=tab1[1][1];
      
}

void mnozenie(int tab[2][2][2])
{
    int wymnozona[2][2];
    wymnozona[0][0] = tab[0][0][0] * tab[1][0][0] + tab[0][0][1] * tab[1][1][0];
    wymnozona[0][1] = tab[0][0][0] * tab[1][0][1] + tab[0][0][1] * tab[1][1][1];

    wymnozona[1][0] = tab[0][1][0] * tab[1][0][0] + tab[0][1][1] * tab[1][1][0];
    wymnozona[1][1] = tab[0][1][0] * tab[1][0][1] + tab[0][1][1] * tab[1][1][1];
    
    printf("|%d   %d|\n", wymnozona[0][0], wymnozona[0][1]);
    printf("|%d   %d|\n", wymnozona[1][0], wymnozona[1][1]);

}

int main()
{
    int macierz1[2][2];
    int macierz2[2][2];
    macierz1[0][0] = losowanie();
    macierz1[0][1] = losowanie();
    macierz1[1][0] = losowanie();
    macierz1[1][1] = losowanie();

    macierz2[0][0] = losowanie();
    macierz2[0][1] = losowanie();
    macierz2[1][0] = losowanie();
    macierz2[1][1] = losowanie();
    
    int polaczona[2][2][2];
    laczenie(macierz1, macierz2, polaczona);
    printf("|%d   %d| |%d   %d|\n",macierz1[0][0], macierz1[0][1], macierz2[0][0], macierz2[0][1]);
    printf("|%d   %d| |%d   %d|\n\n",macierz1[1][0], macierz1[1][1], macierz2[1][0], macierz2[1][1]);
    printf("Wynik z mnozenia powyzszych macierzy: \n");
    
    mnozenie(polaczona);

}
