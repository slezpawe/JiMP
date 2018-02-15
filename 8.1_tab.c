#include <stdio.h>
#include <stdlib.h>

int sum(int tab[], int num)
{
    int sum = 0;
    for(int i=0; i<num; ++i)
    {
        sum += tab[i];
    }
    return sum;
}

int average(int sum, int num)
{
    return sum/num;
}

void sort(int tab[], int num)
{
    int cubby,k;

    for(int i=1; i<num; i++)
    {
        cubby = tab[i];
	for(k=i-1; k>=0; k--)
	{
	    if(cubby < tab[k])
	    {
	        tab[k+1] = tab[k];
	    }
	    else
	        break;	
	}
	tab[k+1]=cubby;
    }
}

int median(int tab[], int num)
{
    if(num%2!=0)
        return tab[num/2+1];
    else
        return tab[num/2]+tab[num/2+1]; 
}

void mode(int tab[], int num)
{
    int current = tab[0];
    int repeat = 1;
    int repeat_max = 0;
    int flag = 0;
    int mode = current;
    for(int i=1; i<num; ++i)
    {
        if(tab[i]==current)
	   repeat++;
	else
	{
	    if(repeat == repeat_max)
	        flag = 1;
	    else if(repeat>repeat_max)
	    {
                repeat_max = repeat;
                mode = current;
		flag = 0;
	    }
	    current = tab[i];
	    repeat = 1;	
	}
    }   
    
    if(repeat == repeat_max)
	flag = 1;
    else if(repeat > repeat_max)
    {
        repeat_max = repeat;
        mode = current;
        flag = 0;
    }

    if(flag == 1)
	printf("Nie można wyznaczyć dominaty\n");
    else
        printf("Dominata elementow to: %d %x %o\n" , mode, mode, mode);
}

int main(void)
{
    int n;
    printf("Podaj ile liczb chcesz wprowadzic: ");
    scanf("%d", &n);
    if(n < 1)
    {
        printf("Podana wartosc musi byc wieksza od 1!\n");
	exit(0);
    }

    int flag = 0, num = 0, *darray;

    darray = (int *)malloc(n*sizeof(int));
    if(darray == NULL)
    {
        printf("Nie udalo sie przydzielic pamieci!\n");
	exit(0);
    }

    while(num<n && flag !=-1)
    {
        printf("Podaj element numer %d: ", num+1);
        flag = scanf("%d", &darray[num]);
	num++;
    }
    if(flag == -1)
        num--;
    
    if(num == 0)
    {
        printf("Blad wprowadzania\n");
	exit(0);
    }

    int sum_of_elements = sum(darray, num);
    printf("\nSuma elementow wynosi: %d %x %o\n", sum_of_elements, sum_of_elements, sum_of_elements);
    
    int average_of_elements=average(sum_of_elements, num);
    printf("Srednia elementow wynosi: %d %x %o\n", average_of_elements, average_of_elements, average_of_elements);
    sort(darray, num);
    
    int median_of_elements=median(darray, num);
    printf("Mediana elementow to: %d %x %o\n", median_of_elements, median_of_elements, median_of_elements);

    mode(darray, num);
    free(darray);
}
