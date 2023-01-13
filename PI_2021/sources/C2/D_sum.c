#include <stdio.h>

double a_progression (double x, double r , int n)

{
	return n == 0 ? 0 :
	x + a_progression(x + r,r,n-1);
}



int main(void)
{
	double x;
	double r;
	int n;
	while (scanf("%lf%lf%d", &x, &r, &n) != EOF)
	{
		double res= a_progression(x,r,n);
		printf("%f\n", res );
	}

}