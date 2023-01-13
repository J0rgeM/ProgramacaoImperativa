#include <stdio.h>

	int sum_extra(int n)
	{
		return n;
	}

	int somersaults(int gol, int n)
	{
		return gol % 4 == 0 ? 8 * (gol/4) : somersaults(gol-1, n+1) + sum_extra(n+1);
	}


	void interact_somersaults(void)
	{
		int x;
		int n=0;
		while(scanf("%d", &x) != EOF)
		 {
		 	int result = somersaults(x,n) + sum_extra(n);
		 	printf("%d\n", result);
		 }
	}

	int main(void)
	{
		interact_somersaults();
		return 0;
	}
