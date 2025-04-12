#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include <locale.h>
#include <string.h>
int main()
{
    setlocale(LC_ALL, "ru_RU.UTF-8");
    int menu, size, action_menu, rand_self, type;
    printf("1.Работа с двумя матрицами\n");
    printf("2.Работа с одной матрицей\n");
    printf("3.Тест функций\n");
    printf("Выберете номер количества матриц с которым хотите работать: \n");
    scanf("%d", &menu);
    if (menu == 1)
    {
        printf("Выберите как вы хотите получать матрицы\n");
        printf("1.Ввести матрицы самому\n");
        printf("2.Сгенерировать рандомно\n");
        printf("Выберите номер действия от 1 до 2: \n");
        scanf("%d", &rand_self);
        printf("Введите размер матриц от 2 до 5: \n");
        scanf("%d", &size);
        printf("Введите с каким типом матриц вы хотите работать:\n");
        printf("1.С вещесвтенными элементами \n");
        printf("2.С комплексными элементами \n");
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
            printf("Введите действительную и мнимую части:(число 'пробел' число)\n");
            matrix1 = create_matrix(size, COMPLEX);
            matrix2 = create_matrix(size, COMPLEX);
        }
        if (rand_self== 1)
        {
            printf("Первая матрица %d x %d:\n", size, size);
            input_matrix(&matrix1);
            print_matrix(&matrix1);
            printf("Вторая матрица %d x %d:\n", size, size);
            input_matrix(&matrix2);
            print_matrix(&matrix2);
        }
        if (rand_self == 2)
        {
            printf("Первая матрица:\n");
            rand_matrix(&matrix1);
            print_matrix(&matrix1);
            printf("Вторая матрица:\n");
            rand_matrix(&matrix2);
            print_matrix(&matrix2);
        }
        printf("Список операций, которые можно провести над матрицами:\n");
        printf("1.Сложение матриц\n");
        printf("2.Вычитание матриц\n");
        printf("3.Произведение матриц\n");
        printf("Выберите номер операции от 1 до 3:\n");
        scanf("%d", &action_menu);
        if (action_menu == 1)
        {
            printf("Результат сложений двух матриц : \n");
            Matrix sum = sum_matrix(&matrix1, &matrix2);
            print_matrix(&sum);
        }
        if (action_menu == 2)
        {
            printf("Результат вычитания двух матриц : \n");
            Matrix substr = substr_matrix(&matrix1, &matrix2);
            print_matrix(&substr);
        }
        if (action_menu == 3)
        {
            printf("Результат произведения двух матриц : \n");
            Matrix result = multipli_matrix(&matrix1, &matrix2);
            print_matrix(&result);
        }
    }
    if (menu == 2)
    {
        printf("Выберите как вы хотите получать матрицу\n");
        printf("1.Ввести матрицу самому\n");
        printf("2.Сгенерировать рандомно\n");
        printf("Выберите номер действия от 1 до 2: \n");
        scanf("%d", &rand_self);
        printf("Введите размер матриц от 2 до 5: \n");
        scanf("%d", &size);
        printf("Введите с каким типом матрицы вы хотите работать:\n");
        printf("1.С вещесвтенными элементами\n");
        printf("2.С комплексными элементами\n");
        printf("Выберите номер действия от 1 до 2: \n");
        scanf("%d", &type);
        Matrix matrix;
        if (type == 1)
        {
            matrix = create_matrix(size, REAL);
        }
        else if (type == 2)
        {
            printf("Введите действительную и мнимую части:(число 'пробел' число)\n");
            matrix = create_matrix(size, COMPLEX);
        }
        if (rand_self == 1)
        {
            printf("Ваша матрица %d x %d:\n", size, size);
            input_matrix(&matrix);
            print_matrix(&matrix);
        }
        if (rand_self == 2)
        {
            printf("Сгенерированная матрица:\n");
            rand_matrix(&matrix);
            print_matrix(&matrix);
        }
        printf("Операция, которую можно провести над матрицей:\n");
        printf("1.Транспонирование\n");
        printf("2.Умножение матрциы на число\n");
        printf("Введите номер операции:\n");
        scanf("%d", &action_menu);
        if (action_menu == 1)
        {
            printf("Результат транспонирования:\n");
            Matrix result = trans_matrix(&matrix);
            print_matrix(&result);

        }
        if (action_menu == 2)
        {
            printf("Введите число на которое хотите умножить матрицу\n");
            double scalar;
            scanf("%lf", &scalar);
            printf("Результат умножения матрицы на число:\n");
            Matrix result = scalar_multipli(&matrix, scalar);
            print_matrix(&result);
        }
    }
    if (menu == 3)
    {
        printf("1.Тестирование суммы\n");
        printf("2.Тестирование разности\n");
        printf("3.Тестирование произведения\n");
        printf("4.Тестирование произведения на скаляр\n");
        printf("1.Тестирование транспонирования\n");
        printf("Выберети операцию над которой хотите провести тесты(введите число от 1-5): ");
        int test_number;
        scanf("%d", &test_number);
        Matrix matrix1, matrix2, expected_result;
        if(test_number == 1)
        {
            load_matrices("sumtest.txt", &matrix1, &matrix2, &expected_result);
            Matrix result = sum_matrix(&matrix1, &matrix2); 
            save_result("sumtest.txt", &result, &expected_result);
            free_matrix(result);
        }
        if(test_number == 2)
        {
            load_matrices("substrtest.txt", &matrix1, &matrix2, &expected_result);
            Matrix result = substr_matrix(&matrix1, &matrix2); 
            save_result("substrtest.txt", &result, &expected_result);
            free_matrix(result);
        }
        if(test_number == 3)
        {
            load_matrices("multiplitest.txt", &matrix1, &matrix2, &expected_result);
            Matrix result = multipli_matrix(&matrix1, &matrix2); 
            save_result("matrixtest.txt", &result, &expected_result);
            free_matrix(result);
        }
        free_matrix(matrix1);
        free_matrix(matrix2);
        free_matrix(expected_result);
    }
    return 0;
}