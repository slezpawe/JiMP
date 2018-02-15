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
        printf("%d\n", *od);
    }
}

void wyswietlPosortowana(int **od, int **doo)
{
    for(; od<doo; od++)
    {
        printf("%d\n", **od);
    }
}

void zamien(int **od, int **doo)
{
    int zmiana;
    int **schowek;

    do
    {
        zmiana=0;
	for(int **i=od; i<doo; i++)
	{
	    if(**i>**(i+1))
	    {
	        zmiana=zmiana+1;
		*schowek=*i;
		*i=*(i+1);
		*(i+1)=*schowek;
	    }
	}
    }while(zmiana!=0);
}

int main()
{
    int A[10];
    const int rozmiar=sizeof(A)/sizeof(A[0]);
    srand(time(NULL));
    losowanie(A, A+rozmiar);
    printf("Zawartosc tablicy A przed losowaniem: \n");
    wyswietl(A, A+rozmiar);
    int *B[10];
    for(int i=0; i<rozmiar; i++)
    {
        B[i]=(A+i);
    }
    
    zamien(B, B+rozmiar-1);
    printf("Posortowana tablica w tablicy wskaznikow B : \n");
    wyswietlPosortowana(B, B+rozmiar);
    
    printf("Zawartosc tablicy A po sortowaniu: \n");
    wyswietl(A, A+rozmiar);
}
