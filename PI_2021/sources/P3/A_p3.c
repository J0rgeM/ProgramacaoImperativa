#include <stdio.h>
#include <math.h>

	const double pol = 2.54;
	const double feet = pol * 12;
	const double pol16 = pol/ 16;

	double nba(int x, int y, int z)
	{			
		double result = (x * feet + y * pol + z * pol16) / 100;
		result = round(result * 100 *2) / 100/2;
		return result;
	}

	void interact_nba(void)
	{	
		int x,y,z;
		while(scanf("%d%d%d", &x, &y, &z) != EOF)
		 {
		 	double result = nba(x,y,z);
		 	printf("%lf\n", result);
		 }
	}

	 int main(void)
	{
		interact_nba();
		return 0;
	}
	