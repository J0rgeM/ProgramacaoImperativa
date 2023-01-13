#include <math.h>
#include <stdio.h>

double a_progression_quadrados (double x, int r)

{
	return r <= 0 ? 0 : 
	x*x + a_progression_quadrados(x+1,r-1);
}



int main(void)
{
	double x;
	int r;
	while (scanf("%lf%d", &x, &r) != EOF)
	{
		double res= a_progression_quadrados(x,r);
		printf("%f\n", res );
	}

}