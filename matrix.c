#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "matrix.h"
Matrix create_matrix(int size, MatrixType type) 
{
    Matrix matrix;
    matrix.size = size;
    matrix.type = type;
    if (type == REAL) 
    {
        matrix.data = malloc(size * size * sizeof(Real));
    } 
    else 
    {
        matrix.data = malloc(size * size * sizeof(Complex));
    }
    return matrix;
}
void input_matrix(Matrix* matrix) 
{
    for (int i = 0; i < matrix->size; i++) 
    {
        for (int j = 0; j < matrix->size; j++) 
        {
            printf("[%d][%d]: ", i, j);
            if (matrix->type == REAL) 
            {
                scanf("%lf", &((Real*)matrix->data)[i * matrix->size + j]);
            } 
            else 
            {
                scanf("%lf %lf", &((Complex*)matrix->data)[i * matrix->size + j].re, &((Complex*)matrix->data)[i * matrix->size + j].im);
            }
        }
    }
}
void print_matrix(const Matrix* matrix) 
{
    for (int i = 0; i < matrix->size; i++) 
    {
        for (int j = 0; j < matrix->size; j++) 
        {
            if (matrix->type == REAL) 
            {
                printf("%.2lf ", ((Real*)matrix->data)[i * matrix->size + j]);
            } 
            else 
            {
                printf("%.2lf + %.2lfi ", ((Complex*)matrix->data)[i * matrix->size + j].re, ((Complex*)matrix->data)[i * matrix->size + j].im);
            }
        }
        printf("\n");
    }
}
void rand_matrix(Matrix* matrix) 
{
    for (int i = 0; i < matrix->size * matrix->size; i++) 
    {
        if (matrix->type == REAL) 
        {
            ((Real*)matrix->data)[i].value = rand() % 100;
        } 
        else 
        {
            ((Complex*)matrix->data)[i].re = rand() % 100;
            ((Complex*)matrix->data)[i].im = rand() % 100;
        }
    }
}
Matrix sum_matrix(const Matrix* matrix1, const Matrix* matrix2) 
{
    Matrix result = create_matrix(matrix1->size, matrix1->type);
    for (int i = 0; i < matrix1->size; i++) 
    {
        for (int j = 0; j < matrix1->size; j++) 
        {
            if (matrix1->type == REAL) 
            {
                ((Real*)result.data)[i * matrix1->size + j].value = ((Real*)matrix1->data)[i * matrix1->size + j].value + ((Real*)matrix2->data)[i * matrix1->size + j].value;
            } 
            else 
            {
                ((Complex*)result.data)[i * matrix1->size + j].re = ((Complex*)matrix1->data)[i * matrix1->size + j].re +((Complex*)matrix2->data)[i * matrix1->size + j].re;
                ((Complex*)result.data)[i * matrix1->size + j].im = ((Complex*)matrix1->data)[i * matrix1->size + j].im + ((Complex*)matrix2->data)[i * matrix1->size + j].im;
            }
        }
    }
    return result;
}
Matrix substr_matrix(const Matrix* matrix1, const Matrix* matrix2) 
{
    Matrix result = create_matrix(matrix1->size, matrix1->type);
    for (int i = 0; i < matrix1->size; i++) 
    {
        for (int j = 0; j < matrix1->size; j++) 
        {
            if (matrix1->type == REAL) 
            {
                ((Real*)result.data)[i * matrix1->size + j].value = ((Real*)matrix1->data)[i * matrix1->size + j].value - ((Real*)matrix2->data)[i * matrix1->size + j].value;
            } 
            else 
            {
                ((Complex*)result.data)[i * matrix1->size + j].re = ((Complex*)matrix1->data)[i * matrix1->size + j].re - ((Complex*)matrix2->data)[i * matrix1->size + j].re;
                ((Complex*)result.data)[i * matrix1->size + j].im = ((Complex*)matrix1->data)[i * matrix1->size + j].im - ((Complex*)matrix2->data)[i * matrix1->size + j].im;
            }
        }
    }
    return result;
}
Matrix multipli_matrix(const Matrix* matrix1, const Matrix* matrix2) 
{
    Matrix result = create_matrix(matrix1->size, matrix1->type);
    for (int i = 0; i < matrix1->size; i++) 
    {
        for (int j = 0; j < matrix1->size; j++) 
        {
            if (matrix1->type == REAL) 
            {
                ((Real*)result.data)[i * matrix1->size + j].value = 0;
                for (int k = 0; k < matrix1->size; k++) 
                {
                    ((Real*)result.data)[i * matrix1->size + j].value += ((Real*)matrix1->data)[i * matrix1->size + k].value * ((Real*)matrix2->data)[k * matrix1->size + j].value;
                }
            } 
            else 
            {
                ((Complex*)result.data)[i * matrix1->size + j].re = 0;
                ((Complex*)result.data)[i * matrix1->size + j].im = 0;
                for (int k = 0; k < matrix1->size; k++) 
                {
                    ((Complex*)result.data)[i * matrix1->size + j].re += ((Complex*)matrix1->data)[i * matrix1->size + k].re * ((Complex*)matrix2->data)[k * matrix1->size + j].re - ((Complex*)matrix1->data)[i * matrix1->size + k].im * ((Complex*)matrix2->data)[k * matrix1->size + j].im;

                    ((Complex*)result.data)[i * matrix1->size + j].im += ((Complex*)matrix1->data)[i * matrix1->size + k].re * ((Complex*)matrix2->data)[k * matrix1->size + j].im + ((Complex*)matrix1->data)[i * matrix1->size + k].im * ((Complex*)matrix2->data)[k * matrix1->size + j].re;
                }
            }
        }
    }
    return result;
}
Matrix trans_matrix(const Matrix* matrix) 
{
    Matrix result = create_matrix(matrix->size, matrix->type);
    for (int i = 0; i < matrix->size; i++) 
    {
        for (int j = 0; j < matrix->size; j++) 
        {
            if (matrix->type == REAL) 
            {
                ((Real*)result.data)[j * matrix->size + i].value = ((Real*)matrix->data)[i * matrix->size + j].value;
            } 
            else 
            {
                ((Complex*)result.data)[j * matrix->size + i].re = ((Complex*)matrix->data)[i * matrix->size + j].re;
                ((Complex*)result.data)[j * matrix->size + i].im = ((Complex*)matrix->data)[i * matrix->size + j].im;
            }
        }
    }
    return result;
}
Matrix scalar_multipli(const Matrix* matrix, double scalar) 
{

    Matrix result = create_matrix(matrix->size, matrix->type);
    for (int i = 0; i < matrix->size; i++) 
    {
        for (int j = 0; j < matrix->size; j++) 
        {
            if (matrix->type == REAL) 
            {
                ((Real*)result.data)[i * matrix->size + j].value = ((Real*)matrix->data)[i * matrix->size + j].value * scalar;
            } 
            else 
            {
                ((Complex*)result.data)[i * matrix->size + j].re = ((Complex*)matrix->data)[i * matrix->size + j].re * scalar;
                ((Complex*)result.data)[i * matrix->size + j].im = ((Complex*)matrix->data)[i * matrix->size + j].im * scalar;
            }
        }
    }
    return result;
}
void load_two_matrices(const char *filename, Matrix *matrix1, Matrix *matrix2, Matrix *expected_result) 
{
    FILE *file = fopen(filename, "r");
    char type[10];
    int size;
    fscanf(file, "%s", type);
    fscanf(file, "%d", &size);
    if (strcmp(type, "REAL") == 0) 
    {
        matrix1->type = REAL; 
        matrix1->size = size; 
        matrix1->data = malloc(size * size * sizeof(Real));
    } 
    else if (strcmp(type, "COMPLEX") == 0) 
    {
        matrix1->type = COMPLEX; 
        matrix1->size = size;
        matrix1->data = malloc(size * size * sizeof(Complex));
    }
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            if (matrix1->type == REAL) 
            {
                fscanf(file, "%.2lf", &((Real *)matrix1->data)[i * size + j]);
            } 
            else 
            {
                fscanf(file, "%.2lf %.2lf", &((Complex *)matrix1->data)[i * size + j].re, &((Complex *)matrix1->data)[i * size + j].im);
            }
        }
    }
    fscanf(file, "%s", type);
    fscanf(file, "%d", &size);
    if (strcmp(type, "REAL") == 0) 
    {
        matrix2->type = REAL;
        matrix2->size = size;
        matrix2->data = malloc(size * size * sizeof(Real));
    } 
    else if (strcmp(type, "COMPLEX") == 0) 
    {
        matrix2->type = COMPLEX;
        matrix2->size = size;
        matrix2->data = malloc(size * size * sizeof(Complex));
    }
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            if (matrix2->type == REAL) 
            {
                fscanf(file, "%.2lf", &((Real *)matrix2->data)[i * size + j]);
            } 
            else 
            {
                fscanf(file, "%.2lf %.2lf", &((Complex *)matrix2->data)[i * size + j].re, &((Complex *)matrix2->data)[i * size + j].im);
            }
        }
    }
    fscanf(file, "%s", type);
    fscanf(file, "%d", &size);
    
    if (strcmp(type, "REAL") == 0) 
    {
        expected_result->type = REAL;
        expected_result->size = size;
        expected_result->data = malloc(size * size * sizeof(Real));
    } 
    else if (strcmp(type, "COMPLEX") == 0) 
    {
        expected_result->type = COMPLEX;
        expected_result->size = size;
        expected_result->data = malloc(size * size * sizeof(Complex));
    }

    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            if (expected_result->type == REAL) 
            {
                fscanf(file, "%.2lf", &((Real *)expected_result->data)[i * size + j]);
            } else {
                fscanf(file, "%.2lf %.2lf", &((Complex *)expected_result->data)[i * size + j].re, &((Complex *)expected_result->data)[i * size + j].im);
            }
        }
    }
    fclose(file);
}
void save_result(const char *filename, const Matrix *result, const Matrix *expected_result) 
{
    FILE *file = fopen(filename, "a");
    fprintf(file, "\n");
    fprintf(file, "RESULT\n");
    if (result->type == REAL) 
    {
        fprintf(file, "REAL\n");
    } 
    else 
    {
        fprintf(file, "COMPLEX\n");
    }
    fprintf(file, "%d\n", result->size);
    for (int i = 0; i < result->size; i++) 
    {
        for (int j = 0; j < result->size; j++) 
        {
            if (result->type == REAL) 
            {
                fprintf(file, "%.2lf ", ((Real *)result->data)[i * result->size + j]);
            } 
            else if (result->type == COMPLEX) 
            {
                fprintf(file, "%.2lf %.2lf ", ((Complex *)result->data)[i * result->size + j].re, ((Complex *)result->data)[i * result->size + j].im);
            }
        }
        fprintf(file, "\n");
    }
    int res = 1;
    for (int i = 0; i < result->size; i++) 
    {
        for (int j = 0; j < result->size; j++) 
        {
            if (result->type == REAL) 
            {
                if (((Real *)result->data)[i * result->size + j].value != ((Real *)expected_result->data)[i * expected_result->size + j].value) 
                {
                    res = 0;
                    break;
                }
            } 
            else if (result->type == COMPLEX) 
            {
                if (((Complex *)result->data)[i * result->size + j].re != ((Complex *)expected_result->data)[i * expected_result->size + j].re || ((Complex *)result->data)[i * result->size + j].im != ((Complex *)expected_result->data)[i * expected_result->size + j].im) 
                {
                    res = 0;
                    break;
                }
            }
        }
    }
    if (res) 
    {
        fprintf(file, "Ожидаемый и полученный результаты совпали, тест пройден \n");
    } 
    else 
    {
        fprintf(file, "Ожидаемый и полученный результаты не совпали, тест не пройден\n");
    }
    fclose(file);
}
void free_matrix(Matrix matrix) 
{
    free(matrix.data);
}
void load_one_matrix(const char *filename, Matrix *matrix, Matrix *expected_result) 
{
    FILE *file = fopen(filename, "r");
    char type[10];
    int size;
    fscanf(file, "%s", type);
    fscanf(file, "%d", &size);
    if (strcmp(type, "REAL") == 0) 
    {
        matrix->type = REAL; 
        matrix->size = size; 
        matrix->data = malloc(size * size * sizeof(Real));
    } 
    else if (strcmp(type, "COMPLEX") == 0) 
    {
        matrix->type = COMPLEX; 
        matrix->size = size;
        matrix->data = malloc(size * size * sizeof(Complex));
    }
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            if (matrix->type == REAL) 
            {
                fscanf(file, "%.2lf", &((Real *)matrix->data)[i * size + j]);
            } 
            else 
            {
                fscanf(file, "%.2lf %.2lf", &((Complex *)matrix->data)[i * size + j].re, &((Complex *)matrix->data)[i * size + j].im);
            }
        }
    }
    fscanf(file, "%s", type);
    fscanf(file, "%d", &size);
    if (strcmp(type, "REAL") == 0) 
    {
        expected_result->type = REAL;
        expected_result->size = size;
        expected_result->data = malloc(size * size * sizeof(Real));
    } 
    else if (strcmp(type, "COMPLEX") == 0) 
    {
        expected_result->type = COMPLEX;
        expected_result->size = size;
        expected_result->data = malloc(size * size * sizeof(Complex));
    }

    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            if (expected_result->type == REAL) 
            {
                fscanf(file, "%.2lf", &((Real *)expected_result->data)[i * size + j]);
            } else {
                fscanf(file, "%.2lf %.2lf", &((Complex *)expected_result->data)[i * size + j].re, &((Complex *)expected_result->data)[i * size + j].im);
            }
        }
    }
    fclose(file);
}