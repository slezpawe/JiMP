#include <stdio.h>
#include <stdlib.h>

int main()
{
    for(int i=0; i<=255; i++)
    {
        printf("Znak: %c, numer: %d\n", (unsigned char)i, i);
    }
}
