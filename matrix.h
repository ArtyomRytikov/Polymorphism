typedef struct 
{
    double re;
    double im;
} Complex;

typedef struct 
{
    double value;
} Real;

typedef enum 
{
    REAL, 
    COMPLEX
} MatrixType;

typedef struct 
{
    int size;
    void* data; 
    MatrixType type; 
} Matrix;

Matrix create_matrix(int size, MatrixType type); 
void input_matrix(Matrix* matrix);
void print_matrix(const Matrix* matrix);
void rand_matrix(Matrix* matrix);
Matrix sum_matrix(const Matrix* matrix1, const Matrix* matrix2);
Matrix substr_matrix(const Matrix* matrix1, const Matrix* matrix2);
Matrix multipli_matrix(const Matrix* matrix1, const Matrix* matrix2);
Matrix trans_matrix(const Matrix* matrix);
Matrix scalar_multipli(const Matrix* matrix, double scalar);