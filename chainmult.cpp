#include<stdio.h>
#include<stdlib.h>

#define INT_MAX  99999999

int MatrixChainMultiplication(int p[], int i, int j) {
    printf( "\n (%d, %d)", i,j);
    if(i == j)
        return 0;  // base condition, no operation required to multiply
                   // same matrix.
    int min = INT_MAX;
    int count;

    for (int k=i; k<j; k++) {
        count = MatrixChainMultiplication(p, i, k) +
                MatrixChainMultiplication(p, k+1, j) +
                p[i-1]*p[k]*p[j];

        if (count < min)
            min = count;
    }
    return min;
}

// Driver program to test above function
int main()
{
    int dimensions[] = {10,30,5,60};

    int n = sizeof(dimensions)/sizeof(dimensions[0]);

    printf("Minimum number of multiplications is %d ",
                          MatrixChainMultiplication(dimensions, 1, n-1));
    return 0;
}
