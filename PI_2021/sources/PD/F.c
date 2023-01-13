#include <stdio.h>
#include <assert.h>
#include "our_ints.h"
#include "our_doubles.h"
//------------------------- Problema F ------------------------------------

int ints_remove_multiple(const int *a, int n, int total, int *b)
{
    int result = 0;
    int subarray = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (i != a[subarray])
            b[result++] = i;
        else
            subarray++;
    }
    return result;
}

int ints_count_while_continuous(const int *a, int n)
{
    int result = 0;
    while (result < n-1 && a[result+1] == a[result]+1)
        result++;
    return result+1;
}

int sequencia(const int *a, int n, int *b, int *c)
{
    int result = 0;
    int i = 0;
    while (i < n)
    {
        int z = ints_count_while_continuous(a+i,n-i);
        b[result] = i;
        c[result] = z;
        result++;
        i += z;
    }
    return result;
}

void test_bigbang(void)
{
    int x; //episodios
    scanf("%d", &x);

    int a[1000]; //vistos
    int n = ints_get(a);

    int b[1000]; //nao vistos
    int y = ints_remove_multiple(a, n, x, b);

    int tamanho[1000];
    int episodio[1000];
    int l = sequencia(b, y, episodio, tamanho);

    int z = b[episodio[ints_find(tamanho, l, ints_min(tamanho, l))]];
    printf("%d\n", z);
}

int main(void)
{
    test_bigbang();
    return 0;
}