/*
 ============================================================================
 Name        : calc
 Author      : Vovchik
 Version     : номер весрии потерялся во времени
 Copyright   : mya
 Description : калькулятор, включающий в себя 6 арифметических операций над числами и 3 над векторами
               данные для операций берутся из файла и записываются в файл
               перед запуском прочтите "readme.txt"
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
        res = res * i;
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

    FILE *input, *output;
    char type, operation;
    float a, b, *x1, *x2, res;
    int size;
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");

    fscanf(input, "%c",&type);
    fscanf(input, " %c",&operation);
    switch(type){ // сделал через switch case так как это оказалось проще
    case 's': // работа с числами
        switch(operation){
        case '+': // ну тут все просто сложение, вычитание так далее
            fscanf(input, " %f %f",&a,&b);
            fprintf(output, "(%.2f + %.2f) = %.2f", a, b, a+b);
            break;
        case '-':
            fscanf(input, " %f %f",&a,&b);
            fprintf(output, "(%.2f - %.2f) = %.2f", a, b, a-b);
            break;
        case '*':
            fscanf(input, " %f %f",&a,&b);
            fprintf(output, "(%.2f * %.2f) = %.2f", a, b, a*b);
            break;
        case '/':
            fscanf(input, " %f %f",&a,&b);
            if (b != 0) fprintf(output, "(%.2f / %.2f) = %.2f", a, b, a/b);
            else fprintf(output, "This operation is not valid");
            break;
        case '^':
            fscanf(input, " %f %f",&a,&b);
            fprintf(output, "%.2f ^ %.2f = %.2f", a, b, power(a,b));
            break;
        case '!':
            fscanf(input, "%f",&a);
            if (a >= 0) fprintf(output, "%.0f! = %.0f", a, factorial(a));
            else fprintf(output, "This operation is not valid");
            break;
        default:
            fprintf(output, "Unknown operation");
        }
        break;
    case 'v':  // работа с векторами
        res = 0;
        fscanf(input, "%i",&size);
        x1 = malloc(size*sizeof(int));
        x2 = malloc(size*sizeof(int));
        for (int i=0; i < size; i++) fscanf(input, "%f", &x1[i]);
        for (int i=0; i < size; i++) fscanf(input, "%f", &x2[i]);
        switch(operation){
        case '+':
            for (int i=0; i < size; i++) fprintf(output, "%.2f ", x1[i]+x2[i]);
            free(x1); // вставил это в каждое действие, так как когда я вставлял в конец программы эклипс ругался ¯\_(ツ)_/¯
            free(x2);
            break;
        case '-':
            for (int i=0; i < size; i++) fprintf(output, "%.2f ", x1[i]-x2[i]);
            free(x1);
            free(x2);
            break;
        case '*':   // скалярное произведение векторов
            for (int i=0; i < size; i++) res = x1[i] * x2[i] + res;
            fprintf(output, "%.2f ", res);
            free(x1);
            free(x2);
            break;
        default:
            fprintf(output, "Unknown operation");
        }
        break;
    default:
        fprintf(output, "Unknown data type");
    }
    fclose(input);
    fclose(output);
}
