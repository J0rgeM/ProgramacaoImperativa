#include <stdio.h>

int sum_positive_integers(int n)
{
    return n == 0 ? 0 : n + sum_positive_integers(n-1);
}

int sum_progression(int x0, int r, int n)
{
    return n == 0 ? 0 : sum_positive_integers(n-1) * r + x0 * n;
    //soma dos n primeiros termos da progressão aritmética ex: x0=5,r=2,n=3 5+7+9=21
}

void interact_sum_progression(void)
{
	int x0;
    int r;
    int n;
    while (scanf("%d%d%d", &x0, &r, &n) != EOF)
    {
        int result = sum_progression(x0, r, n);
        printf("%d\n", result);
    }  
}

int main (void)
{
    interact_sum_progression();
    return 0;
}