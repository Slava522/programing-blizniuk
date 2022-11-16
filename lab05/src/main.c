#include <stdio.h>

int main()
{
    int number1;
    int number2;
    int output = 0;
    
    printf("введіть перше число: ");
    scanf("%u", &number1);
    printf("введіть друге число: ");
    scanf("%u", &number2);

    for (int i = number1; i <= number2; i++) {
        output = output + i;
    }
    printf("%u", output);
    return 0;
}
