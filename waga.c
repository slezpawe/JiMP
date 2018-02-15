#include <stdlib.h>
#include <stdio.h>


int wczytywanie(int poczatek, int koniec)
{
    int a;
    do
    {
        scanf("%d",&a);
        if(a < poczatek || a > koniec)
        {
	    printf("Podaj wartosci z przedzialu od %d do %d \n", poczatek, koniec);
	}

    }while(a < poczatek || a > koniec);
    
    return a;
}

void wynik_wazenia(char napis[100])
{

    printf("%s\n", napis);
    printf("jesli waga nie przechyli sie wpisz - 0,\n"
    "jesli przechyli sie na lewo wpisz - 1,\n"
    "jesli przechyli sie na prawo wpisz - 2\n");

    int wazenie2 = wczytywanie(0,2);
    switch (wazenie2)
    {
	case 0:
	{
	    printf("Najciezsza kula jest kula odlozona na bok.\n");
            break;
	}
	case 1:
	{
	    printf("Najciezsza kula jest na lewej szali.\n");
            break;
	}
	case 2:
	{
	    printf("Najciezsza kula jest na prawej szali.\n");
        }
    }
}

int main()
{
    printf("Poloz na kazdej szali po 3 kule i wprowadz do programu nastepujace wartosci:"
    "\n0 - waga sie nie przechylila\n1 - waga sie przechylila\n");
    int wazenie1 = wczytywanie(0,1);
    if(wazenie1 == 0)
    {
        wynik_wazenia("Na wadze nie ma kuli najciezszej.\n Wybierz 2 z pozostałych 3-ech kul,"
	" poloz je na obu szalach, a 3-cia odluz na bok");
    }
    else if(wazenie1 == 1)
    {
        wynik_wazenia("Wybierz 2 z 3-ech kul ktore sa na przechylonej szali i poloz je na obu szalach," 
	" a 3-cia odloz na bok");
    }
}
