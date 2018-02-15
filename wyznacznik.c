#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));

	int a11 = rand()%11;
	int a12 = rand()%11;
	int a13 = rand()%11;
	int a21 = rand()%11;
	int a22 = rand()%11;
	int a23 = rand()%11;
	int a31 = rand()%11;
	int a32 = rand()%11;
	int a33 = rand()%11;


	printf("| %d\t%d\t%d |\n\n",a11,a12,a13);
	printf("| %d\t%d\t%d |\n\n",a21,a22,a23);
	printf("| %d\t%d\t%d |\n\n",a31,a32,a33);

	int wyznacznik = (a11 * a22 * a33) + (a12 * a23 * a31) + (a13 * a21 * a32)
		- (a13 * a22 * a31) - (a11 * a23 * a32) -(a12 * a21 * a33);
	printf("Wyznacznik tej macierzy jest rowny = %d\n",wyznacznik);
}
