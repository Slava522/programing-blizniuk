/*завдання20: порахувати:
        довжину окружності, якщо команда – 'l';
        площу кола, якщо команда – 's';
        об’єм кулі, якщо команда – 'v'.*/

#include <stdio.h>

int main() {
        float r;
        char command[] = "q";
        float output = 1.5f;
        printf("Введіть радіус: ");
        scanf("%f", &r);
        printf("--------Команди-------- \nL - довжина окружності \nS - площа кола \nV - об’єм кулі \n----------------------- \n");
        scanf("%s", command);
        switch(command[0]) {
            case 'l': case 'L': output = 2*r;  break;
            case 's': case 'S': output = r*r;  break;
            case 'v': case 'V': output = (4*r*r*r)/3;  break;
            default:    printf("такої команди немає");   break;
        }
        printf("%2.2f",output);
        printf("n");
        return 0;
        }
