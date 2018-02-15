#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void stopnie_na_radiany()
{
    double stopnie = 0;
    printf("Podaj stopie: ");
    scanf("%lf",&stopnie);
    
    double radiany = stopnie*M_PI/180;
    printf("Radiany: %lf\n",radiany);
}
void radiany_na_stopnie()
{
    double radiany = 0;
    printf("Podaj radiany: ");
    scanf("%lf",&radiany);
    double stopnie = radiany*180/M_PI;
    printf("Stopnie: %lf\n",stopnie);
}


int main()
{
    int wybor;
    printf("Co chcesz policzyc: ?\n1. Stopnie na radiany\n2. Radiany na stopnie\n");
    scanf("%d",&wybor);
    switch(wybor)
    {
        case 1:
            stopnie_na_radiany();
            break;
        case 2:
            radiany_na_stopnie();
            break;
        default:
	    printf("Nie ma takiej opcji\n");
    }
}
