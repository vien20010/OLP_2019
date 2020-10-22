#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Debug.h"

int main()
{

    FILE *fptr_in;
    FILE *fptr_out;

    int k = 0, n = 0, i = 0, j = 0;
    char matrix, hang, cot, column;
    long long unsigned int S = 0, c = 0;
    char ***A;
    int temp[100][100], mul[100][100];
    fptr_in = fopen("mat.inp", "r");
    fscanf(fptr_in, "%d", &k);
    fscanf(fptr_in, "%d", &n);
    fscanf(fptr_in, "%d", &i);
    fscanf(fptr_in, "%d", &j);
    fscanf(fptr_in, "%u", &S);

    //char A[k][n][n];

    A = (char ***)malloc(k * sizeof(char **));

    for (matrix = 0; matrix < k; matrix++)
    {
        *(A + matrix) = (char **)malloc(n * sizeof(char *));
        for (hang = 0; hang < n; hang++)
        {
            *(*(A + matrix) + hang) = (char *)malloc(n * sizeof(char));
        }
    }

    DBG("%d\n%d\n%d\n%d\n%d\n", k, n, i, j, S);

    for (matrix = 0; matrix < k; matrix++)
    {
        for (hang = 0; hang < n; hang++)
        {
            for (cot = 0; cot < n; cot++)
            {
                fscanf(fptr_in, "%d", (*(*(A + matrix) + hang) + cot));
                //fscanf (fptr_in,"%d",&A[matrix][hang][cot]);
                //DBG("%d\n",A[matrix][hang][cot]);
                DBG("%d\n", *(*(*(A + matrix) + hang) + cot));
            }
        }
    }

    fclose(fptr_in);

    for (hang = 0; hang < n; hang++)
    {
        for (cot = 0; cot < n; cot++)
        {
            *(*(mul + hang) + cot) = *(*(*(A + 0) + hang) + cot);
            *(*(temp + hang) + cot) = *(*(mul + hang) + cot);
            //DBG("%d\t", *(*(mul + hang) + cot));
        }
    }

    //Mul k matrix

    for (matrix = 1; matrix < k; matrix++)
    {
        for (hang = 0; hang < n; hang++)
        {
            for (cot = 0; cot < n; cot++)
            {
                *(*(mul + hang) + cot) = 0;
                for (column = 0; column < n; column++)
                {
                    *(*(mul + hang) + cot) += *(*(temp + hang) + column) * *(*(*(A + matrix) + column) + cot);
                }
            }
        }

        for (hang = 0; hang < n; hang++)
        {
            for (cot = 0; cot < n; cot++)
            {
                *(*(temp + hang) + cot) = *(*(mul + hang) + cot);
                DBG("%d\t", *(*(temp + hang) + cot));
            }
        }
    }

    //Tim phan du

    c = *(*(temp + i-1) + j-1);
    DBG("%d\t%d\n", i, j);
    DBG("%d\n", *(*(temp+i-1)+j-1));
    fptr_out = fopen("mat.out", "w");
    fprintf(fptr_out, "%d", c % S);

    return 0;
}
