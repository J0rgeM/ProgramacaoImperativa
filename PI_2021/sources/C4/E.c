#include <stdio.h>
#include <math.h>

int Banheira(int l0)
{
    return l0 <= 1 ? 0 : Banheira(l0 - 1) + 4 * (l0 - 1); //Utilizado no P3, para contar a sequencia da primeira cor
}

int BanheiraRosa(int B)
{
    int l0 = B / 2;        //número de linhas rosa em B par
    int l1 = B / 2 + B % 2; //número de linhas rosa em B impár
    if (B % 2 == 0)
    {
        return pow(B, 2) - (Banheira(l0) + l0);    //em números par a 1º cor é Branca
    }                                        // l0 - cantos
    else
    {
        return Banheira(l1) + l1;        //em números impar a 1º cor é Rosa
    }                            //l1 - cantos
}

int BanheiraBranca(int B)
{
    return pow(B, 2) - BanheiraRosa(B); //Todos da banheira menos os Rosa da banheira
}

int MosaicoCount(int L, int W, int total)
{
    if (L > 1)
    {
        total += 2*L + 2*   W - 4;
        return MosaicoCount(L - 4, W - 4, total);
    }
    else if (L == 1)
        return total += L * W;
    else if (L < 1)
        return total += 0;
    return total;
}

int MosaicosRosa(int L, int W, int B)
{
    return MosaicoCount(L, W, 0) - BanheiraRosa(B);
}

int MosaicosBrancos(int L, int W, int B)
{
    return (L * W) - (MosaicoCount(L, W, 0) + BanheiraBranca(B));
}

void test_duche(void)
{
    int L;
    int W;
    int B;
    while (scanf("%d%d%d", &W, &L, &B) != EOF)
    {
        int Rosa = MosaicosRosa(L, W, B);
        int Branco = MosaicosBrancos(L, W, B);
        printf("%d %d\n", Rosa, Branco);
    }
}

int main(void)
{
    test_duche();
    return 0;
}