#include <math.h>
#include <stdio.h>

double a_potencia(double x, double y, int r)

{
	return r == 0 ? 0 : 
	pow(x,y) + a_potencia(x-1,y,r-1);
}

double a_inverso(double x)

{
	return x==0 ? 0:
	a_potencia (x,-1,x);	
	
}



int main(void)
{
	int x;
	while (scanf("%d", &x) != EOF)
	{
		double res= a_inverso(x);
		printf("%lf\n", res );
	}

}