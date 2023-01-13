#include <stdio.h>
#include <assert.h>

//Eu, Jorge, declaro por minha honra que este programa foi escrito por mim, durante o
//exame de 5 de fevereiro de 2021, e que não recebi ajuda de ninguém, a não ser, 
//eventualmente, da professora Graça, do professor Amine e do professor Pedro

// Are the two strings equal?
int str_equal(const char *s, const char *t)
{
    int i = 0;
    while (s[i] && t[i] && s[i] == t[i])
    i++;
    return s[i] == '\0' && t[i] == '\0';
} 

// Length of the string, measured in number of memory bytes used.
int str_len(const char *s)
{
    int result = 0;
    while (s[result] != '\0')
    result++;
    return result;
}

int corretor_ortografico(const char *s, const char *x)
{
    if(str_len(s) == strlen(x) && str_equal(s,x))
        return 1;
    return 0;
}

void test_corretor_ortografico(void)
{
    char s[1000];
    char t[1000];
    while (scanf("%s%s", s, t) != EOF)
    {
        int x = corretor_ortografico(s,t);
        if ( x == 1 )
            printf("YES\n");
        else
            printf("NO\n");
    }
}

int main (void)
{
    test_corretor_ortografico();
    return 0;
}