#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "Debug.h"

long long unsigned int find_max(long long unsigned int *matrix, unsigned int hang, unsigned int cot);

int main()
{
    FILE *fptr_in, *fptr_out;
    long long unsigned int *a, *b, du = 0, max_a = 0, max_b = 0;
    unsigned int k = 0, n = 0, i = 0, j = 0;
    unsigned int *L, *R;

    fptr_in = fopen("seq.inp", "r");
    fscanf(fptr_in, "%u", &n);
    fscanf(fptr_in, "%u", &k);
    DBG("%u\t%u\n", n, k);

    a = (long long unsigned int *)malloc(n * sizeof(long long unsigned int));
    b = (long long unsigned int *)malloc(n * sizeof(long long unsigned int));
    L = (unsigned int *)malloc(k * sizeof(unsigned int));
    R = (unsigned int *)malloc(k * sizeof(unsigned int));

    for (i = 0; i < n; i++)
    {
        fscanf(fptr_in, "%llu", a + i);
        DBG("%llu\t", *(a + i));
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        fscanf(fptr_in, "%llu", b + i);
        DBG("%llu\t", *(b + i));
    }
    printf("\n");
    for (i = 0; i < k; i++)
    {
        fscanf(fptr_in, "%u", L + i);
        fscanf(fptr_in, "%u", R + i);
        DBG("%u %u\n", *(L + i), *(R + i));
    }
    fclose(fptr_in);

    for (i = 0; i < k; i++)
    {
        max_a = find_max(a, *(L + i), *(R + i));
        for (j=1;j<=max_a;j++)
        {
            if 
        }
    }
    //Calculate
    return 0;
}

long long unsigned int find_max(long long unsigned int *matrix, unsigned int dau, unsigned int cuoi)
{
    unsigned int k = 0;
    long long unsigned int max = 0;
    for (k = dau; k < cuoi; k++)
    {
        if (*(matrix + k) > max)
        {
            max = *(matrix + k);
        }
    }
    return max;
}