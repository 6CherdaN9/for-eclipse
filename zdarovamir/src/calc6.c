/*
 ============================================================================
 Name        : calc
 Author      : Vovchik
 Version     : 6
 Copyright   : mya
 Description : калькулятор, включающий в себя 6 арифметических операций над числами и 3 над векторами
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

    float *a, *b, res, e, d;
    int size, repeat, operation, type;
    char c;
    repeat = 1;
    while (repeat == 1)
        {
        printf("Variable Type:\n"); // Выбор с чем будет проводится работа
        printf("1. The numbers\n");
        printf("2. The vectors\n");
        scanf("%i", &type);

        if (type == 2){
            res = 0;
            printf("Enter the size of the vectors: "); // ввод колличества координат в векторах
            scanf("%i", &size);
            a = malloc(size*sizeof(int));
            b = malloc(size*sizeof(int));
        printf("Enter the coordinates of the first vector: "); // координаты первого вектора
        for (int i=0; i < size; i++) scanf("%f", &a[i]);
        printf("Enter the coordinates of the second vector: "); // координаты второго вектора
        for (int i=0; i < size; i++) scanf("%f", &b[i]);
        printf("Select operation\n"); // выбор операции
        printf("1. Vector addition\n");
        printf("2. Vector difference\n");
        printf("3. Scalar product of vectors\n");
        scanf("%i", &operation);
        if (operation == 1){
           printf("Answer:\n");
           for (int i=0; i < size; i++) printf("%.2f ", a[i]+b[i]); // сложение векоров
        }
        else if (operation == 2){
            printf("Answer:\n");
            for (int i=0; i < size; i++) printf("%.2f ", a[i]-b[i]); // разность векторов
        }
        else if (operation == 3) {
            printf("Answer:\n");
            for (int i=0; i < size; i++) res = a[i] * b[i] + res; // вектороное произведение векторов
            printf("%.2f ", res);
        }
        free(a);
        free(b);
        printf("\nDo you want to continue? (0 - NO, 1 - YES)\n"); //порторение цикла работы калькулятора
        scanf("%i",&repeat);
        }
    else{
        printf("First number:\n"); // ввод первого числа
        scanf("%f",&e);
        printf("Operation(+,-,*,/,^,!):\n"); // ввод операции
        scanf(" %c",&c);
        if (c != '!'){ // проверка на операцию (если факториал, то вводится только одно число)
            printf("Second number:\n"); // ввод второго числа
            scanf("%f",&d);
        }
        if (c == '+'){
            printf("Answer:\n"); // результат суммы
            printf("%.2f",e+d);
        }
            else{
                    if (c == '-'){ // результат разности
                        printf("Answer:\n");
                        printf("%.2f",e-d);
                    }
                    else{
                        if (c == '^'){ // результат возведения в степень
                            printf("Answer:\n");
                            printf("%.2f", power(e,d));
                        }
                        else{
                            if (c == '/'){
                                if (d == 0){
                                    printf("This operation is not valid\n");
                                }
                                else{
                                        printf("Answer:\n"); // результат деления
                                        printf("%.2f",e/d);
                                    }
                            }
                            else{
                                if (c == '*'){
                                    printf("Answer:\n"); // результат умножения
                                    printf("%.2f",e*d);
                                }
                                else{
                                    if (c == '!'){
                                        if (e < 0){ // проверка числа. если меньше нуля, то операция не выполяется
                                            printf("This operation is not valid\n");

                                        }
                                        else{
                                                printf("Answer:\n"); // результат вычисления факториала
                                                printf("%.2f",factorial(e));
                                            }
                                    }
                                }
                            }
                        }
                    }
                }
                printf("\nDo you want to continue? (0 - NO, 1 - YES)\n"); //порторение цикла работы калькулятора
                scanf("%i",&operation);
            }
        }
    return EXIT_SUCCESS;
}
