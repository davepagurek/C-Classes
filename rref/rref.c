#include <math.h>
#include <stdio.h>

int equals(float a, float b) {
    float precision = 0.0001;
    if (fabs(a-b) <= precision) return 1;
    return 0;
}

void printMatrix(int rows, int columns, float matrix[rows][columns]) {
    int i, j;
    for (i=0; i<rows; i++) {
        for (j=0; j<columns; j++) {
            printf("%.3f\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

void rref(int rows, int columns, float matrix[rows][columns]) {
    int c;
    for (c=0; c<columns; c++) {
        int r;
        for (r=c+1; r<rows && equals(matrix[c][c], 0); r++) {
            float temp[columns];
            int i;

            //copy matrix[c] to temp
            for (i=0; i<columns; i++) {
                temp[i]=matrix[c][i];
            }

            //copy matrix[r] to matrix[c]
            for (i=0; i<columns; i++) {
                matrix[c][i]=matrix[r][i];
            }

            //copy temp to matrix[r]
            for (i=0; i<columns; i++) {
                matrix[r][i]=temp[i];
            }
        }

        if (equals(matrix[c][c], 0)) {
            continue;
        }


        for (r=0; r<rows; r++) {
            if (r==c) continue;
            if (!equals(matrix[r][c], 0) && !equals(matrix[c][c], 0)) {
                float factor = matrix[r][c]/matrix[c][c];
                //printf("%g/%g:\t%g\n", matrix[c][c], matrix[r][c], factor);
                int i=0;
                for (i=0; i<columns; i++) {
                    matrix[r][i] -= factor*matrix[c][i];
                }

                printf ("%g\n", factor);
                printMatrix(rows, columns, matrix);
            }
        }

        float scale = matrix[c][c];
        for (r=0; r<rows; r++) {
            matrix[c][r] /= scale;
        }
    }
}

int main () {
    float matrix[4][4] = {{6, 4, 2, 9},
                          {2, 2, 0, 3},
                          {20, 20, 0, 30},
                          {1, 2, 3, 4}};

    printMatrix(4, 4, matrix);

    rref(4, 4, matrix);

    printMatrix(4, 4, matrix);

    return 0;
}
