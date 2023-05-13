#include "lib.h"
#include "stdio.h"

/// @brief головна функція
int main(){
	int *N1 = (int *)malloc(size * sizeof(int));
	int *N2 = (int *)malloc(size * sizeof(int));
	unsigned long int ans = 0;
	foo(N1, N2, ans);
	free(N1);
	free(N2);
	return 0;
}