#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include <locale.h>
#include <string.h>
int main() 
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int menu = 0;
    while (1) 
    {
        printf("1. Работа с двумя матрицами\n");
        printf("2. Работа с одной матрицей\n");
        printf("3. Тест функций\n");
        printf("4. Выход\n");
        printf("Выберите номер количества матриц с которым хотите работать: ");
        while (1) 
        {
            if (scanf("%d", &menu) != 1) 
            {
                printf("Ошибка ввода. Пожалуйста, введите число от 1 до 4: ");
                while (getchar() != '\n');
                continue;
            }
            if (menu < 1 || menu > 4) 
            {
                printf("Неверный ввод. Пожалуйста, введите число от 1 до 4: ");
                continue;
            }
            break;
        }
        if (menu == 4) break;
        int size = 0;
        int action_menu = 0;
        int rand_self = 0;
        int type = 0;
        if (menu == 1) 
        {
            while (1) 
            {
                printf("\nВыберите как вы хотите получать матрицы\n");
                printf("1. Ввести матрицы самому\n");
                printf("2. Сгенерировать рандомно\n");
                printf("3. Вернуться в главное меню\n");
                printf("Выберите номер действия от 1 до 3: ");
                while (1) 
                {
                    if (scanf("%d", &rand_self) != 1) 
                    {
                        printf("Ошибка ввода. Пожалуйста, введите число от 1 до 3: ");
                        while (getchar() != '\n');
                        continue;
                    }
                    if (rand_self < 1 || rand_self > 3) 
                    {
                        printf("Неверный ввод. Пожалуйста, введите число от 1 до 3: ");
                        continue;
                    }
                    break;
                }
                if (rand_self == 3) break;
                printf("Введите размер матриц от 2 до 5: ");
                while (1) 
                {
                    if (scanf("%d", &size) != 1) 
                    {
                        printf("Ошибка ввода. Пожалуйста, введите число от 2 до 5: ");
                        while (getchar() != '\n');
                        continue;
                    }
                    if (size < 2 || size > 5) 
                    {
                        printf("Неверный размер. Пожалуйста, введите число от 2 до 5: ");
                        continue;
                    }
                    break;
                }
                printf("Введите с каким типом матриц вы хотите работать:\n");
                printf("1. С вещественными элементами \n");
                printf("2. С комплексными элементами \n");
                printf("Выберите номер действия от 1 до 2: ");
                while (1) {
                    if (scanf("%d", &type) != 1) 
                    {
                        printf("Ошибка ввода. Пожалуйста, введите 1 или 2: ");
                        while (getchar() != '\n');
                        continue;
                    }
                    if (type < 1 || type > 2) {
                        printf("Неверный ввод. Пожалуйста, введите 1 или 2: ");
                        continue;
                    }
                    break;
                }
                Matrix matrix1, matrix2;
                if (type == 1) 
                {
                    matrix1 = create_matrix(size, REAL);
                    matrix2 = create_matrix(size, REAL);
                } 
                else 
                {
                    matrix1 = create_matrix(size, COMPLEX);
                    matrix2 = create_matrix(size, COMPLEX);
                }
                if (rand_self == 1) 
                {
                    printf("\nПервая матрица %d x %d:\n", size, size);
                    input_matrix(&matrix1);
                    print_matrix(&matrix1);
                    printf("\nВторая матрица %d x %d:\n", size, size);
                    input_matrix(&matrix2);
                    print_matrix(&matrix2);
                }
                else 
                {
                    printf("\nПервая матрица:\n");
                    rand_matrix(&matrix1);
                    print_matrix(&matrix1);
                    printf("\nВторая матрица:\n");
                    rand_matrix(&matrix2);
                    print_matrix(&matrix2);
                }
                printf("\nСписок операций, которые можно провести над матрицами:\n");
                printf("1. Сложение матриц\n");
                printf("2. Вычитание матриц\n");
                printf("3. Произведение матриц\n");
                printf("4. Вернуться в главное меню\n");
                printf("Выберите номер операции от 1 до 4: ");
                while (1) 
                {
                    if (scanf("%d", &action_menu) != 1) 
                    {
                        printf("Ошибка ввода. Пожалуйста, введите число от 1 до 4: ");
                        while (getchar() != '\n');
                        continue;
                    }
                    if (action_menu < 1 || action_menu > 4) 
                    {
                        printf("Неверный ввод. Пожалуйста, введите число от 1 до 4: ");
                        continue;
                    }
                    break;
                }
                if (action_menu == 4) 
                {
                    free_matrix(matrix1);
                    free_matrix(matrix2);
                    break;
                } 
                else if (action_menu == 1) 
                {
                    printf("\nРезультат сложения двух матриц:\n");
                    Matrix sum = sum_matrix(&matrix1, &matrix2);
                    print_matrix(&sum);
                    free_matrix(sum);
                } 
                else if (action_menu == 2) 
                {
                    printf("\nРезультат вычитания двух матриц:\n");
                    Matrix substr = substr_matrix(&matrix1, &matrix2);
                    print_matrix(&substr);
                    free_matrix(substr);
                } 
                else if (action_menu == 3) 
                {
                    printf("\nРезультат произведения двух матриц:\n");
                    Matrix result = multipli_matrix(&matrix1, &matrix2);
                    print_matrix(&result);
                    free_matrix(result);
                }
                free_matrix(matrix1);
                free_matrix(matrix2);
            }
        }
        if (menu == 2) 
        {
            while (1) 
            {
                printf("\nВыберите как вы хотите получать матрицу\n");
                printf("1. Ввести матрицу самому\n");
                printf("2. Сгенерировать рандомно\n");
                printf("3. Вернуться в главное меню\n");
                printf("Выберите номер действия от 1 до 3: ");
                while (1) 
                {
                    if (scanf("%d", &rand_self) != 1) 
                    {
                        printf("Ошибка ввода. Пожалуйста, введите число от 1 до 3: ");
                        while (getchar() != '\n');
                        continue;
                    }
                    if (rand_self < 1 || rand_self > 3) 
                    {
                        printf("Неверный ввод. Пожалуйста, введите число от 1 до 3: ");
                        continue;
                    }
                    break;
                }
                if (rand_self == 3) break;
                printf("Введите размер матрицы от 2 до 5: ");
                while (1) 
                {
                    if (scanf("%d", &size) != 1) 
                    {
                        printf("Ошибка ввода. Пожалуйста, введите число от 2 до 5: ");
                        while (getchar() != '\n');
                        continue;
                    }
                    if (size < 2 || size > 5) 
                    {
                        printf("Неверный размер. Пожалуйста, введите число от 2 до 5: ");
                        continue;
                    }
                    break;
                }
                printf("Введите с каким типом матрицы вы хотите работать:\n");
                printf("1. С вещественными элементами\n");
                printf("2. С комплексными элементами\n");
                printf("Выберите номер действия от 1 до 2: ");
                while (1) 
                {
                    if (scanf("%d", &type) != 1) 
                    {
                        printf("Ошибка ввода. Пожалуйста, введите 1 или 2: ");
                        while (getchar() != '\n');
                        continue;
                    }
                    if (type < 1 || type > 2) 
                    {
                        printf("Неверный ввод. Пожалуйста, введите 1 или 2: ");
                        continue;
                    }
                    break;
                }
                Matrix matrix;
                if (type == 1) 
                {
                    matrix = create_matrix(size, REAL);
                } 
                else 
                {
                    matrix = create_matrix(size, COMPLEX);
                }

                if (rand_self == 1) 
                {
                    printf("\nВаша матрица %d x %d:\n", size, size);
                    input_matrix(&matrix);
                    print_matrix(&matrix);
                }
                else 
                {
                    printf("\nСгенерированная матрица:\n");
                    rand_matrix(&matrix);
                    print_matrix(&matrix);
                }
                printf("\nОперация, которую можно провести над матрицей:\n");
                printf("1. Транспонирование\n");
                printf("2. Умножение матрицы на число\n");
                printf("3. Вернуться в главное меню\n");
                printf("Введите номер операции: ");
                while (1) 
                {
                    if (scanf("%d", &action_menu) != 1) 
                    {
                        printf("Ошибка ввода. Пожалуйста, введите число от 1 до 3: ");
                        while (getchar() != '\n');
                        continue;
                    }
                    if (action_menu < 1 || action_menu > 3) 
                    {
                        printf("Неверный ввод. Пожалуйста, введите число от 1 до 3: ");
                        continue;
                    }
                    break;
                }
                if (action_menu == 3) 
                {
                    free_matrix(matrix);
                    break;
                } 
                else if (action_menu == 1) 
                {
                    printf("\nРезультат транспонирования:\n");
                    Matrix result = trans_matrix(&matrix);
                    print_matrix(&result);
                    free_matrix(result);
                } 
                else if (action_menu == 2) 
                {
                    printf("\nВведите число на которое хотите умножить матрицу: ");
                    double scalar;
                    while (scanf("%lf", &scalar) != 1) 
                    {
                        printf("Ошибка ввода. Пожалуйста, введите число: ");
                        while (getchar() != '\n');
                    }
                    printf("\nРезультат умножения матрицы на число:\n");
                    Matrix result = scalar_multipli(&matrix, scalar);
                    print_matrix(&result);
                    free_matrix(result);
                }
                free_matrix(matrix);
            }
        }
        if (menu == 3) 
        {
            while (1) 
            {
                printf("\n1. Тестирование суммы\n");
                printf("2. Тестирование разности\n");
                printf("3. Тестирование произведения\n");
                printf("4. Тестирование транспонирования\n");
                printf("5. Тестирование умножения на скаляр\n");
                printf("6. Вернуться в главное меню\n");
                printf("Выберите операцию, над которой хотите провести тесты (введите число от 1-6): ");
                int test_number;
                while (1) 
                {
                    if (scanf("%d", &test_number) != 1) 
                    {
                        printf("Ошибка ввода. Пожалуйста, введите число от 1 до 6: ");
                        while (getchar() != '\n');
                        continue;
                    }
                    if (test_number < 1 || test_number > 6) 
                    {
                        printf("Неверный ввод. Пожалуйста, введите число от 1 до 6: ");
                        continue;
                    }
                    break;
                }
                if (test_number == 6) break;
                Matrix matrix, matrix1, matrix2, expected_result;
                if (test_number == 1) 
                {
                    load_two_matrices("sumtest.txt", &matrix1, &matrix2, &expected_result);
                    Matrix result_sum = sum_matrix(&matrix1, &matrix2);
                    save_result("sumtest.txt", &result_sum, &expected_result);
                    free_matrix(result_sum);
                } 
                else if (test_number == 2) 
                {
                    load_two_matrices("substrtest.txt", &matrix1, &matrix2, &expected_result);
                    Matrix result_substr = substr_matrix(&matrix1, &matrix2);
                    save_result("substrtest.txt", &result_substr, &expected_result);
                    free_matrix(result_substr);
                } 
                else if (test_number == 3) 
                {
                    load_two_matrices("multiplitest.txt", &matrix1, &matrix2, &expected_result);
                    Matrix result_mult = multipli_matrix(&matrix1, &matrix2);
                    save_result("multiplitest.txt", &result_mult, &expected_result);
                    free_matrix(result_mult);
                } 
                else if (test_number == 4) 
                {
                    load_one_matrix("transtest.exe", &matrix, &expected_result);
                    Matrix result_trans = trans_matrix(&matrix);
                    save_result("transtest.txt", &result_trans, &expected_result);
                    free_matrix(result_trans);
                } 
                else if (test_number == 5) 
                {
                    double scalar;
                    printf("\nВведите число на которое хотите умножить матрицу: ");
                    while (scanf("%lf", &scalar) != 1) 
                    {
                        printf("Ошибка ввода. Пожалуйста, введите число: ");
                        while (getchar() != '\n');
                    }
                    load_one_matrix("scalartest.exe", &matrix, &expected_result);
                    Matrix result_scalar = scalar_multipli(&matrix, scalar);
                    save_result("scalartest.txt", &result_scalar, &expected_result);
                    free_matrix(result_scalar);
                }
                free_matrix(matrix1);
                free_matrix(matrix2);
                free_matrix(expected_result);
            }
        }
    }
    return 0;
}