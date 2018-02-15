#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void losowanie(int *od, int *doo)
{
    for(; od<doo; od++)
    {
        *od=rand()%100+1;
    }
}

void wyswietl(int *od, int *doo)
{
    for(; od<doo; od++)
    {
        printf("%d\n",*od);
    }
}

void srednia_wazona(int *od, int *doo)
{
    int i=0;
    int suma=0;
    int suma_wag=0;

    for(; od<doo; od++)
    {
        suma=suma+(*od*i);	    
        suma_wag+=i;
	i++;
    }
    printf("Srednia wazona elementow tablicy = %lf\n", (double)suma/suma_wag);
}

int main(void)
{
    int tab[10];
    const int rozmiar=sizeof(tab)/sizeof(tab[0]);
    srand(time(NULL));
    losowanie(tab, tab+rozmiar);
    wyswietl(tab, tab+rozmiar);
    srednia_wazona(tab, tab+rozmiar);
}
