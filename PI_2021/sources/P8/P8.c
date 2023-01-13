#include <stdio.h>
#include <assert.h>
#include "our_ints.h"

//--------------------Problema A-------------------------------
int ints_greater_than (const int *a, int n, int *b, int x) 
{
	int contador = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > x) {
			b[contador++] = a[i];
		}
	}
	return contador;
}

void test_ints_greater_than (void)
{
	int a[1000];
	int n = ints_get_until(-1, a);
	int b[1000];
	int x;
	while (scanf("%d", &x) != EOF) {
		int y = ints_greater_than(a, n, b, x);
		ints_println_special(b, y);
	}
}

void unit_test_ints_greater_than(void) 
{
	int a1[10] = {1,2,3,4,5,6,7,8,9,10};
	int b[10];
	assert(ints_greater_than(a1, 10, b, 5) == 5 && b[0] == 6 && b[1] == 7 && b[2] == 8 && b[3] == 9 && b[4] == 10);
	assert(ints_greater_than(a1, 10, b, 8) == 2 && b[0] == 9 && b[1] == 10);
	assert(ints_greater_than(a1, 10, b, 9) == 1 && b[0] == 10);
	int a2[10] = {2,5,4,3,6,7,8,9,9,10};
	assert(ints_greater_than(a2, 10, b, 6) == 5 && b[0] == 7 && b[1] == 8 && b[2] == 9 && b[3] == 9 && b[4] == 10);
}

// -------------------Problema B-----------------------------
int ints_less_than (const int *a, int n, int *b, int x) 
{
	int contador = 0;
	for (int i = 0; i < n; i++) 
	{
		if (a[i] < x) 
		{
			b[contador++] = a[i];
		}
	}
	
	return contador;
}

void test_ints_less_than (void) 
{
	int a[1000];
	int n = ints_get_until(-1, a);
	int b[1000];
	int x;
	while (scanf("%d", &x) != EOF) 
	{
		int y = ints_less_than(a, n, b, x);
		ints_println_special(b, y);
	}
}

void unit_test_ints_less_than(void) 
{
	int a3[10] = {1,2,3,4,5,6,7,8,9,10};
	int b1[10];
	assert(ints_less_than(a3, 10, b1, 2) == 1 && b1[0] == 1);
	assert(ints_less_than(a3, 10, b1, 1) == 0);
	int a4[10] = {3,4,5,2,34,56,76,54,3,0};
	assert(ints_less_than(a4, 10, b1, 1) == 1 && b1[0] == 0);
	assert(ints_less_than(a4, 10, b1, 3) == 2 && b1[0] == 2 && b1[1] == 0);
}



// ----------------Problema C--------------------------
int digits_sum (const int *a, int n, int *b) 
{
	int contador = 0;
	int y;
	int p;
	for (int i = 0; i < n; i++) 
	{
		p = a[i];
		y = 0;
		while (p > 0) 
		{
			y += p%10;
			p = p/10;
		}
		b[contador++] = y;
	}
	return contador;
}

void test_digits_sums (void) 
{
	int a[1000];
	int n = ints_get_until(-1, a);
	int b[1000];
	int m = digits_sum(a, n, b);
	ints_println_special(b, m);
}

void unit_test_digits_sums (void) 
{
	int a5[10] = {12, 35, 432, 1, 9, 0, 79, 90, 1000, 98};
	int b2[10];
	assert(digits_sum(a5, 2, b2) == 2 && b2[0] == 3 && b2[1] == 8);
	assert(digits_sum(a5, 3, b2) == 3 && b2[0] == 3 && b2[1] == 8 && b2[2] == 9);
	int a6[4] = {5848, 848, 1, 0};
	int b3[4];
	assert(digits_sum(a6, 3, b3) == 3 && b3[0] == 25 && b3[1] == 20 && b3[2] == 1);
	assert(digits_sum(a6, 1, b3) == 1 && b3[0] == 25);
}



// -----------------------Problema D--------------------------------------
int ints_append (const int *a, int n, const int *b, int m, int *c) 
{
	int result = 0;
	for (int i = 0; i < n+m; i++) 
	{
		if (i < n) {
			c[result++] = a[i];
		}
		else 
		{
			c[result++] = b[i-n];
		}
	}
	return result;
}

void test_ints_append (void)
 {
	int a[1000];
	int b[1000];
	int c[2000];
	int n = ints_get_until(-1, a);
	int m = ints_get_until(-1, b);
	int y = ints_append (a, n, b, m, c);
	ints_println_special(c, y);
	int w = ints_append (b, m, a, n, c);
	ints_println_special(c, w);
}

void unit_test_ints_append (void)
 {
	int a7[5] = {1,2,3,4,5};
	int b4[5] = {1,2,3,4,5};
	int c[10];
	assert(ints_append(a7, 1, b4, 1, c) == 2 && c[0] == 1 && c[1] == 1);
	assert(ints_append(a7, 2, b4, 2, c) == 4 && c[0] == 1 && c[1] == 2 && c[2] == 1 && c[3] == 2);
	assert(ints_append(b4, 1, a7, 2, c) == 3 && c[0] == 1 && c[1] == 1 && c[2] == 2);
	assert(ints_append(b4, 2, a7, 3, c) == 5 && c[0] == 1 && c[1] == 2 && c[2] == 1 && c[3] == 2 && c[4] == 3);
}


// ------------------Problema E--------------------------
int ints_fill_elem (const int *a, int n, int *b)
 {
	int result = 0;
	for (int i = 0; i < n; i++) 
	{
		b[result++] = a[i];
	}
	return result;
}

int ints_take (const int *a, int n, int *b, int x) 
{
	int result;
	if (x > 0 && x < n) {
		result = ints_fill_elem(a, x, b);
	}
	else if (x >= n) {
		result = ints_fill_elem(a, n, b);
	}
	else {
		result = 0;
	}
	return result;
}

void test_ints_take (void)
 {
	int a[1000];
	int n = ints_get_until(-1, a);
	int b[1000];
	int x;
	while (scanf("%d", &x) != EOF) 
	{
		int m = ints_take(a, n, b, x);
		ints_println_special(b, m);
	}
}

void unit_test_ints_take (void) 
{
	int a[5] = {1,2,3,4,5};
	int b[5];
	assert(ints_take(a, 2, b, 3) == 2 && b[0] == 1 && b[1] == 2);
	assert(ints_take(a, 3, b, 6) == 3 && b[0] == 1 && b[1] == 2 && b[2] == 3);
	assert(ints_take(a, 4, b, -1) == 0);
	assert(ints_take(a, 4, b, 3) == 3 && b[0] == 1 && b[1] == 2);
}


// --------------------Problema F-------------------------
int ints_fill_F(const int *a, int n, int *b, int x) 
{
	int result = 0;
	for (int i = x; i < n; i++) 
	{
		b[result++] = a[i];
	}
	return result;
}


int ints_drop (const int *a, int n, int *b, int x) 
{
	int result;
	if (x >= 0 && x < n) 
	{
		result = ints_fill_F(a, n, b, x);
	}
	else if (x < 0)
	 {
		x = 0;
		result = ints_fill_F(a, n, b, x);
	}
	else 
	{
		result = 0;
	}
	return result;
}

void test_ints_drop (void)
 {
	int a[1000];
	int n = ints_get_until(-1, a);
	int b[1000];
	int x;
	while (scanf("%d", &x) != EOF)
	 {
		int m = ints_drop(a, n, b, x);
		ints_println_special(b, m);
	}
}

void unit_test_ints_drop (void) 
{
	int a[5] = {1,2,3,4,5};
	int b[5];
	assert(ints_drop(a, 5, b, 4) == 1 && b[0] == 5);
	assert(ints_drop(a, 5, b, -1) == 5 && b[0] == 1 && b[1] == 2 && b[2] == 3 && b[3] == 4 && b[4] == 5);
	assert(ints_drop(a, 5, b, 6) == 0);
	assert(ints_drop(a, 0, b, 0) == 0);
}


//------------------------Problema G--------------------
int ints_ascending (const int *a, int n, int *b) 
{
	b[0] = a[0];
	int result = 1;
	if (n <= 0) 
	{
		result = 0;
	}
	else 
	{
		for (int i = 1; i < n; i++) 
		{
			
			if (a[i] >= ints_max(a, i)) 
			{
				b[result++] = a[i];
			}
		}
	}
	return result;
}

void test_ints_ascending (void) 
{
	int a[1000];
	int b[1000];
	int n = ints_get_until (-1, a);
	int m = ints_ascending (a, n, b);
	ints_println_special(b, m);
}

void unit_test_ints_ascending(void) 
{
	int a[5] = {3,5,2,8,6};
	int b[6];
	assert(ints_ascending(a, 5, b) == 3 && b[0] == 3 && b[1] == 5 && b[2] == 8);
	assert(ints_ascending(a, 1, b) == 1 && b[0] == 3);
	int a1[10] = {5,3,6,6,9,7,5,6,2,1};
	assert(ints_ascending(a1, 10, b) == 4 && b[0] == 5 && b[1] == 6 && b[2] == 6 && b[3] == 9);
	assert(ints_ascending(a1, 4, b) == 3 && b[0] == 5 && b[1] == 6 && b[2] == 6);
}


// ----------------------Problema H--------------------
int ints_accumulate (const int *a, int n, int *b) 
{	
	int result = 0;
	
		for (int i = 0; i <= n; i++) 
		{
			b[result++] = ints_sum(a, i);
		}
	return result;
}

void test_ints_accumulate (void)
 {
	int a[1000];
	int b[1001];
	int n = ints_get_until(-1, a);
	int m = ints_accumulate(a, n, b);
	ints_println_special(b, m);
}

void unit_test_ints_accumulate (void) 
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int b[10];
	assert(ints_accumulate(a, 2, b) == 3 && b[0] == 0 && b[1] == 1 && b[2] == 3);
	assert(ints_accumulate(a, 5, b) == 6 && b[0] == 0 && b[1] == 1 && b[2] == 3 && b[3] == 6 && b[4] == 10 && b[5] == 15);
	assert(ints_accumulate(a, 3, b) == 4 && b[0] == 0 && b[1] == 1 && b[2] == 3 && b[3] == 6 && b[4] == 10);
	assert(ints_accumulate(a, 1, b) == 2 && b[0] == 0 && b[1] == 1);
}


//-----------------------Problema I---------------------
int ints_unaccumulate (const int *a, int n, int *b)
 {
	int result = 0;
	if (a[0] != 0) 
	{
		result = 0;
	}
	else 
	{
		for (int i = 1; i < n; i++)
		 {
			b[result++] = a[i] - a[i-1];
		}
	}
	return result;
}

void test_ints_unaccumulate (void) 
{
	int a[1000];
	int b[1000];
	int n = ints_get_until(-1, a);
	int m = ints_unaccumulate(a, n, b);
	ints_println_special(b, m);
}

void unit_test_ints_unaccumulate (void) 
{
	int a[10] = {0,5,6,10,11,14,18};
	int b[10];
	assert(ints_unaccumulate(a, 0, b) == 0);
	assert(ints_unaccumulate(a, 5, b) == 4 && b[0] == 5 && b[1] == 1 && b[2] == 4 && b[3] == 1);
	int a1[10] = {0,7,2,5,8,2,5,1,0,9};
	assert(ints_unaccumulate(a1, 3, b) == 2 && b[0] == 7 && b[1] == -5);
	assert(ints_unaccumulate(a1, 10, b) == 9 && b[0] == 7 && b[1] == -5 && b[2] == 3 && b[3] == 3 && b[4] == -6 && b[5] == 3 && b[6] == -4 && b[7] == -1 && b[8] == 9);
}


//------------------------Problema J-----------------
int ints_find_triple (const int *a, int n) 
{
	int result = -1;
	for (int i = 0; i < n-2; i++) 
	{
		if (a[i] == a[i+1] && a[i] == a[i+2]) 
		{
			return i;
		}
	}
	return result;
}

void test_ints_find_triple (void)
{
	int a[1000];
	int n = ints_get_until(-1, a);
	int m = ints_find_triple(a, n);
	if (m >= 0) 
	{
		printf("%d\n", m);
	}
	else
	 {
		printf("-1\n");
	}
	
}

void unit_test_ints_find_triple (void) 
{
	int a[10] = {1,2,3,3,3,4,1,2,2,2};
	assert(ints_find_triple(a, 3) == -1);
	assert(ints_find_triple(a, 5) == 2);
	int a1[10] = {1,1,1,5,2,9,9,9,7};
	assert(ints_find_triple(a1, 4) == 0);
	assert(ints_find_triple(a1, 10) == 0);
}

void unit_tests(void) 
{
	unit_test_ints_greater_than(); //problema A
	unit_test_ints_less_than(); //exercicio B	
	unit_test_digits_sums(); //exercicio C
	unit_test_ints_append(); //exercicio D	
	unit_test_ints_take(); //exercicio E	
	test_ints_drop(); //exercicio F	
	unit_test_ints_ascending(); //exercicio G	
	unit_test_ints_accumulate(); //exercicio H
	unit_test_ints_unaccumulate(); //exercicio I
	unit_test_ints_find_triple(); //exercicio J
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
		test_ints_greater_than();
	}
	else if (x == 'B') 
	{
		test_ints_less_than();
	}
	else if (x == 'C') 
	{
		test_digits_sums();
	}
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
	}
	else if (x == 'G') 
	{
		test_ints_ascending();
	}
	else if (x == 'H') 
	{
		test_ints_accumulate();
	}
	else if (x == 'I') 
	{
		test_ints_unaccumulate();
	}
	else if (x == 'J') 
	{
		test_ints_find_triple();
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