// 60 min ou menos = 10 cen por minuto 61-120 paga a primeira hora e o restante a 40 por min 12-180 90 por min
#include <stdio.h>
#include <math.h>

double cvrt_euro(double a) // euros
{
    return a/100;
}

double cvrt(int a) //horas pa minutos
{
    return a = a*60;
}

double calc_meio(int a, int b, int c, int d) //meio da duração do confinamento
{
    return ((cvrt(a)+ b) + (cvrt(c) + d))/2; 
}

int calc_price(int tempo, double a)
{
    int price;
    if (tempo > 60)
    {
        price = 60 * 10 * pow(a,2) + calc_price(tempo-60,a+1);
    }
    else
    {
        price = tempo * 10 * pow(a,2);
    }
    return price;
}

double calc( int a, int b, int c, int d, int e, int f)
{
    int tmp_infra;
    if (calc_meio(a,b,c,d) >= (cvrt(e)+f)) // saber se ele foi apanhado mais proximo do inicio ou do fim
    {
        tmp_infra = (cvrt(e)+f)-(cvrt(a)+b); // tempo que foi apanhado menos o inicial para saber quanto tempo me interessa
    }
    else
    {
        tmp_infra = (cvrt(c)+d) - (cvrt(e)+f); // tempo final tempo que interessa
    }
    return cvrt_euro(calc_price(tmp_infra,1));
}

void test(void)
{
    int a; // inicio
    int b;
    int c; // fim
    int d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int e; //apanhado
    int f;
    while (scanf("%d%d", &e , &f) != EOF)
    {
        double result = calc( a, b, c, d, e, f);
        printf("%.2f\n", result);
    }
}

int main(void)
{
    test();
    return 0;
}