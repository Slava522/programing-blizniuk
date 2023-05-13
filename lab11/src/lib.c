#include "lib.h"
#include "stdio.h"
#include <string.h>
/// @brief Main function that counts and writes down consequitive numbers from the input array
/// @param N1 Input array
/// @param ans answer or output
void foo(int* N1, int* N2, unsigned long int ans){
	*(N1 + 0) = 4;
	*(N1 + 1) = 2;
	*(N1 + 2) = 2;
	*(N1 + 3) = 5;
	*(N1 + 4) = 3;
	*(N1 + 5) = 3;
	*(N1 + 6) = 3;
	*(N1 + 7) = 9;
	*(N1 + 8) = 7;
	*(N1 + 9) = 7;
	*(N1 + 10) = 4;
	for(int j = 0; j < size; j++){
		if (*(N1 + j) == *(N1 + j + 1)){
			*(N2 + ans) = *(N1 + j);
			*(N2 + ans + 1) = *(N1 + j + 1);
			ans++;
			ans++;
			if (*(N1 + j + 1) == *(N1 + j + 2)){
				j++;
			}
		}
	}
	int *tr = (int *)malloc(ans * sizeof(int));
	for (unsigned long int j = 0; j < ans; j++){
		*(tr + j) = *(N2 + j);
	}
	printf("Результат: ");
	for (unsigned long int j = 0; j < ans; j++){
		printf("%d", *(tr + j));
	}
	free(tr);
}