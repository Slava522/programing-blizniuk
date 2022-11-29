#include <stdio.h>

int main()
{
        int input;
        int output = 0;
        int output2 = 0;
        int counter = 1;

        printf("Введіть число: ");
        scanf("%d", &input);

        while(input/counter >= 1) {
            output ++;
            counter *= 10;
	    output2 +=(input%counter)/(counter/10);
            input -=input%counter;
        }
        printf("\nКількість розрядів числа: %d", output);
        printf("\nСумма цифр числа: %d", output2);
}
