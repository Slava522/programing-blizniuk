#include "./lib.h"
#include "stdio.h"
#include <string.h>

char* num_to_char(int Input) {
    char Snum0[10] [15] = {"one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine "};
    char Snum10[10] [15] = {"ten ", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen "};
    char Snum20[8] [15] = {"twenty ","thirty ","fourty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "};
    static char output[1024];

    if(Input == 0) {strcat(output, "zero");}
    
    //тисячі
    if(Input/1000 >= 1) {
        strcat(output, Snum0[Input/1000 - 1]);
        strcat(output, "thousand ");
        Input -= Input/1000*1000;}
    
    //сотні
    if(Input/100 >= 1) {
        strcat(output, Snum0[Input/100 - 1]);
        strcat(output, "hundred ");
        Input -= Input/100*100;}
    
    //числа від 1 до 9
    if(Input < 10) {strcat(output, Snum0[Input - 1]);}
    
    //числа від 10 до 19
    else if(Input/10 < 2) {strcat(output, Snum10[Input - 10]);}
        
    //числа від 20 до 99
    else {strcat(output, Snum20[Input/10 - 2]);
        Input -= (Input/10)*10;
        if(Input != 0) {strcat(output, Snum0[Input - 1]);}
    }
    return output;
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