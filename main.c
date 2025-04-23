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
        printf("Выберите номер количества матриц с которым хотите работать: \n");

        if (scanf("%d", &menu) != 1) 
        {
            printf("Ошибка ввода. Попробуйте снова.\n");
            continue;
        }

        if (menu < 1 || menu > 4) 
        {
            printf("Неверный выбор. Пожалуйста, выберите номер от 1 до 4.\n");
            continue;
        }

        if (menu == 4) 
        {
            break;
        }

        int size = 0;
        int action_menu = 0;
        int rand_self = 0;
        int type = 0;

        if (menu == 1) 
        {
            while (1) 
            {
                printf("Выберите как вы хотите получать матрицы\n");
                printf("1. Ввести матрицы самому\n");
                printf("2. Сгенерировать рандомно\n");
                printf("3. Вернуться в главное меню\n");
                printf("Выберите номер действия от 1 до 3: \n");
                
                if (scanf("%d", &rand_self) != 1) 
                {
                    printf("Ошибка ввода. Попробуйте снова.\n");
                    continue;
                }

                if (rand_self == 3) 
                {
                    break; // Возврат в главное меню
                }

                printf("Введите размер матриц от 2 до 5: \n");
                scanf("%d", &size);
                if (size < 2 || size > 5) 
                {
                    printf("Неверный размер матрицы. Размер должен быть от 2 до 5.\n");
                    continue;
                }

                printf("Введите с каким типом матриц вы хотите работать:\n");
                printf("1. С вещественными элементами \n");
                printf("2. С комплексными элементами \n");
                printf("Выберите номер действия от 1 до 2: \n");
                scanf("%d", &type);

                Matrix matrix1, matrix2;
                if (type == 1) 
                {
                    matrix1 = create_matrix(size, REAL);
                    matrix2 = create_matrix(size, REAL);
                } 
                else if (type == 2) 
                {
                    matrix1 = create_matrix(size, COMPLEX);
                    matrix2 = create_matrix(size, COMPLEX);
                } 
                else 
                {
                    printf("Некорректный тип матрицы.\n");
                    continue;
                }

                if (rand_self == 1) 
                {
                    printf("Первая матрица %d x %d:\n", size, size);
                    input_matrix(&matrix1);
                    print_matrix(&matrix1);
                    printf("Вторая матрица %d x %d:\n", size, size);
                    input_matrix(&matrix2);
                    print_matrix(&matrix2);
                }
                else if (rand_self == 2) 
                {
                    printf("Первая матрица:\n");
                    rand_matrix(&matrix1);
                    print_matrix(&matrix1);
                    printf("Вторая матрица:\n");
                    rand_matrix(&matrix2);
                    print_matrix(&matrix2);
                }

                printf("Список операций, которые можно провести над матрицами:\n");
                printf("1. Сложение матриц\n");
                printf("2. Вычитание матриц\n");
                printf("3. Произведение матриц\n");
                printf("4. Вернуться в главное меню\n");
                printf("Выберите номер операции от 1 до 4:\n");
                scanf("%d", &action_menu);

                if (action_menu == 4) 
                {
                    break;
                } 
                else if (action_menu == 1) 
                {
                    printf("Результат сложения двух матриц : \n");
                    Matrix sum = sum_matrix(&matrix1, &matrix2);
                    print_matrix(&sum);
                    free_matrix(sum);
                } 
                else if (action_menu == 2) 
                {
                    printf("Результат вычитания двух матриц : \n");
                    Matrix substr = substr_matrix(&matrix1, &matrix2);
                    print_matrix(&substr);
                    free_matrix(substr);
                } 
                else if (action_menu == 3) 
                {
                    printf("Результат произведения двух матриц : \n");
                    Matrix result = multipli_matrix(&matrix1, &matrix2);
                    print_matrix(&result);
                    free_matrix(result);
                } 
                else 
                {
                    printf("Некорректный выбор операции.\n");
                }

                free_matrix(matrix1);
                free_matrix(matrix2);
            }
        }

        if (menu == 2) 
        {
            while (1) 
            {
                printf("Выберите как вы хотите получать матрицу\n");
                printf("1. Ввести матрицу самому\n");
                printf("2. Сгенерировать рандомно\n");
                printf("3. Вернуться в главное меню\n");
                printf("Выберите номер действия от 1 до 3: \n");
                
                if (scanf("%d", &rand_self) != 1) 
                {
                    printf("Ошибка ввода. Попробуйте снова.\n");
                    continue;
                }

                if (rand_self == 3) 
                {
                    break; // Возврат в главное меню
                }

                printf("Введите размер матрицы от 2 до 5: \n");
                scanf("%d", &size);
                if (size < 2 || size > 5) 
                {
                    printf("Неверный размер матрицы. Размер должен быть от 2 до 5.\n");
                    continue;
                }

                printf("Введите с каким типом матрицы вы хотите работать:\n");
                printf("1. С вещественными элементами\n");
                printf("2. С комплексными элементами\n");
                printf("Выберите номер действия от 1 до 2: \n");
                scanf("%d", &type);

                Matrix matrix;
                if (type == 1) 
                {
                    matrix = create_matrix(size, REAL);
                } else if (type == 2) 
                {
                    matrix = create_matrix(size, COMPLEX);
                }
                else 
                {
                    printf("Некорректный тип матрицы.\n");
                    continue;
                }

                if (rand_self == 1) 
                {
                    printf("Ваша матрица %d x %d:\n", size, size);
                    input_matrix(&matrix);
                    print_matrix(&matrix);
                }
                else if (rand_self == 2) 
                {
                    printf("Сгенерированная матрица:\n");
                    rand_matrix(&matrix);
                    print_matrix(&matrix);
                }

                printf("Операция, которую можно провести над матрицей:\n");
                printf("1. Транспонирование\n");
                printf("2. Умножение матрицы на число\n");
                printf("3. Вернуться в главное меню\n");
                printf("Введите номер операции:\n");
                scanf("%d", &action_menu);

                if (action_menu == 3) 
                {
                    break;
                } 
                else if (action_menu == 1) 
                {
                    printf("Результат транспонирования:\n");
                    Matrix result = trans_matrix(&matrix);
                    print_matrix(&result);
                    free_matrix(result);
                } 
                else if (action_menu == 2) 
                {
                    printf("Введите число на которое хотите умножить матрицу\n");
                    double scalar;
                    scanf("%lf", &scalar);
                    printf("Результат умножения матрицы на число:\n");
                    Matrix result = scalar_multipli(&matrix, scalar);
                    print_matrix(&result);
                    free_matrix(result);
                } 
                else 
                {
                    printf("Некорректный выбор операции.\n");
                }

                free_matrix(matrix);
            }
        }

        if (menu == 3) 
        {
            while (1) 
            {
                printf("1. Тестирование суммы\n");
                printf("2. Тестирование разности\n");
                printf("3. Тестирование произведения\n");
                printf("4. Тестирование транспонирования\n");
                printf("5. Тестирование умножения на скаляр\n");
                printf("6. Вернуться в главное меню\n");
                printf("Выберите операцию, над которой хотите провести тесты (введите число от 1-6): ");
                
                int test_number;
                if (scanf("%d", &test_number) != 1) 
                {
                    printf("Ошибка ввода. Попробуйте снова.\n");
                    continue;
                }

                if (test_number == 6) 
                {
                    break;
                }

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
                    printf("Введите число на которое хотите умножить матрицу\n");
                    scanf("%lf", &scalar);
                    load_one_matrix("scalartest.exe", &matrix, &expected_result);
                    Matrix result_scalar = scalar_multipli(&matrix, scalar);
                    save_result("scalartest.txt", &result_scalar, &expected_result);
                    free_matrix(result_scalar);
                } 
                else 
                {
                    printf("Некорректный выбор теста.\n");
                }

                free_matrix(matrix1);
                free_matrix(matrix2);
                free_matrix(expected_result);
            }
        }
    }

    return 0;
}