#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib.h"

int input = INPUT;

int main()
{
    printf("Введіть число що належить проміжку [0;9999]:");
    //scanf("%d", &input);
    
    printf("Сумма цифр числа: %d \n", summ(input));
    printf("Кількість розрядів числа: %d \n", ammount(input));
    printf("%s", num_to_char(input));

    return 0;
}
