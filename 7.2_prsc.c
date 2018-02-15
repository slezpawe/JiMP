#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void print(int n, ...)
{
    int count=0;
    char *ptr;
    va_list vl;
    
    int input;

    va_start(vl, n);
    while(count<n)
    {
        ptr=va_arg(vl, char*);
	if(strcmp(ptr, "%d")!=0)
      	    printf("%s ", ptr);
	else
	{
	    scanf("%d",&input);	
	}
	count++;    
    }

    va_end(vl);
}

int main()
{
    print(8, "Podaj", "bok", "a:", "%d", "Podaj", "bok", "b:", "%d");
    return 0;
}
