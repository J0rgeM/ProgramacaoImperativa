#include <stdio.h>
#include <assert.h>

//Eu, Jorge, declaro por minha honra que este programa foi escrito por mim, durante o exame de 5 de fevereiro de 2021, e que não recebi ajuda de ninguém, a não ser, eventualmente, da professora Graça, do professor Amine e do professor Pedro

int privacidade_contador(const char *s, char *t)
{
 int result = 0;
 while( s[result] != '\0')
 {
    if (s[result] >= 'A' && s[result] <= 'Z')
      t[1] = s[result]; //ultima letra maiscula
    result++; // contar n carateres do string
}
  t[2] = s[result-2]; //penultimo numero
  t[3] = s[result-1]; //ultimo numero
  return 0;
} 

int privacidade(char *s, char *t)
{
  t[0] = s[0]; //primeira letra
  privacidade_contador(s, t);
  t[4] = '\0'; //define o fim
  return 0;
}

void test_privacidade(void)
{
  char s[1000];
  char t[1000];
  while (scanf("%s", t) != EOF)
  {
      privacidade(t, s);
      printf("%s\n", s);
  }
}

int main(int argc, char **argv)
{ 
  int x = 'A'; 
  if (argc > 1) 
    x = *argv[1]; 
  if (x == 'A') 
    test_privacidade();
  else 
    printf("%s: Invalid option.\n", argv[1]); 
  return 0;  
}