#include <stdio.h>
#include <math.h>

double sum_powers_from(double x, int n, double y)
{
	return n == 0 ? 0 : pow(x,y) + sum_powers_from(x-1, n-1, y);
}

double sum_inverses_squares(double n)
{
    return n == 0 ? 0 : sum_powers_from(n,n,-2);
    // soma dos inversos dos quadrados ex: n=3  0 + 1 + 1/4 + 1/9 

}

void interact_sum_inverses_squares(void)
{
    double n;
    while (scanf("%lf", &n) != EOF)
    {
        double result = sum_inverses_squares(n);
        printf("%lf\n", result);
    }  
}

int main(void)
{
    interact_sum_inverses_squares();
    return 0;
}