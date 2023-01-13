#include <stdio.h>
#include <math.h>

double calc_preco(int r, int v, double p)
{
	return r <= v ? r * p :
		calc_preco(r - v, v, round(p * 0.90 * 100) / 100) + v * p;
	
}

void cantina(void)
{
	int v = 100;
	double p = 8;
	int r;
	while(scanf_s("%d", &r) != EOF)
	{
		double res = calc_preco(r,v,p);
		printf("%lf\n", res);
	}
}

int main(void)
{
	cantina();
	return 0;
}