#include <stdio.h>
int sum(int x, int y)
{
 return y == 0 ? x : sum(x+1, y-1);
}
int twice(int x)
{
	return sum(x,x);
}
int main(void)
{
 int x;
 scanf("%d", &x);
 int z = twice(x);
 printf("%d\n", z);
 return 0;
} 