#include <stdio.h>

int concatenate(int x, int y, int z)
{
	return z < y ? concatenate(x,y,z*10) : (x*z) + y;
}

int main(void)
{
	int x;
	int y;
	int z=10;
	scanf("%d%d", &x, &y);
	int res= concatenate(x,y,z);
	printf("%d\n", res);
}