#include <stdio.h>

const int reforma = (66*12) + 4;
const int idade_max = (70*12);
    
int idade_reforma(int a, int m)
{
    // 40*12 = idade reforma   ver idade reforma vai ser igual ou superir idade maximo = 70
}


void interact_idade_reforma(void)
{
    int x,y;
    while(scanf("%d%d%d", &x,&y) != EOF)
    {
        int result = idade_reforma(a,m);
        printf("%f\n", result);
    }
}

int main(void)
{   
    interact_idade_reforma();
    return 0;
}