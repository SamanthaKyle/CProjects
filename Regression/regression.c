/********************************************************************************
    Linear Regression computation using linear algebra projection techniques.
    Author: Samantha Kyle
    Date: December 20th, 2020
*********************************************************************************/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

char DELIM = ' ';
int WID = 2;

void printMatrix(int len, int wid, double (*matrix)[wid]) {
    /*
    TODO:
    make this nicer, round consistently
    */
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < wid; j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void transpose(int len, int wid, double (*matrix)[wid]) {
    /*
    TODO: calloc this matrix and make this function return it
    */
    double t[wid][len];
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < wid; j++) {
            t[j][i] = matrix[i][j];
        }
    }
    printMatrix(wid, len, t);

}

/*
TODO: complete this function
-calloc memory for new matrix
-perform operations
-return new matrix

double* multiply(int len1, int wid1, int len2, int wid2, double (*matrix1)[wid1], double (*matrix2)[wid2]) {

}
*/

/*
TODO: complete this function
- needs to solve aTar = aTb where A is [1's x's] b is [y's]
- call to get aT
- multiply aT by a and aTb
- solve for r0 and r1
- return pointer to array containing r0 and r1 in order

double* LINprojection(int len, int wid, double *(dataMatrix)[wid]) {

}
*/

/*
TODO: complete this function
-something to print formula
*/

int main() {
    /*
    TODO: make more test files
    -make this prompt input instead
    
    */
    //open a file, ensure opened correctly
    FILE* f = fopen("testFile.txt", "r");
    if (f == NULL) {return 1;}

    char line[256];
    int lineCount = 0;

    //get the total length of the file
    while (fgets(line, sizeof(line), f)) {
        lineCount++;
    }
    rewind(f);

    int len = lineCount;
    /*
    TODO: calloc this matrix
    */
    double matrix[len][WID];
    double (*pmatrix)[WID] = matrix;
    
    int i = 0;
    while (fgets(line, sizeof(line), f)) {
        char* xVal = strtok(line, " \n");
        char* yVal = strtok(NULL, " \n");
        matrix[i][0] = atof(xVal);
        matrix[i][1] = atof(yVal);
        i++;
    }
    printf("ORIGINAL\n");
    printMatrix(len, WID, pmatrix);
    printf("TRANSPOSED\n");
    transpose(len, WID, pmatrix);

    free(pmatrix);

    return 0;
}