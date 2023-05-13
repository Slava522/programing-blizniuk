#include <stdio.h>

int input = 0;
char Snum0[10] [15] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char Snum10[10] [15] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
char Snum20[8] [15] = {"twenty","thirty","fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};

//числа від 10 до 99
void To99() {
    if(input/10 != 0) {
        //числа від 10 до 19
        if(input/10 < 2){printf("%s ", Snum10[input - 10]);}
                
        //числа від 20 до 90
        else{printf("%s ", Snum20[input/10 - 2]);
            input -= (input/10)*10;
            if(input != 0) {printf("%s ", Snum0[input]);}
            }
    }
}

int summ(int Input)
{
        int output = 0;
        int counter = 1;

        while(Input/counter >= 1) {
            counter *= 10;
	    output +=(Input%counter)/(counter/10);
            Input -=Input%counter;
        }
        return output;
}

int ammount(int Input)
{
        int output = 0;
        int counter = 1;

        while(Input/counter >= 1) {
            output ++;
            counter *= 10;
            Input -=Input%counter;
        }
        return output;
}

int main()
{
    printf("Введіть число що належить проміжку [0;9999]:");
    scanf("%d", &input);
    
    printf("Сумма цифр числа: %d \n", summ(input));
    printf("Кількість розрядів числа: %d \n", ammount(input));
    
    if(input <= 9999 && input >= 0) {
        //чотиризначні числам
        if(input >= 1000) {
            printf("%s thouthand ", Snum0[input/1000]);
            input -= (input/1000)*1000;
            
            if(input/100 != 0) {
                printf("%s hundred ", Snum0[input/100]);
            }
            input -= (input/100)*100;
            
            To99();
            
        }
        
        //трьозначні числа
        else if(input >= 100) {
            printf("%s hundred ", Snum0[input/100]);
            input -= (input/100)*100;
            
            To99();
        }
        
        //двозначні числа
        else if(input >= 10) {
            To99();
        }
        
        //однозначні числа
        else {
            printf("%s ", Snum0[input]);
        }
        
    }
    
    else {
        printf("Введене число не належить проміжку [0;9999]");
    }

    return 0;
}
