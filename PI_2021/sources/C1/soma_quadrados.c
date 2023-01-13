//Tomás Rodrigues 67382
#include <stdio.h>
int sumquadrados (int x)
{
	return ((x+1)*x*(2*x+1))/6;
}
int sumquadrados_ent (int x, int y)
{
	return sumquadrados (y) - sumquadrados (x-1);
}
int main(void)
{
 	int x;
 	int y;
 	scanf("%d%d", &x, &y);
 	int z = sumquadrados_ent(x,y);
	printf("%d\n", z);
 	return 0;
} 