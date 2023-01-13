#include <stdio.h>
#include <math.h>

double c_salario(double x, double y, double z)
{
	double hm= y+(z/60);
	if ((y>20))
	{
		return (x*2)+((hm-20)*1.5*x);
	} 
	else 
		return x*(hm-18);
}


void salario(void)
{
	double s;
	int h;
	int m;
	while (scanf("%lf%d%d", &s, &h, &m) != EOF)
		{
			double res= round(100*c_salario(s,h,m))/100;
			printf("%f\n", res);
		}
}

int main(void)
{
	salario();
	return 0;
}