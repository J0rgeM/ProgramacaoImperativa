#include <stdio.h>
int half(int y)
{
 return y == 0 ? 0 : y - 1 == 0 ? 0 : half(y-2)+1;
}

int main(void)
{
 	int y;
 	scanf("%d", &y);
 	int z = half(y);
 	printf("%d\n", z);
 	return 0;
}