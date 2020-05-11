#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "main.h"

// ----------------------------------------------------------------------------------------------------------------------------------------
// Секция объявления глобальных переменных
// ----------------------------------------------------------------------------------------------------------------------------------------

// переменные хранения буффера и длины символьного представления первого числа
char* firstNumberBuffer;
int   firstNumberLength = 0;

// первое число 
int firstNumber = 0;

// переменные хранения буффера и длины символьного представления второго числа
char* secondNumberBuffer;
int   secondNumberLength = 0;

// второе число 
int secondNumber = 0;


// ----------------------------------------------------------------------------------------------------------------------------------------
// Функция суммирования
// ----------------------------------------------------------------------------------------------------------------------------------------
int Add (int a, int b)
{
    return a + b;
}

// ----------------------------------------------------------------------------------------------------------------------------------------
// Функция вычитания
// ----------------------------------------------------------------------------------------------------------------------------------------
int Subtract (int a, int b)
{
    return a - b;
}

// ----------------------------------------------------------------------------------------------------------------------------------------
// Функция преобразования строки в число
// ----------------------------------------------------------------------------------------------------------------------------------------
int StrToNumber (char* buf, int len)
{
    int result = 0;

    int pos = 1;
    int i;
    for (i = len; i > 0; i--, pos = pos * 10)
    {
        result += (buf[i-1] - '0') * pos;
    }
    return result;
}

// ----------------------------------------------------------------------------------------------------------------------------------------
// Функция очистки и сброса артефактов арифмитеческой операции
// ----------------------------------------------------------------------------------------------------------------------------------------
static void CleanUp()
{
    firstNumberLength = 0;
    secondNumberLength = 0;
    free(firstNumberBuffer);
    free(secondNumberBuffer);
}

// ----------------------------------------------------------------------------------------------------------------------------------------
// Главная функция 
// ----------------------------------------------------------------------------------------------------------------------------------------
int main()
{
    printf("\nCalculator start!");

    // переменная для контроля завершения работы калькулятора
    int isBreak = 0;

    // переменная для хранения результатов выполнения вспомогательных функций
    int statusCode = 0;

    // переменная для хранения введенного символа 
    char ch;

    // запускаем нитку выполнения (бесконечный цикл с выходом по условию)
    while (1)
    {
        printf("\n---------------------------------------------------------------");
        
        // первая функциональность - требуется ввести первое число
        printf("\nEnter a first number: ");

        // запускаем нитку последовательного считывания цифр пока не нажат Enter (число введено) либо ESС (выходим из калькулятора)
        do
        {
            // читаем символ
            statusCode = CheckForExit(&ch, NUMBER);
            if (statusCode == 0)
            {
                firstNumberLength++;
                if (firstNumberLength == 1)
                    firstNumberBuffer = (char*)malloc(sizeof(char));
                else
                    firstNumberBuffer = realloc(firstNumberBuffer, firstNumberLength * sizeof(char));
                firstNumberBuffer[firstNumberLength - 1] = ch;
            }

        } while (statusCode == 0);

        // если Ecs обрываем арифмитескую операцию
        if (statusCode == -1)
            break;

        // переводим первое число из символьного представления в цифровое
        firstNumber = StrToNumber(firstNumberBuffer, firstNumberLength);

        // вторая функциональность - требуется ввести второе число
        printf("\nEnter a second number: ");

        // запускаем нитку последовательного считывания цифр пока не нажат Enter (число введено) либо ESС (выходим из калькулятора)
        do
        {
            // читаем символ
            statusCode = CheckForExit(&ch, NUMBER);
            if (statusCode == 0)
            {
                secondNumberLength++;
                if (secondNumberLength == 1)
                    secondNumberBuffer = (char*)malloc(sizeof(char));
                else
                    secondNumberBuffer = realloc(secondNumberBuffer, secondNumberLength * sizeof(char));
                secondNumberBuffer[secondNumberLength - 1] = ch;
            }

        } while (statusCode == 0);

        // если Ecs обрываем арифмитескую операцию
        if (statusCode == -1)
            break;

        // переводим второе число из символьного представления в цифровое
        secondNumber = StrToNumber(secondNumberBuffer, secondNumberLength);

        // третья функциональность - выбор арифметической операции
        
        printf("\nEnter a type of operation: ");
        
        // читаем символ
        statusCode = CheckForExit(&ch, OPERATION);

        // если операция
        if (statusCode == 0)
        {
            int result = 0;
            switch (ch)
            {
                case '+' : 
                    result = Add(firstNumber, secondNumber); 
                    break;
                case '-' : 
                    result = Subtract(firstNumber, secondNumber);
                    break;
                case '*' :
                    result = Multiply(firstNumber, secondNumber); 
                    break;
                case '/' : 
                    result = Divide(firstNumber, secondNumber);
                    break;
                default: printf("5"); break;
            };
            
            // выводим результат
            printf("\nThe result is %d", result);  
            
            // чистим
            CleanUp();   
        }
        else 
        {
            break;
        }

    } 

    // был нажат Esc - чистим и завершаем работу
    CleanUp();
    printf("\nCalculator stop!");
    return 0;
}


