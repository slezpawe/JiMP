#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int randint()
{
    int random = rand()%1001;
    return random;
}

int char_int(char const *d)
{
    int number = atoi(d);
    return (int)number;
}

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        printf("Nie podano ilosci liczb do wylosowania i nazwy pliku wyjsciowego!\n");
	exit(1);
    }
    srand(time(NULL));

    FILE *file;
    char *name = argv[2];
    int amount = char_int(argv[1]);

    file = fopen(name, "w");
    for(int i=0; i<amount; i++)
    {
        fprintf(file, "%d\n", randint());
    }
    fclose(file);
}
