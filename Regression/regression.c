/********************************************************************************
    Linear Regression computation using linear algebra projection techniques.
    Author: Samantha Kyle
    Date: December 21st, 2020
*********************************************************************************/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct matrix{
    double* data;
    int rows;
    int cols;
};

void printMatrix(struct matrix m){
    /*
    TODO:
    make this nicer, round consistently
    */
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            printf("%f ", m.data[(i*m.cols) + j]);
        }
        printf("\n");
    }
}

struct matrix transpose(struct matrix m){

    struct matrix t;
    t.rows = m.cols;
    t.cols = m.rows;

    t.data = (double*) malloc(t.rows * t.cols * sizeof(double));
    
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            t.data[j* t.cols + i] = m.data[i*m.cols + j];
        }
    }
    return t;

}

struct matrix multiply(struct matrix m, struct matrix m2) {
    /*
    TODO: provide functionality to exit early when dimensions incorrect
    */

    if (m2.rows != m.cols) { printf("Cannot multiply\n");}

    struct matrix new;
    new.rows = m.rows;
    new.cols = m2.cols;

    new.data = (double*) malloc(new.rows * new.cols * sizeof(double));
    
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m2.cols; j++) {
            double sumDot = 0;
            for (int k = 0; k < m.cols; k++) {
                sumDot += m.data[i*m.cols + k] * m2.data[k*m2.cols + j];
            }
            new.data[i*new.cols + j] = sumDot;
        }
    }
    return new;
}

void LINprojection(struct matrix dataMatrix) {
    struct matrix A;
    A.rows = dataMatrix.rows;
    A.cols = 2;
    A.data = (double*) malloc(A.rows * A.cols * sizeof(double));

    struct matrix B;
    B.rows = dataMatrix.rows;
    B.cols = 1;
    B.data = (double*) malloc(B.rows * sizeof(double));

    for (int i = 0; i < A.rows; i++) {
        A.data[i*A.cols] = (double) 1;
        A.data[i*A.cols + 1] = dataMatrix.data[i*A.cols];
        B.data[i] = dataMatrix.data[i*A.cols + 1];
    }

    struct matrix ATA = multiply(transpose(A), A);
    struct matrix ATB = multiply(transpose(A), B);

    //ATA is always a 2*2 matrix, with values a,b,c,d
    double a = ATA.data[0];
    double b = ATA.data[1];
    double c = ATA.data[2];
    double d = ATA.data[3];

    double e = ATB.data[0];
    double f = ATB.data[1];

    double r0 = ((e/b) - (f/d))/((a/b) - (c/d));
    double r1 = (e - (a*r0))/b;
    printf("y = %f + %f\n", r1, r0);
}

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

    //get the total rowsgth of the file
    while (fgets(line, sizeof(line), f)) {
        lineCount++;
    }
    rewind(f);
    
    struct matrix m;
    m.rows = lineCount;
    m.cols = 2;
    m.data = (double*) malloc(m.rows * m.cols * sizeof(double));
    
    int i = 0;
    while (fgets(line, sizeof(line), f)) {
        
        char* xVal = strtok(line, " \n");
        char* yVal = strtok(NULL, " \n");
        m.data[i * m.cols] = atof(xVal);
        m.data[i* m.cols + 1] = atof(yVal);
        i++;
    }

    LINprojection(m);
    
    free(m.data);

    return 0;
}