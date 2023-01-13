#include <stdio.h>
#include <math.h>

const double desconto_20 = 0.8;

int promo(int unidades)
{
    int result = unidades / 3;
    return unidades - result;
}
double azeite(double preco, double litros, int unidades)
{
    return round((preco * desconto_20 * promo(unidades)) / (litros * unidades) * 100) / 100;
}

void interact_azeite(void)
{
    double x,y;
    int z;
    while(scanf("%lf%lf%d", &x,&y,&z) != EOF)
    {
        double result = azeite(x,y,z);
        printf("%f\n", result);
    }
}

int main(void)
{   
    interact_azeite();
    return 0;
}