#include <stdio.h>

int main()
{
        /*input повинен бути розміром у чотири символи*/
        int input = 0000;
        int buffer = 0;
        int output = 0;

	printf("%s", "Input number(4 digits) ");
	scanf("%d", &input);

        for(int i = 1; i <= 4; i++) {
                buffer = input % 10;
                input = (input - buffer) / 10;
                output = output + buffer;
        }
        printf("%d", output);
        return 0;
}

