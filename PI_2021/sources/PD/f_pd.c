#include <stdio.h>
#include <assert.h>
#include "our_ints.h"
#include "our_doubles.h"


int ints_find_pos (const int *b, int n) {
    int i = 0;
    while (i < n && b[i] == 0) {
        i++;
    }
    return b[i];
}


int ints_argmin_mine(const int *b, int n)
{
    assert(n > 0);
    int result = 0;
    int m;
    if (b[0] != 0) {
        m = b[0];
    }
    else {
        m = ints_find_pos(b, n) + 1; //encontra o primeiro valor de b positivo para depois encontrar o argumento minimo em que b[i] != 0
    }

    for (int i = 1; i < n; i++)   // i = 1 //encontra o argmin de b[i] e devolve o argumento
        if (m > b[i] && b[i] != 0)
              m = b[result = i];
  return result;
}

int not_watched (int episodio, int x, int *c, int t) {
    int result = t;
    int cont = 0;
    while (result <= x && result != episodio) {
        c[cont++] = result;
        result++;
    }
    return cont;
}

int big_bang (const int *a, int n, int x, int *b, int *c){
    int i = 0;
    int result = 0;
    int t = 1;
    while (i < n) {
        int z = not_watched(a[i], x, c, t); //devolve o tamanho dos grupos de episodios nao vistos
        t += z + 1;
        b[result++] = z;
        i++;
    }
    int argmin = ints_argmin_mine(b, result);

    return argmin;
}

int main()
{
    big_bang();
    return 0;
}