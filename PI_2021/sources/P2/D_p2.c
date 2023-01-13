#include <stdio.h>

double sum_progression_dbl(double x0, double r, int n)
{
	return n == 0 ? 0
	: x0 + sum_progression_dbl(x0 + r, r, n-1);
}

void interact_sum_progression(void)
{
	double x0;
    double r;
    int n;
    while (scanf("%lf%lf%d", &x0, &r, &n) != EOF)
    {
        double result = sum_progression_dbl(x0, r, n);
        printf("%lf\n", result);
    }  
}

int main(void)
{
    interact_sum_progression();
    return 0;
}