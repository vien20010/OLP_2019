#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    FILE *fptr_in;
    FILE *fptr_out;
    char n = 0;
    int a = 0, b = 0, i = 0;
    int x[100], y[100], r[100];
    double length = 0, min = 999999999;
    fptr_in = fopen("cow.inp", "r");
    while (fptr_in == NULL)
    {
        /* code */
        printf("Error Read");
        exit(1);
    }

    fscanf(fptr_in, "%d", &n);
    fscanf(fptr_in, "%d", &a);
    fscanf(fptr_in, "%d", &b);

    for (i = 0; i < n; i++)
    {
        fscanf(fptr_in, "%d", (x + i));
        printf("%d\n",*(x+i));
        fscanf(fptr_in, "%d", (y + i));
        printf("%d\n",*(y+i));
        fscanf(fptr_in, "%d", (r + i));
        printf("%d\n",*(r+i));
        length = sqrt(pow(a - *(x + i), 2) + pow(b - *(y + i), 2)) - *(r + i);
        if (i==0)
        {
            min=length;
        }
        if (length < min)
        {
            min = length;
        }
        if ((int)min==min)
        {
            min--;
        }
    }
    printf("%u",(unsigned int)min);
    fclose(fptr_in);
    fptr_out = fopen("cow.out", "w");
    fprintf(fptr_out, "%u", (int)min);
    fclose(fptr_out);
    return 0;
}
