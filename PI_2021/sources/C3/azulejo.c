#include <stdio.h>

int blue(int c, int a)
{
	int res;
	res = ((1 +(1 + (((a + 1) / 2) - 1) *4)) * ((a + 1) / 2)) / 2;
	res += (c - a) * a - ((c - a + (a % 2)) / 2) * a;
	return res;
}


int yellow(int c, int a, int blue )
{
	int res= (c*a) - blue;
	return res;
}

void parede(void)
{
	int c;
	int a;
	while (scanf("%d%d", &c, &a) != EOF)
	{
		printf("%d %d\n", blue(c,a), yellow(c,a,blue(c,a)));
	}
}

int main(void)
{
	parede();
	return 0;
}