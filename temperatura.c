#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void celsjusz_fahrenheit()
{
    double cel;
    printf("Podaj stopnie w skali Celsjusza: ");
    scanf("%lf",&cel);
    
    double fah =(9.0/5.0*cel)+32;
    printf("Stopnie w skali Fahrenheita: %lf\n",fah);
}
void fahrenheit_celsjusz()
{
    double fah;
    printf("Podaj stopnie w skali Fahrenheita: ");
    scanf("%lf",&fah);

    double cel = (5.0/9.0)*(fah-32);
    printf("Stopnie w skali Celsjusza: %lf\n", cel);
}


int main()
{
    int wybor;
    printf("Jakiej zamiany chcesz dokonac: ?\n1. Z stopni Celsjusza na Fahrenheita\n2. Z stopni Fahrenheita na Celsjusza\n");
    scanf("%d",&wybor);
    switch(wybor)
    {
        case 1:
            celsjusz_fahrenheit();
            break;
        case 2:
            fahrenheit_celsjusz();
            break;
	default:
	    printf("Nie ma takiej opcji w menu\n");
	    break;
    }
}
