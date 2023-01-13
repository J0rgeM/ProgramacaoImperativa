#include <stdio.h>

double sum_squares_from(double x, int n)
{
    return n == 0 ? 0 : x * x + sum_squares_from(x+1, n-1);
}

void interact_sum_squares_from(void)
{
	double x;
    int n;
    while (scanf("%lf%d", &x, &n) != EOF)
    {
        double result = sum_squares_from(x, n);
        printf("%lf\n", result);
    }  
}

int main(void)
{
    interact_sum_squares_from();
    return 0;
}