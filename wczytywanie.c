#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int wczytywanie_liczby()
{
    int calkowita;
    
    do
    {
        scanf("%d",&calkowita);

        if(calkowita<1)
        {
    	    printf("Podana liczba jest za mala.\n");
        }
        else if(calkowita>10)
        {
    	    printf("Podana liczba jest za duza.\n");
        }
    }while(calkowita < 1 || calkowita >10);

    return calkowita;
}

int main()
{
    int calkowita;
    printf("Podaj liczbe calkowita od 1 do 10: ");

    calkowita = wczytywanie_liczby();

    if(calkowita<=5)
    {
        if(calkowita < 3)
	{
	    if(calkowita == 1)
                printf("Liczba rowna sie = 1\n");
	    else
	        printf("Liczba rowna sie = 2\n");
	}
	else if(calkowita == 3)
	    printf("Liczba rowna sie = 3\n");
	else
	{  
	    if(calkowita == 4)
                printf("Liczba rowna sie = 4\n");
	    else
	        printf("Liczba rowna sie = 5\n");
	}
    }
    else 
    {
    
        if(calkowita < 8)
	{
	    if(calkowita == 6)
                printf("Liczba rowna sie = 6\n");
	    else
	        printf("Liczba rowna sie = 7\n");
	}
	else if(calkowita == 8)
	    printf("Liczba rowna sie = 8\n");
	else
	{  
	    if(calkowita == 9)
                printf("Liczba rowna sie = 9\n");
	    else
	        printf("Liczba rowna sie = 10\n");
	}
    }
}
