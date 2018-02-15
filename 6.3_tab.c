#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void losowanie(int tab[], int rozmiar)
{
    srand(time(NULL));
    for(int i=0; i<rozmiar; i++)
    {
        tab[i]=rand()%100+1;
    }
}

void wyswietl(int *od, int *doo)
{
    printf("Wyswietlanie wartosci: \n");
    for(; od<doo; ++od)
    {
        printf("%d\n",*od);
    }
}

void srednia_liczb(int *od, int *doo)
{
    int suma=0;
    double srednia;
    for(; od<doo; ++od)
    {
        suma+=*od;
    }
    srednia = (double)suma/(double)10;
    printf("Srednia = %lf \n",srednia);
}

void swap(int tab[], int a, int b)
{
    int schowek=0; 
    schowek=tab[a];
    tab[a]=tab[b];
    tab[b]=schowek;
}

void sortowanie(int tab[], int rozmiar)
{
    int zmiana=0;
    do
    {
        zmiana=0;
	for(int i=0; i<rozmiar-1; ++i)
	{
	    if(tab[i]>tab[i+1])
	    {
	        zmiana+=1;
		swap(tab, i, i+1);
	    }
	}
    }while(zmiana!=0);
}

void mediana(int *od)
{
    double mediana=(*(od+4)+*(od+5))/2.0;
    printf("Mediana = %lf\n",mediana);
}

void minimalna_maksymalna(int *od, int *doo)
{
    int min=*od;
    int maks=*od;
    for(; od<doo; ++od)
    {
        if(*od<min)
	{
	    min=*od;
	}
	else if(*od>maks)
	{
	    maks=*od;
	}
    }
    printf("Najmniejsza wartosc z tablicy = %d\n", min);
    printf("Najwieksza wartosc z tablicy = %d\n",maks);
}

int main(void)
{
    int tab[10];
    const int rozmiar = sizeof(tab)/sizeof(tab[0]);
    
    for(int i=1; i<=5; ++i)
    {
        switch(i)
	{	
	    case 1: 
		losowanie(tab, rozmiar);
                break;
            case 2: 
		wyswietl(tab, tab+rozmiar);
		break;
	    case 3: 
		srednia_liczb(tab, tab+rozmiar);
		break; 
	    case 4: 
		sortowanie(tab, rozmiar);
		mediana(tab);
		break;
            case 5: 
		minimalna_maksymalna(tab, tab+rozmiar);
		break;
            default: 
		exit(0);
		break;
        }
    }        
}
