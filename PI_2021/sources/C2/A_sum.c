#include <stdio.h>

int soma(int x, int z)
{
	return x == 0 ? z : soma(x-1, z+x);

}

int main(void)
{
	int x;
	int z=0;
	while (scanf("%d", &x) != EOF)
	{
		int res= soma(x,z);
		printf("%d\n", res );
	}

}