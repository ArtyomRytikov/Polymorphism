#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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