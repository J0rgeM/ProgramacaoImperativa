#include <stdio.h>
#include <assert.h>
#include "our_ints.h"
#include "our_doubles.h"

//------------------------- Problema A ------------------------------------
int ints_count_while_penalti (const int *a, int n) 
{
	int result = 1;
	while (result < n && ((a[result] * a[0]) > 0 || a[result] == 0)) 
		result++;
	return result;
}

int penalti (const int *a, int n, int *b) 
{
	int result = 0;
	int i = 0;
	while (i < n)
	 {
		int z = ints_count_while_penalti(a + i, n - i);
		b[result++] = z;
		i += z;
	}
	return result;
}

void test_penalti (void)
{
	int a[1000];
	int n = ints_get(a);
	int b[1000];
	int m = penalti (a, n, b);
	ints_println_special(b, m);
}

void unit_test_penalti (void)
{
	int a[20] = {4,6, 8, 3, -1, 10, 4, 5, -3, -4, 7, 0, 0, -2, 6, 4, -4, -3, -2};
	int b[20];
	assert(penalti(a, 20, b) == 8);
	assert(penalti(a + 5, 15, b) == 6);
}

// ----------------------------- Problema B -----------------------------------

int quantidade (const double *a, int n)
{
    int x = 0;
    int result = 0;
    int y = 0;
    while (x < n)
	{
        if (a[x] <= 0)
		{
            result++;
        }
        x++;
    }
    if (result >= 3)
    {
        y = 1;
    }
    return y;
}

int primeira_vez(const double *a, int n) 
{
    int i = n - 31;
    int result = 0;
    while (i >= 0) {
       int z = quantidade(a + i, 31);
        if (z == 1) 
        {
            return (n - i)/31;
        }
        i -= 31;
    }
    return result;
}

int dezembro (const double *a, int n)
 {
    int i = 0;
    int result = 0;
    while (i < n) 
    {
        int z = quantidade(a + i, 31);
        result += z;
        i += 31;
    }
    return result;
}

void test_dezembro (void) 
{
    double a[4000];
    int n = doubles_get(a);
    int y = dezembro(a, n);
    if (y != 0)
     {
        int x = primeira_vez(a, n);
        printf("%d %d\n", y, x);
    }
    else 
    {
        printf("%d\n", y);
    }
    
}

//----------------------------- Problema C -----------------------------------

int separar(const double *a, int n, double *b, double *c)
{
	int i = 0;
	int result = 0;
	while (i < n)
	{
		b[result] = a[i];
		i++;
		c[result] = a[i];
		result++;
		i++;
	}
	return result;
}

int dias_choveu(const double *a, int n)
{
  int result = 0;
  for (int i = 0; i < n; i++)
    if (a[i] > 0)
      result++;
  return result;
}

int doubles_count_while_penico(const double *a, int n)
{
	int result = 0;
	while (result < n && a[result] > 0)
	{
		result++;
	}
	return result;
}

int dias_seguidos_choveu(const double *a, int n, int *d)
{
	int result = 0;
	int i = 0;
	while (i < n)
	{
		int x = doubles_count_while_penico(a+i,n-i);
		d[result++] = x;
		if (x == 0)
		{
			x++;
		}
		i += x;
	}
	int max = ints_max(d,result);
	return max;
}

void test_penico(void)
{
	double a[1000]; 
	double b[1000];
	double c[1000];
	int d[1000];
	int n = doubles_get(a);
	int x = separar(a,n,b,c);
	double precipitacao_total_1 = doubles_sum(b,x);
	double precipitacao_total_2 = doubles_sum(c,x);
	double max_chuva_1 = doubles_max(b,x);
	double max_chuva_2 = doubles_max(c,x);
	int total_dias_choveu1 = dias_choveu(b,x);
	int total_dias_choveu2 = dias_choveu(c,x);
	int max1 = dias_seguidos_choveu(b,x,d);
	int max2 = dias_seguidos_choveu(c,x,d);
 	printf("%.1f %.1f\n", precipitacao_total_1, precipitacao_total_2);
	printf("%.1f %.1f\n", max_chuva_1, max_chuva_2);
	printf("%d %d\n", total_dias_choveu1, total_dias_choveu2);
	printf("%d %d\n", max1, max2);
}

//----------------------------- Problema D -----------------------------------

int count_rampa(const int *a, int n)
{
	int result = 1;
	while (result < n && a[result] - a[result - 1] > 0)
	{
		result++;
	}
	return result;
}

int rampa(const int *a, int n, int *b, int x)
{
	int i = 0;
	b[0] = 0;
	b[1] = 0;
	while (i < n)
	{
		int z = count_rampa(a+i, n-i);
		if ((z-1) >= x)
		{
			b[0] += 1;
			b[1] += z - 1;
		}
		i += z;
	}
	return 2;
}

void test_rampa(void)
{
	int x;
	scanf("%d", &x);
	int a[1000];
	int b[2];
	int n = ints_get(a);
	int result = rampa(a,n,b,x);
	ints_println_special(b,result);
}

//----------------------------- Problema E -----------------------------------

int count_recessao(const int *a, int n)
{
	int result = 1;
	while (result < n && a[result - 1] - a[result] > 0)
	{
		result++;
	}
	return result;
}

void ints_println_1(const int *b, int z)
{
	printf("%d\n", z);
	for (int i = 0; i < z*2; i += 2)
	{
		printf("%d %d\n", b[i],b[i+1]);
	}
}

int recessao(const int *a, int n, int *b)
{
	int i = 0;
	int result = 0;
	int y;
	while (i < n)
	{
		y = count_recessao(a+i,n-i);
		if ( y >= 3)
		{
			b[result++] = i;
			b[result++] = y;
		}
		i += y;
	}
	return result;
}

void test_recessao(void)
{
	int a[1000];
	int b[1000];
	int n = ints_get(a);
	int z = recessao(a,n,b)/2;
	ints_println_1(b,z);
}

//------------------------- Problema F ------------------------------------
int ints_find_pos(const int *b, int n) 
{
    int i = 0;
    while (i < n && b[i] == 0) 
        i++;
    return b[i];
}

int ints_argmin_mine(const int *b, int n)
{
    assert(n > 0);
    int result = 0, m;

    if (b[0] != 0) 
        m = b[0];
    else 
        m = ints_find_pos(b, n) + 1; //encontra o primeiro valor de b positivo para depois encontrar o argumento minimo em que b[i] != 0
    for (int i = 1; i < n; i++)   // i = 1 //encontra o argmin de b[i] e devolve o argumento
        if (m > b[i] && b[i] != 0)
              m = b[result = i];
  return result;
}

int nao_visto (int episodio, int x, int *c, int t) 
{
    int result = t;
    int contador = 0;
    while (result <= x && result != episodio) 
    {
        c[contador++] = result;
        result++;
    }
    return contador;
}

int bigbang (const int *a, int n, int x, int *b, int *c)
{
    int i = 0;
    int result = 0;
    int t = 1;
    while (i < n) 
    {
        int z = nao_visto(a[i], x, c, t); //devolve o tamanho dos grupos de episodios nao vistos
        t += z + 1;
        b[result++] = z;
        i++;
    }
    int argmin = ints_argmin_mine(b, result);

    return argmin;
}

void test_bigbang (void) 
{
    int a[1000];
    int b[1000];
    int c[1000];

    int x, t;
    scanf("%d", &x);

    int n = ints_get(a);
    a[n+1] = x;
    int y = bigbang(a, n+1, x, b, c);

    if (y == 0) 
    {
        t = 1;
        printf("%d\n", t);
    }
    else
    {
        y = y-1;
        t = a[y] + 1;
        printf("%d\n", t); //devolve o primeiro episodio nao visto do grupo mais pequeno
    }
}

void unit_tests (void)
{
	unit_test_penalti();
}

int main (int argc, char **argv)
{
	unit_tests();
	int x = 'A';
	if (argc > 1)
		x = *argv[1];
	if (x == 'A') 
		test_penalti();
	else if (x == 'B') 
		test_dezembro();
	else if (x == 'C') 
		test_penico();
	else if (x == 'D') 
		test_rampa();
	else if (x == 'E') 
		test_recessao();
	else if (x == 'F') 
		test_bigbang();
	else if (x == 'U')
		printf("All unit tests PASSED.\n");
	else
		printf("%s: Invalid option.\n", argv[1]);
	return 0;
}