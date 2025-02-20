// Creating box filter and storing avg values in diagonal...
#include <stdio.h>

void calculate_and_replace(float matrix_m[][10], int m) {
    // Temporary 3x3 matrix
    float temp_matrix[3][3];

    // Traverse through each possible 3x3 box...
    for (int i = 0; i < m - 2; i++) {   // Traverse the row.
        for (int j = 0; j < m - 2; j++) {  // Traverse the column upto m-3
            float sum = 0;
            
            // Fill the temporary 3x3 matrix and calculate the sum
            for (int r = i; r < i + 3; r++) {           //we will go from i to i+3 as size is of 3*3
                for (int c = j; c < j + 3; c++) {
                    temp_matrix[r - i][c - j] = matrix_m[r][c];
                    sum += matrix_m[r][c];
                }
            }
            
            // Calculate the average of the 3x3 box as a float
            float avg = sum / 9.0;       
            
            // Put the average in the center (diagonal position) of the current 3x3 box
            matrix_m[i + 1][j + 1] = avg;  // Center of the 3x3 box diagonal
        }
    }
}

int main() {
    int m;

    // Get the size of the matrix (m * m)
    printf("Enter the size of the matrix (m): ");
    scanf("%d", &m);

    // Ensure the matrix is large enough to fit a 3x3 submatrix
    if (m < 3) {
        printf("Matrix size should be at least 3x3.\n");
        return 0;
    }

    // Declare the matrix dynamically...
    float matrix_m[10][10];

    // Get the matrix elements from the user.
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%f", &matrix_m[i][j]);
        }
    }

    // Display the original matrix
    printf("\nOriginal Matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf("%.1f ", matrix_m[i][j]);
        }
        printf("\n");
    }

    // Call the function to calculate average and replace the center (diagonal) of 3x3 submatrix
    calculate_and_replace(matrix_m, m);

    // Display the modified matrix
    printf("\nModified Matrix with averages in the center of 3x3 submatrices:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf("%.1f ", matrix_m[i][j]);
        }
        printf("\n");
    }

    return 0;
}
