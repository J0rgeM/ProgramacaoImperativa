#include <stdio.h>
#include <assert.h>
#include "our_ints.h"
#include "our_doubles.h"


int ints_count_while (const int *a, int n) {
	int result = 0;
	int z = a[result] * a[result+1];
	while (result < (n - 1) && (a[result] * a[result+1] >= 0)) {
		result++;
	}
	return result;
}

int penalti (const int *a, int n, int *b) {
	int result = 0;
	int i = 0;
	while (i < n) {
		int z = ints_count_while(a + i, n - i);
		b[result++] = z;
		i += z;
	}
	return result;
}


void test_penalti (void) {
	int a[1000];
	int n = ints_get(a);
	int b[1000];
	int m = penalti (a, n, b);
	ints_println_special(b, m);
}


int main (void) {
	test_penalti();
	return 0;
}