#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "our_ints.h"
#include "our_doubles.h"

/*
Eu, Roberto Santos, declaro por minha honra que este programa foi escrito por mim, durante o
exame de 5 de fevereiro de 2021, e que não recebi ajuda de ninguém, a não ser, eventualmente, da professora Graça, do professor Amine e do professor Pedro. 
*/

// A

int str_privacity_useful(const char *test, char *r)
{
 int result = 0;
 while( test[result] != '\0')
 {
    if (test[result] >= 'A' && test[result] <= 'Z')
    {
      r[1] = test[result];
    }
    result++;
  }
  r[3] = test[result-1];
  r[2] = test[result-2];
  return 0;
} 

int str_privacity(char *test, char *r)
{
  r[0] = test[0];
  str_privacity_useful(test, r);
  r[4] = '\0';
  return 0;
}

void test_privacity()
{
  char r[1000];
  char test[1000];
  while (scanf("%s", test) != EOF)
  {
      str_privacity(test, r);
      printf("%s\n", r);
  }
}

// B


// C

int main(int argc, char **argv)
{ 
  int x = 'A'; 
  if (argc > 1) 
    x = *argv[1]; 
  if (x == 'A') 
    test_privacity();
  else 
    printf("%s: Invalid option.\n", argv[1]); 
  return 0;  
}