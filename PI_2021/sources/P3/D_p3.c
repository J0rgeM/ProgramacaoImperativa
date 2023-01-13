#include <stdio.h>
#include <math.h>

double salario(double x, double y, double z)
{
	return y > 20 ? ((x * 2) + (y - 20 + z / 60) * (x * 1.50)) : (y - 18 + z / 60) * (x);
}

void interact_salario(void)
{	
	double x;
	int y,z;	
	while(scanf("%lf%d%d", &x, &y, &z) != EOF)
	 {
	 	double result = round(salario(x,y,z) * 100)/100;
	 	printf("%f\n", result);
	 }
}

int main(void)
{
	interact_salario();
	return 0;
}