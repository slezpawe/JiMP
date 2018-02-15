#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/ioctl.h>
#include <math.h>
#include <string.h>

enum ArgumentType {TYPE_CHAR, TYPE_CHAR_PTR, TYPE_INT, TYPE_DOUBLE};

void printSpaces(int spaces)
{
    for(int i=0; i<spaces; i++)
        printf(" ");
}

int doublePrecision(double number)
{
    int precision;
    if((int)(number*100) % 100 == 0)
	precision = 0;
    else if((int)(number*100) % 10 == 0)
	precision = 1;
    else
	precision = 2;
    return precision;
}

void printChar(char arg,  unsigned width)
{
    if(isprint(arg))
    {
        int spaces = width/2;
	printSpaces(spaces);
	printf("%c", arg);
	printSpaces(spaces);
    }
    else
        printf("\n");
}

void printCharPtr(char *arg, unsigned width)
{

    unsigned const length = strlen(arg);
    if(length > width)
	printf("%s\n", arg);
    else
    {
        int spaces = (width-length)/2;
        printSpaces(spaces);
        printf("%s", arg);
        printSpaces(spaces);
    }
}

void printInt(int arg, unsigned width)
{

    unsigned length = log10(arg);
    if(length > width)
        printf("%d\n", arg);
    else
    {
        int spaces = (width - length)/2;
        printSpaces(spaces);
        printf("%d", arg);
        printSpaces(spaces);
    }
}

void printDouble(double arg, unsigned width)
{

    unsigned length = log10(arg);
    int precision = doublePrecision(arg);
    length += precision;
    if(precision>0)
        length += 1;
    if(length > width)
        printf("%lf\n", arg);
    int spaces = (width - length)/2;
    printSpaces(spaces);
    if(precision == 0)
        printf("%.0lf", arg);
    else if(precision == 1)
        printf("%.1lf", arg);
    else
        printf("%.2lf", arg);
    printSpaces(spaces);
}

void printArgumentInTheMiddle(void const *argument, enum ArgumentType type, unsigned width)
{
    if((void*)argument==NULL)
        printf("\n");
    else
    {
        switch(type)
        {
	    case TYPE_CHAR:
		{    
		    char arg = *(char*)argument;
		    printChar(arg, width);
		} break;
	    case TYPE_CHAR_PTR:
		{
		    char *arg = (char*)argument;
		    printCharPtr(arg, width);
		} break;
	    case TYPE_INT:
		{
	            int arg = *(int*)argument;
		    printInt(arg, width);
		} break;
	    case TYPE_DOUBLE:
		{
	            double arg = *(double*)argument;
		    printDouble(arg, width);
                } break;
	    default:
	        printf("Cos poszlo nie tak\n");
	        break;    
        }
    }
}

int main(void)
{
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int const columns = w.ws_col;
    char const letter = 'a';
    char const *lettering = "Jezyki i Metody Programowania";
    int const number = 1000000;
    double const num = 8.013;

    printArgumentInTheMiddle(lettering, TYPE_CHAR_PTR, columns);
    printArgumentInTheMiddle(&number, TYPE_INT, columns);
    printArgumentInTheMiddle(&num, TYPE_DOUBLE, columns);
    printArgumentInTheMiddle(&letter, TYPE_CHAR, columns);
    printArgumentInTheMiddle(NULL, TYPE_INT, columns);
}
