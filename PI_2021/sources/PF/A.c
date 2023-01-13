#include <stdio.h>
#include <assert.h>

//Eu, Jorge, declaro por minha honra que este programa foi escrito por mim, durante o
//exame de 5 de fevereiro de 2021, e que não recebi ajuda de ninguém, a não ser, 
//eventualmente, da professora Graça, do professor Amine e do professor Pedro

int str_privacidade(const char *s, char *t)
{
 int result = 0;
 while( s[result] != '\0')
 {
    if (s[result] >= 'A' && s[result] <= 'Z')
      t[1] = s[result];
    result++;
}

  t[3] = s[result-1];
  t[2] = s[result-2];
  return 0;
} 

int str_privacity(char *s, char *t)
{
  t[0] = s[0];
  str_privacidade(s, t);
  t[4] = '\0';
  return 0;
}

void test_privacity(void)
{
  char s[1000];
  char t[1000];
  while (scanf("%s", t) != EOF)
  {
      str_privacity(t, s);
      printf("%s\n", s);
  }
}

int main (void)
{
    test_privacity();
    return 0;
}