#include <stdio.h>
#include <assert.h>
#include "our_ints.h"
#include "our_doubles.h"

int prenda_natal(const int *a, int n, int x)
{
    int result = 0;
    for(int i = 0; i < n; i++)
    {
        result += a[i]/x;
    }
    return result;
}

void test_prenda_natal(void)
{   
    int x;
    scanf("%d", &x);
    int a[1000];
    int n = ints_get_until(-1,a);
    printf("%d\n", prenda_natal(a,n,x));
}

void unit_test_prenda_natal(void)
{
    int a[6] = {7,3,2,5,6,10};
    int x = 3;
    assert(prenda_natal(a,6,x) == 9);
}

// -------------------- Exercício C -----------
int bitonico(const int *a, int n)
{
    int result = 0;
    for(int i = 1; i < n-1; i++)
    {
        if(a[i] > a[i-1]) //crescer
        {
            if(a[i] > a[i+1]) //desce
            {
                result += 1;
            }
        } else
        {
            if(a[i] < a[i+1]) //crescer
            {
                result += 1;
            }    
        }      
    } return result;
}

void test_bitonico(void)
{
    int a[1000];
    int n = ints_get_until(-1,a);
    int y = bitonico(a,n);
    if(y > 1)
    {
       printf("desordenado\n");

    }else
    {
      printf("bitónico\n");     
    }

}

void unit_test_bitonico(void)
{
    int a1[7] = {2,5,8,14,10,8,2};
    int a2[8] = {8,3,2,5,89,120,500,501};
    int a3[4] = {7,9,1,6};
    assert(bitonico(a1,7) == 1);
    assert(bitonico(a2,8) == 1);
    assert(bitonico(a3,4) == 2);
}

void unit_tests (void) 
{
	//exercicio A
	unit_test_prenda_natal();
	//exercicio B
	//Test_B();
	//exercicio C
	unit_test_bitonico();
	/*//exercicio D
	Test_D();
	//exercicio E
	Test_E();
	//exercicio F
	Test_F();*/
}

int main (int argc, char **argv)
 {
	unit_tests();
	int x = 'A';
	if (argc > 1)
    {
		x = *argv[1];
	}
	if (x == 'A') 
    {
		test_prenda_natal();
	}
	//else if (x == 'B')
    // {
	//	test_ints_less_than();
	//}
	else if (x == 'C') 
    {
		test_bitonico();
	}/*
	else if (x == 'D')
     {
		test_ints_append();
	}
	else if (x == 'E') 
    {
		test_ints_take();
	}
	else if (x == 'F') 
    {
		test_ints_drop();
	}*/
	else if (x == 'U')
     {
		printf("All unit tests PASSED.\n");
	}
	else {
		printf("%s: Invalid option.\n", argv[1]);
	}
	return 0;
}