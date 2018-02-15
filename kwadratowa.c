#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(void)
{
    double a,b,c;
    double delta = 0;

    printf("Podaj wspolczynnik a rownania kwadratowego: ");
    scanf("%lf",&a);

    printf("\nPodaj wspolczynnik b rownania kwadratowego: ");
    scanf("%lf",&b);

    printf("\nPodaj wspolczynnik c rownania kwadratowego: ");
    scanf("%lf",&c);

    if(a == 0)
    {
    	printf("Podane rownanie nie jest rownaniem kwadratowym!\n");
	exit(0);
    }

    delta = b*b - 4*(a*c);

    if(delta<0) printf("\nRownanie nie posiada pierwiastkow.\n");
    else if(delta==0)
    {
        double rozw = (-b)/2*a;
	printf("Rownanie ma jedno rozwiazanie rowne: %lf\n",rozw);
    }
    else
    {
        double pierw = sqrt(delta);
	double rozw1 = (-b-pierw)/(2*a);
	double rozw2 = (-b+pierw)/(2*a);
	printf("Pierwsze rozwiazanie rownania to: %lf\n",rozw1);
	printf("Drugie rozwiazanie rownania to: %lf\n",rozw2);

    }
}
