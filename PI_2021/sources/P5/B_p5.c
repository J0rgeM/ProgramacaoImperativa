#include <stdio.h>
#include <math.h>

double funcao(int x, int y)
{
 return x < 100 ? x * y:funcao(x/10, y*10);
}

void interact_funcao(void)
{
    int x;
    int y=1;
    while(scanf("%d", &x) != EOF)
    {
        int result = funcao(x,y);
        printf("%d\n", result);
    }
}

int main(void)
{   
    interact_funcao();
    return 0;
}