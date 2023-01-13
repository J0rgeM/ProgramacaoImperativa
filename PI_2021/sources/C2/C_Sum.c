#include <stdio.h>

int progression (int x, int r , int n, int z)

{
	return n == 0 ? z : 
	progression(x+r,r,n-1,z+x);
}



int main(void)
{
	int x;
	int r;
	int n;
	int z=0;
	while (scanf("%d%d%d", &x, &r, &n) != EOF)
	{
		int res= progression(x,r,n,z);
		printf("%d\n", res );
	}

}