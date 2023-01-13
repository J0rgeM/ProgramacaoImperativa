#include <stdio.h>
#include <assert.h>

int ints_get(int *a) 
{
    int x;
    int result = 0;
    while (scanf("%d", &x) != EOF) 
    {
        a[result++] = x;
    }
    return result;
}

int ints_max(const int *a, int n)
{
    assert(n >= 0);
    int result = a[0];
    for(int i = 1; i < n; i++) //i=1
        if(result < a[i])
            result = a[i];
    return result;
}

int ints_min(const int *a, int n)
{
    assert(n >= 0);
    int result = a[0];
    for(int i = 0; i < n; i++)
        if(result > a[i])
        result = a[i];
    return result;
}

int ints_indices(const int *a, int n, int x, int *b)
{
    int result = 0;
    for(int i = 0; i < n; i++)
        if(a[i] == x)
            b[result++] = i;
    return result;
}

void ints_println_basic(const int *a, int n)
{
    if (n > 0)
    {
        printf("%d", a[0]);
        for (int i = 1; i < n; i++)
        {
            printf(" %d", a[i]);
        }
        printf("\n");
    }
    
}

int even_values_minus_odd_values (const int *a, int n) //A 
{
    int par = 0;
    int impar = 0;
    
    for (int i = 0; i < n ; i++) 
    {
        if (a[i] % 2 == 0) 
        {
            par = par + a[i];
        }
        else {
           impar = impar + a[i];
        }
    }
    int result = par - impar;
    return result;
}

void test_even_values_minus_odd_values(void) //A
{  
    int a[1000];
    int n = ints_get(a);
    int y = even_values_minus_odd_values(a, n);
    
    printf("%d\n", y);
}

void unit_test_sum(void) //A
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    assert(even_values_minus_odd_values(a, 10) == 5);
    assert(even_values_minus_odd_values(a, 8) == 4);
}

int even_positions_minus_odd_positions (const int *a, int n) //B
{
    int par = 0;
    int impar = 0;
    
    for (int i = 0; i < n ; i++) 
    {
        if (i % 2 == 0) 
        {
            par = par + a[i];
        }
        else 
        {
           impar = impar + a[i];
        }
    }
    int result = par - impar;
    return result;
}

void test_even_positions_minus_odd_positions(void) //B
{  
    int a[1000];
    int n = ints_get(a);
    int y = even_positions_minus_odd_positions(a, n);
    
    printf("%d\n", y);
}

void unit_test_sum_positions(void) //B
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    assert(even_positions_minus_odd_positions(a, 10) == -5);
    assert(even_positions_minus_odd_positions(a, 8) == -4);
}

int ints_all_equal (const int *a, int n) //C
{
    int x = ints_min(a, n);
    int y = ints_max(a ,n);
    int result;

    if( n > 0 )
    {
        if(x == y)
        {
            result = 1;
        }
        else
        {
            result = 0;
        }    
    }
    else
    {
        result = 1;
    }
    return result;
}   

void test_ints_all_equal(void) //C
{  
    int a[1000];
    int n = ints_get(a);
    int y = ints_all_equal(a, n);
    
    printf("%d\n", y);
}

void unit_test_ints_all_equal(void) //C
{
    int a[10] = {1,1,1,1,1,1,1,1,2,2};
    assert(ints_all_equal(a, 10) == 0);
    assert(ints_all_equal(a, 8) == 1);
}

int ints_second_max(const int *a, int n) //D
{
    assert(a[0] != a[1] && n > 1);
    int second_max = a[0];
    int max = ints_max(a,n);

    for(int i = 0; i < n; i++)
    {
        if(second_max < a[i] && max > a[i])
        {
            second_max = a[i];
        }
        else if(second_max >= a[i] && max == a[i])
        {
            second_max = 0;
        }
    }
    return second_max;
}

void test_ints_second_max(void) //D
{  
    int a[1000];
    int n = ints_get(a);
    int y = ints_second_max(a, n);
    
    printf("%d\n", y);
}

void unit_test_ints_second_max(void) //D
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    assert(ints_second_max(a, 10) == 9);
    assert(ints_second_max(a, 8) == 7);
}

 void test_ints_argmax(void)
 {
    int a[1000];
    int b[1000];
    int n = ints_get(a);
    int max = ints_max(a, n);
    int y = ints_indices(a, n, max, b);
    
    ints_println_basic(b, y);
 }

void unit_test_ints_argmax(void) //E
{
    int a[10] = {1,2,3,4,5,2,5,3,4,5};
    int b[10];
    int max = ints_max(a, 10);
    int max2 = ints_max(a, 4);
    assert(ints_indices(a, 10, max, b) == 3);
    assert(ints_indices(a, 8, max, b) == 2);
    assert(ints_indices(a, 4, max2, b) == 1);
}


void unit_tests(void) 
{
    unit_test_sum();
    unit_test_sum_positions();
    unit_test_ints_all_equal();
    unit_test_ints_second_max();
    unit_test_ints_argmax();
}

int main (void) 
{
    unit_tests();
    //test_even_values_minus_odd_values();
    //test_even_positions_minus_odd_positions();
    //test_ints_all_equal();
    //test_ints_second_max();
    test_ints_argmax();
    return 0;
}