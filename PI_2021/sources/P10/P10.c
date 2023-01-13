#include <stdio.h>
#include <assert.h>
#include "our_ints.h"
#include "our_doubles.h"

// -------------- Exercicio A-----------------
int div(int x, int y)
{
    while(x != 0)
    {
        if(x % 10 == y)
            return 1;
        else
            x /= 10;
    }
    return 0;
}

int operacao_stop(const int *a, int n,int *b, int x)
{
    int result = 0;
    for(int i = 0; i < n; i++)
    {
        int y = div(a[i], x);
        if(y == 1)
            b[result++] = a[i];
    }
    return result;
}

void test_operacao_stop(void)
{
    int a[1000];
    int b[1000];
    int x;
    scanf("%d", &x);
    int n = ints_get_until(-1,a);
    int y = operacao_stop(a,n,b,x);
    printf("%d\n", y);
    ints_println(b, y,"\n");
}

void unit_test_operacao_stop(void)
{
    int a[10] = {781212, 112232, 809111, 671, 1000, 381922, 711673, 3333, 2, 128912};
    int b[10];
    assert(operacao_stop(a,3,b,1) == 3 && b[0] == 781212 && b[1] == 112232 && b[2] == 809111);
}

// --------------- Exercicio B--------------------- 

/*double media_abf(const double *a, int n, int i)
{
    double result = 0;
    int d = 0;
    for(int j = i; j < n-12; j += 12)
    {
        d++;
        result += a[j];
    }
    return result/d;

}

int comp_media_abf(const double *a, int n, const double *b, int y, int *c)
{
    int result = 0;
    for(int i = n-12; i < n; i++)
    {
        if(a[i] < b[i-n-12])
            c[result++] = i-n+12+1;
    }
}

int albufeiras(const double *a, int n, double *b)
{
    int result = 0;
    for(int i = 0; i < 12; i++)
        b[result++] = media_abf(i,a,n);
    return result;

}

void test_albufeiras(void)
{
    double a[960];
    double b[960];
    int c[960];
    int n = doubles_get_until(-1,a);
    int y = albufeiras(a, n, b);
    int t = comp_media_abf(a, n, b, y, c);
    ints_println_special(c, t);
}

void unit_test_albufeiras(void)
{

}
*/

int double_sub_array(double *a, int n, int x, double *b)
{
    int result = 0;
    for(int i = n; i < n + x; i++)
    {
        a[result++] = b[i];
    }
    return result;
}

void media_meses(double *a, int n, double *b)
{
    int anos = n / 12;
    for(int i = 0; i < n - 12; i++)
    {
        a[i%12] += b[i]; //i%12 o 12ºmes é janeiro do ano seguinte, e vai somar cada ano
    }
    for(int i = 0; i < 12; i++)
    {
        a[i] = a[i] / (anos -1); // divide para saber a media e o mes
    }
}

int verificar_media_meses(int *a, double *b, double *c)
{
 int result = 0;
 for(int i = 0; i < 12; i++)
 {
     if(b[i] < c[i])
        a[result++] = i + 1; //(output), +1 porque nao existe mes 0
 }
 return result;
}

void test_albufeiras(void)
{
    int anos, result;
    int media_inferior[12];
    double ultimo_ano[12];
    double niveis[960]; // 80*12meses= 960, requisito
    double media[12];

    int n = doubles_get(niveis);
    anos = n / 12;
    media_meses(media, n, niveis);
    double_sub_array(ultimo_ano, 12 * (anos - 1), 12, niveis);
    result = verificar_media_meses(media_inferior, ultimo_ano, media);
    ints_println_special(media_inferior, result);

}

/*void unit_test_albufeiras(void)
{

}*/

//---------------Exercício C---------------------
void only_min( int *a, int n)
{
    for(int i = 0; i < n; i++)
       a[i] /= 100;   
}

int maradona(int *a, int n)
{
    only_min(a,n);
    int max = 0;
    int min = 0;
    for(int i = 0; i < n; i++)
    {
        int g = ints_count(a,n, a[i]);
        if(g > max)
        {
            max = g;
            min = a[i];
        }
    }
    return min;
}

void test_maradona(void)
{
    int a[1000];
    int n = ints_get_until(-1,a);
    int min = maradona(a,n);
    int g = ints_count(a,n,min);
    printf("%d %d\n", min, g);
}

void unit_test_maradona(void)
{
    int a[7] = {2345, 7810, 250, 900, 2300, 1200, 2345};
    assert(maradona(a,7) == 23);
}

void unit_tests(void)
{
    unit_test_operacao_stop(); //exercicio A
    //unit_test_albufeiras(); //ecercício B
    unit_test_maradona(); //exercicio C
}

int main (int argc, char **argv)
 {
	unit_tests();
	int x = 'A';
	if (argc > 1)
    {
		x = *argv[1];
	}/*else
	if (x == 'B') 
    {
		test_albufeiras();
	}*/
    else 
    if(x == 'C') 
    {
		test_maradona();
	}
	else if (x == 'U')
     {
		printf("All unit tests PASSED.\n");
	}
	else {
		printf("%s: Invalid option.\n", argv[1]);
	}
	return 0;
}