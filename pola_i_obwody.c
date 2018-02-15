#include <stdio.h>
#include <math.h>
double prostokat()
{
    
    printf("Co chcesz policzyc?\n1. Pole\n2. Obwod\n");
    int obliczanie;
    scanf("%d",&obliczanie);
    double a, b;
    printf("Podaj bok a: ");
    do{
        scanf("%lf", &a);
	if(a<0)
            printf("Bok musi byc wiekszy od 0\n");
    }while(a<0);

    printf("\nPodaj bok b: ");
    do{
        scanf("%lf", &b);
	if(b<0)
            printf("Bok musi byc wiekszy od 0\n");
    }while(b<0);

    switch(obliczanie)
    {
        case 1: 
        {	
            double pole = a*b;
            printf("Pole wynosi: %lf\n", pole);
            break;
        }
        case 2:	
        {
            double obwod = 2*(a+b);
            printf("Obwod wynosi: %lf\n", obwod);
            break;
        }
        default: 
	{
            printf("Nie wybrales ani pola ani obwodu.\n");
            break;
        }
    }

}

double kwadrat()
{
   
    printf("Co chcesz policzyc?\n1. Pole\n2. Obwod\n");
    int obliczanie;
    scanf("%d",&obliczanie);
    double bok;
    printf("Podaj bok kwadratu: ");
    do{
        scanf("%lf", &bok);
	if(bok<0)
            printf("Bok musi byc wiekszy od 0\n");
    }while(bok<0);

    switch(obliczanie)
    {
        case 1: 
	{
            double pole_kwadratu = bok*bok;
            printf("Pole wynosi: %lf\n", pole_kwadratu);
            break;
        }
        case 2:	
        {
            double obwod_kwadratu = 4*bok;
            printf("Obwod wynosi: %lf\n", obwod_kwadratu);
            break;
        }
        default:
	{
            printf("Nie wybrales ani pola ani obwodu.\n");
            break;
        }
    }
}

double trojkat()
{
    
    printf("Co chcesz policzyc?\n1. Pole\n2. Obwod\n");
    int obliczanie;
    scanf("%d",&obliczanie);
    double c;
    printf("Podaj bok trojkata: ");
    do{
        scanf("%lf", &c);
	if(c<0)
            printf("Bok musi byc wiekszy od 0\n");
    }while(c<0);

    switch(obliczanie)
    {
        case 1: 
        {
            double pole_trojkata = (c*c*sqrt(3))/4;
            printf("Pole wynosi: %lf\n", pole_trojkata);
            break;
        }
        case 2:	
        {
            double obwod_trojkata = 3*c;
            printf("Obwod wynosi: %lf\n", obwod_trojkata);
            break;
        }
        default:
	{	
            printf("Nie wybrales ani pola ani obwodu.\n");
            break;
        }
    }
}

double kolo()
{
    printf("Co chcesz policzyc?\n1. Pole\n2. Obwod\n");
    int obliczanie;
    scanf("%d",&obliczanie);
    double r;
    printf("Podaj promien kola: ");
    do{
        scanf("%lf", &r);
	if(r<0)
            printf("Promien musi byc wiekszy od 0\n");
    }while(r<0);

    switch(obliczanie)
    {
        case 1: 
	{
            double pole_kola = M_PI*r*r;
	    printf("Pole wynosi: %lf\n", pole_kola);
	    break;
	}
        case 2:	
	{
	    double obwod_kola = 2*M_PI*r;
	    printf("Obwod wynosi: %lf\n", obwod_kola);
            break;
        }
        default:
	{
            printf("Nie wybrales ani pola ani obwodu.\n");
	    break;
        }
    }
}

int main()
{
    int figura;
    printf("Jaka figure chcesz liczyc: \n1. Prostokat\n2. Kwadrat\n"
			"3. Trojkat rownoboczny\n4. Kolo\n");
    scanf("%d",&figura);

    switch(figura)
    {
        case 1:
        {
	    prostokat();
            break;	    
	}	
        case 2:	
        {
            kwadrat();
	    break;
	}
	case 3:
        {
            trojkat();
	    break;
	}
        case 4:
        {			
	    kolo();
	    break;	
	}
	default:
	{
	    printf("Nie ma takiej figury w tym kalkulatorze\n");
	}
    }
}
