#include <stdio.h>

int main()
{
    int input = 0;
    char Snum0[10] [15] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char Snum10[10] [15] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    char Snum20[8] [15] = {"twenty","thirty","fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    printf("Введіть число що належить проміжку [0;9999]:");
    scanf("%d", &input);
    
    if(input <= 9999 && input >= 0) {
        //чотиризначні числам
        if(input >= 1000) {
            printf("%s thouthand ", Snum0[input/1000]);
            input -= (input/1000)*1000;
            
            if(input/100 != 0) {
                printf("%s hundred ", Snum0[input/100]);
            }
            input -= (input/100)*100;
            
            if(input/10 != 0) {
                //числа від 10 до 19
                if(input/10 < 2){printf("%s ", Snum10[input - 10]);}
                
                //числа від 20 до 90
                else{printf("%s ", Snum20[input/10 - 2]);
                    input -= (input/10)*10;
                    if(input != 0) {
                        printf("%s ", Snum0[input]);
                    }
                }
            }
            
        }
        
        //трьозначні числа
        else if(input >= 100) {
            printf("%s hundred ", Snum0[input/100]);
            input -= (input/100)*100;
            
            if(input/10 != 0) {
                //числа від 10 до 19
                if(input/10 < 2){printf("%s ", Snum10[input - 10]);}
                
                //числа від 20 до 90
                else{printf("%s ", Snum20[input/10 - 2]);
                    input -= (input/10)*10;
                    if(input != 0) {
                        printf("%s ", Snum0[input]);
                    }
                }
            }
        }
        
        //двозначні числа
        else if(input >= 10) {
            if(input/10 < 2){printf("%s ", Snum10[input - 10]);}
                
            //числа від 20 до 90
            else{printf("%s ", Snum20[input/10 - 2]);
                input -= (input/10)*10;
                if(input != 0) {
                    printf("%s ", Snum0[input]);
                }
            }
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
