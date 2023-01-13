#include <stdio.h>
#include <math.h>

double calc_ida(int x)
{
	double p = 0.087;
	return ceil(x*p*2)/2;
}

double ida_volta(int x)
{
	double des = 0.85;
	return ceil(calc_ida(x)*2*des*2)/2;
}

void precob(void)
{
	int km;
	while (scanf("%d", &km) != EOF)
	{
		printf("%.2f %.2f\n", calc_ida(km), ida_volta(km));
	}
}

int main(void)
{
	precob();
	return 0;
}