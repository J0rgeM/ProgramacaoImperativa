#include <stdio.h>
#include <assert.h>

int str_is_prefix(char *pre, char *name)
{
    int result = 0;
    for (int i = 0; pre[i] != '\0'; i++) // percorre string pre
        result++;

    // verifica se prefixo é igual ao nome e se a posiçao 0 das duas strings é diferente
    int result2 = 0;
    while ( (pre[result2] == name[result2] && result2 != result) || ('\0' == pre[0]))
        result2++;

    if (result == result2) // se forem iguais significa que tem prefixo 
        return 1; 
    return result2;
}

void test_prefix(void)
{
    char pre[1000];
    char name[1000]; // n de caracters
    while (scanf("%s%s", pre, name) != EOF)
    {
        int x = str_is_prefix(pre, name);
        if (x == 1) // 1 vem da do if da funçao prefix 
            printf("YES\n");
        else
            printf("NO\n");
    }
}

void unit_test_str_is_prefix(void)
{
    assert(str_is_prefix("abc", "abcde"));
    assert(str_is_prefix("abc", "abc"));
    assert(str_is_prefix("", "abcde"));
    assert(str_is_prefix("a", "abcde"));
    assert(!str_is_prefix("abcde", "abc"));
    assert(!str_is_prefix("bcde", "abcde"));
    assert(!str_is_prefix("b", "abcde"));
    assert(!str_is_prefix("abcde", "xyz"));
}

int main(void)
{
    unit_test_str_is_prefix();
    test_prefix();
    return 0;
}