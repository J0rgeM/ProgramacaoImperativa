#include <stdio.h>
#include <math.h>

double sum_powers_from(double x, int n, double y)
{
	return n == 0 ? 0 : pow(x,y) + sum_powers_from(x-1, n-1, y);
}

double sum_inverses(double n)
{
    return n == 0 ? 0 : sum_powers_from(n,n,-1);
    // soma dos inversos ex: n=3  0 + 1 + 1/2 + 1/3 

}

void interact_sum_inverses(void)
{
    double n;
    while (scanf("%lf", &n) != EOF)
    {
        double result = sum_inverses(n);
        printf("%lf\n", result);
    }  
}

int main(void)
{
    interact_sum_inverses();
    return 0;
}