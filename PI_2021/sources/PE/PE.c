#include <stdio.h>
#include <assert.h>

//----------------------------- Problema A -----------------------------------
int str_find(const char *s, char x)
{
  for (int i = 0; s[i] != 0; i++)
    if (s[i] == x)
      return i;
  return -1;
}

int alpha2(const char *s, const char *r)
{
  char result = str_find(r, s[0]);
  return result != -1 && str_find(r + result + 1,s[1]) != -1;
}

void test_alpha2(void)
{
  char s[2]; 
  scanf("%s", s);
  char x[1000];
  char *r[2] = {"NO","YES"};
  while (scanf("%s", x) != EOF)
  {
    int z = alpha2(s,x);
    printf("%s\n", r[z]);
  }
}

void unit_test_str_find(void)
{
  assert(str_find("abcdedfghi", 'a') == 0);
  assert(str_find("abcdedfghi", 'd') == 3);
  assert(str_find("abcdedfghi", 'g') == 7);
  assert(str_find("abcdedfghi", 'i') == 9);
  assert(str_find("abcdedfghi", 'p') == -1);
  assert(str_find("", 'z') == -1);
}

void unit_test_alpha2(void)
{
  assert(alpha2("pt", "portugal"));
  assert(alpha2("fr", "franca"));
  assert(alpha2("lk", "sri lanka"));
  assert(!alpha2("de", "alemanha"));
  assert(!alpha2("zb", "brazil"));
}

// -------------------------- Problema B --------------------------------------

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

void unit_tests(void)
{
  unit_test_str_find();
  unit_test_alpha2();
}

int main (int argc, char **argv)
{
	unit_tests();
	int x = 'A';
	if (argc > 1)
		x = *argv[1];
	if (x == 'A') 
		test_alpha2();
	else if (x == 'B') 
    test_alpha3();
	else if (x == 'U')
		printf("All unit tests PASSED.\n");
	else
		printf("%s: Invalid option.\n", argv[1]);
	return 0;
}