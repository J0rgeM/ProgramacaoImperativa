#include <stdio.h>

int sum_positive_integers(int n)
{
    return n == 0 ? 0 : n + sum_positive_integers(n-1);
}

int sum_multiple(int r, int n)
{
    return n == 0 ? 0 : sum_positive_integers(n-1)*r;
}

void interact_sum_multiple (void){
    int x;
    int y;
    while (scanf("%d%d", &y, &x) != EOF){
        int r = sum_multiple(y, x);
        printf("%d\n", r);
    }  
}

int main (void){
    interact_sum_multiple();
    return 0;
}
 