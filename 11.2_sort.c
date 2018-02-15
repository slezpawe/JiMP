#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void display_tab(int *od, int *doo)
{
     for(; od<doo; ++od)
         printf("%d\n", *od);
}

int counting_lines(char const *name)
{
    FILE *file = fopen(name, "r");

    if(file==NULL)
    {
        printf("Nie udalo sie otworzyc pliku");
	getchar();
	exit(1);
    }

    char line[255];
    int number_of_lines = 0;
    while(fgets(line, 250, file)!=NULL)
        ++number_of_lines;
    fclose(file);

    return number_of_lines;
}

void sort(int tab[], int num)
{
     int cubby, k;

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
	 tab[k+1] = cubby;
     }
}

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Nie podano nazwy pliku do otwarcia!\n");
	exit(1);
    }
    char const *name1 = argv[1];


    int number_of_lines = counting_lines(name1); 
    int tab[number_of_lines];

    FILE *file = fopen(name1, "r");
    char line[255];
    for(int i=0; i<number_of_lines; i++)
    {
        fgets(line, 250, file);
	tab[i] = (int)strtol(line, NULL, 10);
    }

    fclose(file);
    sort(tab, number_of_lines);

    if(argc == 2)
        display_tab(tab, tab+number_of_lines);
    else{
        char const *name2 = argv[2];
        file = fopen(name2, "w");
        fprintf(file, "%d", tab[0]);
        fclose(file);

        file = fopen(name2, "a");
        for(int i=1; i<number_of_lines; i++)
        {
            fprintf(file, "\n");
   	    fprintf(file, "%d", tab[i]);
        }
        fclose(file);
    }
}
