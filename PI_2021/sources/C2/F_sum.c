#include <math.h>
#include <stdio.h>

double a_potencia(double x, double y, int r)

{
	return r == 0 ? 0 : 
	pow(x,y) + a_potencia(x+1,y,r-1);
}



int main(void)
{
	double x;
	double y;
	int r;
	while (scanf("%lf%lf%d", &x, &y, &r) != EOF)
	{
		double res= a_potencia(x,y,r);
		printf("%f\n", res );
	}

}