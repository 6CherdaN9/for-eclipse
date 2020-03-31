/*
 ============================================================================
 Name        : calculator
 Author      : Vovchik
 Version     : итоговая
 Copyright   : mya
 Description : калькулятор, включающий в себя 6 арифметических операций над числами и 3 над векторами
               данные для операций берутся из файла и записываются в файл 
               либо берутся из консоли и выводятся туда же
               перед запуском прочтите "readme.txt"
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

float factorial(int n){  //функция для вычисления факториала(n - число)
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

float power(float x, float y){  //функция для вычисления степени(x - число, y - степень)
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

int main(int argc, char *argv[]){
    FILE *input, *output;
    char type, operation, work, repeat, infname[100], outfname[100];
    float a, b, *x1, *x2, res; 
    int size;

    repeat = 'y';

    while (repeat == 'y'){

        printf("What do you want to work with? ( f - file / c - console ): ");
        scanf(" %c", &work);
        switch(work){
            case 'f':
            
                printf("Enter input file name: ");
                scanf("%s", infname);
                printf("Enter output file name: ");
                scanf("%s", outfname);

                input = fopen(infname, "r");
                output = fopen(outfname, "w");

                fscanf(input, "%c", &type);
                fscanf(input, " %c", &operation);
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
                                fprintf(output, "( ");
                                for (int i=0; i < size; i++) fprintf(output, "%.2f ", x1[i]);
                                fprintf(output, " ) + ( ");
                                for (int i=0; i < size; i++) fprintf(output, "%.2f ", x2[i]);
                                fprintf(output, " ) = ( ");
                                for (int i=0; i < size; i++) fprintf(output, "%.2f ", x1[i]+x2[i]);
                                fprintf(output, " )");
                                free(x1); // вставил это в каждое действие, так как когда я вставлял в конец программы эклипс ругался ¯\_(ツ)_/¯
                                free(x2);
                               break;
                            case '-':
                                fprintf(output, "( ");
                                for (int i=0; i < size; i++) fprintf(output, "%.2f ", x1[i]);
                                fprintf(output, " ) - ( ");
                                for (int i=0; i < size; i++) fprintf(output, "%.2f ", x2[i]);
                                fprintf(output, " ) = ( ");
                                for (int i=0; i < size; i++) fprintf(output, "%.2f ", x1[i]-x2[i]);
                                fprintf(output, " )");
                                free(x1);
                                free(x2);
                                break;
                            case '*':   // скалярное произведение векторов
                                fprintf(output, "( ");
                                for (int i=0; i < size; i++) fprintf(output, "%.2f ", x1[i]);
                                fprintf(output, " ) * ( ");
                                for (int i=0; i < size; i++) fprintf(output, "%.2f ", x2[i]);
                                fprintf(output, " ) = ");
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
                        break;
            case 'c':
                
                printf("Variable type:\n"); // Выбор с чем будет проводится работа
                printf("1. The numbers\n");
                printf("2. The vectors\n");
                scanf(" %c", &type);

                if (type == '2'){
                    res = 0;
                    printf("Enter the size of the vectors: "); // ввод колличества координат в векторах
                    scanf("%i", &size);
                    x1 = malloc(size*sizeof(int));
                    x2 = malloc(size*sizeof(int));
                    printf("Enter the coordinates of the first vector: "); // координаты первого вектора
                    for (int i=0; i < size; i++) scanf("%f", &x1[i]);
                    printf("Enter the coordinates of the second vector: "); // координаты второго вектора
                    for (int i=0; i < size; i++) scanf("%f", &x2[i]);
                    printf("Select operation:\n"); // выбор операции
                    printf("1. Vector addition\n");
                    printf("2. Vector difference\n");
                    printf("3. Scalar product of vectors\n");
                    scanf(" %c", &operation);
                    if (operation == '1'){
                        printf("Answer:\n");
                        printf("(");
                        for (int i=0; i < size; i++) printf("%.2f ", x1[i]+x2[i]); // сложение векоров
                        printf(")\n");
                    }
                    else if (operation == '2'){
                        printf("Answer:\n");
                        printf("(");
                        for (int i=0; i < size; i++) printf("%.2f ", x1[i]-x2[i]); // разность векторов
                        printf(")\n");
                    }
                    else if (operation == '3') {
                        printf("Answer:\n");
                        for (int i=0; i < size; i++) res = x1[i] * x2[i] + res; // скалярное произведение векторов
                        printf("%.2f \n", res);
                    }
                    free(x1);
                    free(x2);
                }
                else if (type == '1'){
                    printf("First number:\n"); // ввод первого числа
                    scanf("%f",&a);
                    printf("Operation(+,-,*,/,^,!):\n"); // ввод операции
                    scanf(" %c",&operation);
                    if (operation != '!'){ // проверка на операцию (если факториал, то вводится только одно число)
                        printf("Second number:\n"); // ввод второго числа
                        scanf("%f",&b);
                    }
                    if (operation == '+'){
                        printf("Answer:\n"); // результат суммы
                        printf("%.2f\n",a+b);
                    }
                    else if (operation == '-'){ // результат разности
                        printf("Answer:\n");
                        printf("%.2f\n",a-b);
                    }
                    else if (operation == '^'){ // результат возведения в степень
                        printf("Answer:\n");
                        printf("%.2f\n", power(a,b));
                        }
                    else if (operation == '/'){
                        if (b == 0) printf("This operation is not valid\n");
                        else{
                            printf("Answer:\n"); // результат деления
                            printf("%.2f\n",a/b);
                            }
                        }
                    else if (operation == '*'){
                        printf("Answer:\n"); // результат умножения
                        printf("%.2f\n",a*b);
                    }
                    else if (operation == '!'){
                        if (a < 0) printf("This operation is not valid\n"); // проверка числа. если меньше нуля, то операция не выполяется
                        else{
                            printf("Answer:\n"); // результат вычисления факториала
                            printf("%.2f\n",factorial(a));
                        }
                    }
                }
                else printf("Unknown type\n");
            }
    printf("Do you want to countinue? (y/n)");
    scanf(" %c", &repeat);
    }
    return EXIT_SUCCESS;
}
