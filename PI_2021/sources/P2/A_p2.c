#include <stdio.h>
   
int sum_positive_integers(int x)
{
  return x == 0 ? 0 : x + sum_positive_integers(x-1);
}

 void interact_sum_positive_integers (void)
 {
    int x;
    while(scanf("%d", &x) != EOF){
      int r = sum_positive_integers(x);
      printf("%d\n", r);
    }
 }

 int main(void)
  {
  	interact_sum_positive_integers();
  }

 