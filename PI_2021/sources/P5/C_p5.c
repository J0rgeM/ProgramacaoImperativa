#include <stdio.h>
#include <math.h>

double converte_euro(double e)
{
    return e / 100;
}

double converte_min(int min)
{   
    return min = min * 60;
}

double conf_meio(int a, int b, int c, int d) //meio da duração do confinamento
{
    return ((converte_min(a)+ b) + (converte_min(c) + d))/2; 
}

int multa(int tempo, double confi)
{
    int preco;
    if(tempo > 60)
    {   
        preco = 60 * 10 * pow(confi,2) + multa(tempo - 60, confi+1);
    }else
    {
        preco = tempo * 10 * pow(confi,2);
    }
    return preco;
}

double recolher_obrigatorio(int a, int b, int c, int d, int e, int f)
{   
    int result;
    if(conf_meio(a,b,c,d) >= (converte_min(e) + f)) //se foi apanhado mais proximo do inicio ou do fim
    {
        result = (converte_min(e) + f) - (converte_min(a) + b); //tempo apanhado menos o inicial para saber o que interessa
    }
    else
    {
        result = (converte_min(c) + d) - (converte_min(e) + f); //tempo final que interessa
    }
    return converte_euro(multa(result, 1));
}

void interact_recolher_obrigatorio(void)
{
    int a; // inicio
    int b;
    int c; // fim
    int d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int e; //apanhado
    int f;
    while(scanf("%d%d", &e, &f) != EOF)
    {
        double result = recolher_obrigatorio( a, b, c, d, e, f);
        printf("%.2f\n", result);
    }
}

int main(void)
{   
    interact_recolher_obrigatorio();
    return 0;
}