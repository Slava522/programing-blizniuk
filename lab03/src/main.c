#include <stdio.h>

int main()
{
        /*input повинен бути розміром у чотири символи*/
        int input = 2111;
        int buffer = 0;
        int buffer1 = 0;
        int output = 0;

        buffer1 = input;
        for(int i = 1; i <= 4; i++) {
                buffer = buffer1 % 10;
                buffer1 = (buffer1 - buffer) / 10;
                output = output + buffer;
        }
        printf("%d", output);
        return 0;
}

