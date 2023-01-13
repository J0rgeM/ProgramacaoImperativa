#include <stdio.h>
#include <math.h>

double converte(int x, int y, int z)
{
	double res = ((x*0.3048) + (y*0.0254) + (z*0.0254/16));
	return round(res*200)/200;
}

void nba(void)
{
	int x; //pés
	int y; //polegadas
	int z; // pes
	while (scanf("%d%d%d", &x, &y, &z) != EOF)
	{
		printf("%f\n", converte(x,y,z) );
	}
}


int main()
{
	nba();
	return 0;
}