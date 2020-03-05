/*
 ============================================================================
 Name        : calc
 Author      : Vovchik
 Version     : 6
 Copyright   : mya
 Description : калькулятор, включающий в себя 6 арифметических операций
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

float factorial(int n)  //функция для вычисления факториала(n - число)
{
    float res;
    int i;
    res = 1;
    i = 1;
    while (i != (n + 1))
    {
        res = res * i; //пишу этот комментарий с сайта github
        i++;
    }
    return(res);
}

float power(float x, float y)  //функция для вычисления степени(x - число, y - степень)
{
    float res;
    int i;
    res = 1;
    i = 0;
    while (i < y)
    {
        res = res * x;
        i++;
    }
    if (y < 0)
    {
        res = 1/res;
    }
    return(res);
}

int main(int argc, char *argv[]) // тело программы
    {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    float a,b;
    char c;
    int m;
    m = 1;
    while(m == 1) // цикл для повторения работы калькудятора
    {
        printf("First number:\n"); // ввод первого числа
        scanf("%f",&a);
        printf("Operation(+,-,*,/,^,!):\n"); // ввод операции
        scanf(" %c",&c);
        if (c != '!') // проверка на операцию (если факториал, то вводится только одно число)
        {
            printf("Second number:\n"); // ввод второго числа
            scanf("%f",&b);
        }
        if (c == '+')
        {
            printf("Answer:\n"); // результат суммы
            printf("%.2f",a+b);
        }
        else
        {
            if (c == '-') // результат разности
            {
                printf("Answer:\n");
                printf("%.2f",a-b);
            }
            else
            {
                if (c == '^') // результат возведения в степень
                {
                    printf("Answer:\n");
                    printf("%.2f", power(a,b));
                }
                else
                {
                    if (c == '/') // результат деления
                    {
                        if (b == 0) // проверка второго числа(делителя) на равность нулю
                        {
                            printf("This operation is not valid\n");
                        }
                        else
                            {
                                printf("Answer:\n"); // результат деления
                                printf("%.2f",a/b);
                            }
                    }
                    else
                    {
                        if (c == '*')
                        {
                            printf("Answer:\n"); // результат умножения
                            printf("%.2f",a*b);
                        }
                        else
                        {
                            if (c == '!')
                            {
                                if (a < 0) // проверка числа. если меньше нуля, то операция не выполяется
                                {
                                    printf("This operation is not valid\n");

                                }
                                else
                                    {
                                        printf("Answer:\n"); // результат вычисления факториала
                                        printf("%.2f",factorial(a));
                                    }
                            }
                        }
                    }
                }
            }
        }
        printf("\nDo you want to continue? (0 - NO, 1 - YES)\n"); //порторение цикла работы калькулятора
        scanf("%i",&m);
    }
    return EXIT_SUCCESS;
}
