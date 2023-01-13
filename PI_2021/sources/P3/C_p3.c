#include <stdio.h>

int yellow(int comp, int alt, int blue)
{
	int sum_yellow = (comp * alt)-blue;
	return sum_yellow;
}

int blue(int comp, int alt)
{
	int sum_blue = 0;
	sum_blue = ((1 + (1+ (((alt + 1) / 2) - 1) * 4)) * ((alt+1) / 2)) / 2;

	sum_blue += (comp - alt) * alt - ((comp - alt + (alt % 2)) /2) * alt;
	return sum_blue;
}

void interact_sum_tiles(void)
{
	int alt, comp, result_blue, result_yellow;
	while(scanf("%d%d", &comp, &alt) != EOF)
	{
		result_blue = blue(comp, alt);
		result_yellow = yellow(comp, alt, result_blue);
		printf("%d %d\n", result_blue, result_yellow);
	}
}

int main(void)
{
	interact_sum_tiles();
	return 0;
}