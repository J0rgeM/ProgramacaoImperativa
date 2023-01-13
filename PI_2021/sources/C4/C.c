#include <stdio.h>
#include <stdio.h>

double veloc_inicial(double x, int y)
{
	return y == 0 ? x :
	x + veloc_inicial(x*0.9, y-1);
}

void canhao(void)
{
	int d;
	int v = 1;
	while (scanf("%d", &d) != EOF)
	{
		printf("%f\n", veloc_inicial(v,d));
	}
}

int main(void)
{
	canhao();
	return 0;
}