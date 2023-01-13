#include <stdio.h>
#include <assert.h>
// -------------------------- Problema B --------------------------------------
int str_find(const char *s, char x)
{
  for (int i = 0; s[i] != 0; i++)
    if (s[i] == x)
      return i;
  return -1;
}

int alpha3(const char *s, const char *r)
{
  char result = str_find(r, s[0]);
  //return result != -1 && str_find(r + result + 1,s[1]) != -1;
  char result2 = result != -1 && str_find(r + result + 1,s[1]) != -1;
  return result2 != -1 && str_find(r + result2 + 1,s[2]) != -1;
}

void test_alpha3(void)
{
  char s[2]; 
  scanf("%s", s);
  char x[1000];
  char *r[2] = {"NO","YES"};
  while (scanf("%s", x) != EOF)
  {
    int z = alpha3(s,x);
    printf("%s\n", r[z]);
  }
}

int main(void)
{
  test_alpha3();
  return 0;
}