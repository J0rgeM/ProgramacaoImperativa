#include <stdio.h>

int soma(int r, int n, int z)
{
	return n == 0 ? z : soma(r,n-1,((n-1)*r)+z);

}

int main(void)
{
	int r;
	int n;
	int z=0;
	while (scanf("%d%d", &r, &n) != EOF)
	{
		int res= soma(r,n,z);
		printf("%d\n", res );
	}

}