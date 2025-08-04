#include <stdio.h>

#define MAX 100

// Function to compute the transpose of a matrix
void transposeMatrix(int matrix[MAX][MAX], int transpose[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int rows, cols;
    int matrix[MAX][MAX], transpose[MAX][MAX];

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // Input matrix
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("Element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Call the function to compute transpose
    transposeMatrix(matrix, transpose, rows, cols);

    // Display transposed matrix
    printf("\nTranspose of the matrix:\n");
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}
