#include <stdio.h>  
#include <math.h>
#include <assert.h>
#include "our_ints.h"
#include "our_doubles.h"


int double_sub(double *result, int init, int len, double *array)
{
    int n = 0;
    for(int i = init; i < init + len; i++)
    {
        result[n++] = array[i];
    }
    return n;
}

void media_meses(double *media, int n, double *niveis)
{
    int anos = n / 12;
    for (int i = 0; i < n - 12; i++)
        media[i%12] += niveis[i]; //i%12 o 12ºmes é janeiro do ano seguinte. vai somar cada ano
    for(int i = 0; i < 12; i++)
        media[i] = media[i]/(anos - 1); // vai dividir para saber a media e cada mes
}

int verificar_media(int *result, double *ultimo_ano, double *media)
{
    int n = 0;
    for(int i = 0; i < 12; i++)
    {
        if(ultimo_ano[i] < media[i])
            result[n++] = i + 1;// result é o output. +1 porue nao ha mes 0
    }
    return n;
}

void test_albufeiras()
{
    int n, anos, result_meses_inferiores;

    int media_inferior[12];
    double ultimo_ano[12];
    double niveis[960];// requesitos tecnicos, 80*12meses=960
    double media[12];

    n = doubles_get(niveis);
    anos = n / 12;
    media_meses(media, n, niveis);
    double_sub(ultimo_ano, 12*(anos-1), 12, niveis);
    result_meses_inferiores = verificar_media(media_inferior, ultimo_ano, media);
    ints_println_special(media_inferior, result_meses_inferiores);
}

int main()
{
    test_albufeiras();
    return 0;
}