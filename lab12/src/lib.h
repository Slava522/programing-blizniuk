#define SIZE 256

#define ROWS 2
#define COLS 2

#define OPEN_FILE_ERROR -3 

#include <locale.h>
#include <stdlib.h>
#include <stdio.h>

/// @brief Displays brief information about program
void display_info();

/// @brief allows user to fill the matrix
void fill_matrix(int **m);

/// @brief prints out a matrix
void print_matrix(int **m);

/// @brief frees allocated space from  matrix
void free_matrix(int **m);

/// @brief allocates memory for the matrix
int **get_matrix();

/// @brief adds matrix a to b
int **add_matrix(int **a, int **b);