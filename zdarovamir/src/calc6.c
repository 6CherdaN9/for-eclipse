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

int main(int argc, char *argv[])
    {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    float a,b;
    char c;
    int m;
    m = 1;
    while(m == 1)
    {
        printf("First number:\n");
        scanf("%f",&a);
        printf("Operation(+,-,*,/,^,!):\n");
        scanf(" %c",&c);
        if (c != '!')
        {
            printf("Second number:\n");
            scanf("%f",&b);
        }
        if (c == '+')
        {
            printf("Answer:\n");
            printf("%f",a+b);
        }
        else
        {
            if (c == '-')
            {
                printf("Answer:\n");
                printf("%f",a-b);
            }
            else
            {
                if (c == '^')
                {
                    printf("Answer:\n");
                    printf("%f", power(a,b));
                }
                else
                {
                    if (c == '/')
                    {
                        printf("Answer:\n");
                        printf("%f",a/b);
                    }
                    else
                    {
                        if (c == '*')
                        {
                            printf("Answer:\n");
                            printf("%f",a*b);
                        }
                        else
                        {
                            if (c == '!')
                            {
                                printf("Answer:\n");
                                printf("%f",factorial(a));
                            }
                        }
                    }
                }
            }
        }
        printf("Do you want to continue? (0 - NO, 1 - YES)\n"); //порторение цикла работы калькулятора
        scanf("%i",&m);
    }
    return EXIT_SUCCESS;
}
