#include <stdio.h>
#include <math.h>

double calc_imc(double x, double y)
{
	return x/ pow (y,2);
}

double obesa_01(int x, double y)
{
	int result;
	if (x == 1)
		if (y>=31.2)
			result = 1;
		else
			result = 0;
	else
		if (y>=32.4)
			result = 1;
		else
			result = 0;
	return result;
}


void obesidade(void)
{
	int s;
	double w;
	double h;
	while (scanf("%d%lf%lf", &s, &w, &h) != EOF)
	{
		int res_ob = obesa_01(s,calc_imc(w,h));
		printf("%f %d\n", calc_imc(w,h), res_ob);
	}
}

int main(void)
{
	obesidade();
	return 0;
}