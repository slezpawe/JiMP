#include <stdio.h>
#include <stdlib.h>
int wczytywanie(int poczatek, int koniec)
{
    int a;

    do{
	scanf("%d",&a);
	if(a < poczatek || a > koniec)
	{
	    printf("Podaj w przedziale od %d do %d\n", poczatek, koniec);
        }

    }while(a < poczatek || a > koniec);

    return a;
}

int porownanie(int tab1[],int tab2[])
{
    if(tab1[0]>tab2[0])
    {
        return 1;
    }
    else if(tab1[0]==tab2[0])
    {
        if(tab1[1]==tab2[1])
        {
	    if(tab1[2]==tab2[2])
	    {
	        return 0;
	    }
	    else if(tab1[2]>tab2[2])
	    {
	        return 1;
	    }
	    else
	    {
	        return -1;
	    }
	}
	else if(tab1[1]>tab2[1])
	{
            return 1;
	}
	else
	{
	    return -1;
	}

    }
    else
    {
        return -1;
    }
}

int main()
{
    printf("Program wypisze -1 gdy pierwsza podana godzina jest wczesniejsza od drugiej,\n "
    "0 gdy godziny sa rowne i 1 gdy pierwsza jest pozniejsza od drugiej\n\n");
	
    int czas1[3];
    int czas2[3];
    printf("Podaj pierwsza godzine: ");
    czas1[0] = wczytywanie(1, 24);

    printf("\nPodaj minute pierwszej godziny: ");
    czas1[1] = wczytywanie(0, 59);
    
    printf("\nPodaj sekunde pierwszej godziny: ");
    czas1[2] = wczytywanie(0, 59);

    printf("Podaj druga godzine: ");
    czas2[0] = wczytywanie(1, 24);

    printf("\nPodaj minute drugiej godziny: ");
    czas2[1] = wczytywanie(0, 59);
    
    printf("\nPodaj sekunde drugiej godziny: ");
    czas2[2] = wczytywanie(0, 59);

    printf("Wynik: %d\n",porownanie(czas1, czas2));
}
