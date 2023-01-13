#include <stdio.h>
#include <math.h>

int converte_meses(int x, int m)
{
	int z = 40*12;
	return z + (x*12) + m;
}

int comp(int x)
{
	int id = (66*12) + 4;
	int max = (70*12);
	if (x < id)
		return id;
	if (x > max)
		return max;
	else 
		return x;
}

int inverso(int x)
{
	return x/12;
}

int inverso_meses(int x)
{
	return x%12;
}

void reforma(void)
{
	int a;
	int m;
	while (scanf("%d%d", &a, &m) != EOF)
	{
		printf("%d %d\n", inverso(comp(converte_meses(a,m))) , inverso_meses(comp(converte_meses(a,m))) );
	}
}

int main(void)
{
	reforma();
	return 0;
}