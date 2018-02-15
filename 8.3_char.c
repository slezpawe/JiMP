#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long copyArgumentAndPrintCharReturningSumOfArguments(void* data, size_t sizeOfData)
{
    char lettering[sizeOfData];
    memcpy(lettering, data, sizeOfData);
    long long sum = 0;
    for(int i=0; i< sizeOfData; i++)
    {
        printf("%x\n", lettering[i]);
        sum += lettering[i];
    }
    return sum;
}

int main(void)
{
    char lettering[255];
    int length;
    printf("Podaj napis: ");
    scanf("%s", lettering);
    printf("Podaj dlugosc: ");
    scanf("%d", &length);
    
    long long sum = copyArgumentAndPrintCharReturningSumOfArguments(lettering, length);
    printf("Suma dziesietnie: %lld\nSuma szesnastkowo: %llx\n", sum, sum);
}
