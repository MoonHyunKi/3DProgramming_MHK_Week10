#include <iostream>
#include "MuSoenMath.h"

int main() {
    printf("3DProgramming_201934030_문현기_2-1\n\n");
    header();
    matA T1;
    
    int matrix[4][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16} };

    T1.Identity(3, 3);
    T1.transposeNbyN(matrix, 4);
    system("pause");
}