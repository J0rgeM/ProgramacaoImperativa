#include <stdio.h>

int cmortal(int x)
{
	return (x/4)*8;
}

int srsaults(int x, int n)
{
	int res;
	if (x % 4 == 0)
		res = cmortal(x);
	else 
		res = n + srsaults(x-1,n+1);
	return res;
}


void somersaults(void)
{
	int x;
	int n=1;
	while (scanf("%d", &x) != EOF)
	{
		printf("%d\n", srsaults(x,n) );
	}

}

int main()
{
	somersaults();
	return 0;
}