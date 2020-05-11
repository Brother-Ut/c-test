#include <stdio.h>
#include <conio.h>
#include "main.h"

int CheckForExit(char *outChar, inputType type)
{
    char ch = 0;

    switch (type){

        case NUMBER:

            do{
                ch = getch();
                
                // возвращаем признак нажатия Enter
                if (ch == 13 || ch == 10)
                    return 1;
                
                // возвращаем признак нажатия Esc
                if (ch == 27)
                    return -1;
            
            } while ( !(ch >= '0' && ch <= '9'));

            // записываем введенную цифру
            *outChar = ch;

            // выводим цифру в терминал
            printf("%c", ch);
            
            // возвращаем признак введенной цифры
            return 0;

        case OPERATION:

            while (1) {
                ch = getch();

                // возвращаем признак нажатия Esc
                if (ch == 27)
                    return -1;

                // ждем валидный символ арифметической операции
                if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
                {
                    // записываем введенную операцию
                    *outChar = ch;
                    
                    // выводим операцию в терминал
                    printf("%c", ch);

                    // возвращаем признак успешно введенного типа арифмитической операции
                    return 0;
                }
            }

        default: 
            break;

    }
}