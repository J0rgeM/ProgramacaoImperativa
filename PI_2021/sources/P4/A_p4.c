#include <stdio.h>
#include <math.h>
// 1km = 0.087€
//310km -> 27€  310*0.087 = 26.97 = 27
//95km -> 8.5€ 95*0.087 = 8.265 = 8.50
const double km = 0.087;
const double desconto = 0.85;

double ida(int x)
{
    return ceil((x * km) * 2 ) /2;
}

double ida_e_volta(int x)
{
    return ceil(ida(x) * 2 * desconto * 2 ) / 2;
}

void interact_ticket(void)
{
    int x;
    while(scanf("%d", &x) != EOF)
    {
        double result_ida = ida(x);
        double result_ida_e_volta = ida_e_volta(x);
        printf("%.2f %.2f\n", result_ida, result_ida_e_volta);
    }
}

int main(void)
{   
    interact_ticket();
    return 0;
}