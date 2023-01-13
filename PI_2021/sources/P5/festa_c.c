#include<stdio.h>
#include<math.h>
double recursiva(int c1, int x, double valor)
{
  return c1 <= 60 ? c1 * valor: (valor * 60) + recursiva(c1-60, x+1 ,0.1((x+1)(x+1)));
}
double covidado_1(int h1,int m1,int h2,int m2,int h3,int m3)
{
  int a1 = (h1*60) + m1;
  int a2 = (h2 *60) + m2;
  int a3 = (h3 *60) +m3;
  int c1 = a3-a1;
  int c2 = a2-a3;
  int x = 1;
  double valor = 0.1;
  double d;
  if(c1 <= c2)
  {
    d = recursiva(c1,x,valor);
  }
  else
  {
    d = recursiva(c2,x,valor);
  }
  return d;
}

void test()
{
  int h1;
  int m1; // Tempo em que começa o recolher obrigatorio;
  int h2;
  int m2; // Tempo em que acaba o recolher obrigatorio;
  int h3;
  int m3; // Tempo depois do recolher obrigatorio;
  scanf("%d%d%d%d", &h1, &m1, &h2, &m2);
  while(scanf("%d%d", &h3, &m3) !=EOF)
  {
    double multa = covidado_1(h1,m1,h2,m2,h3,m3);
    printf("%0.2f\n", multa);
  }
}

int main()
{
  test();
  return 0;
}