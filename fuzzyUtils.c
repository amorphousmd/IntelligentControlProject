#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double* hlt_hinhthang(float* x, int div, int L, int C1, int C2, int R)
{
    // The array has div + 1 doubles
    double *y = calloc(div + 1, sizeof(double));

    for (int i = 0; i <= div; i++)
    {
        if (x[i] < L)
        {
            y[i] = 0;
        }
        else if (x[i] < C1)
        {
            y[i] = (x[i] - L)/(C1 - L);
        }
        else if (x[i] < C1)
        {
            y[i] = 1;
        }
        else if (x[i] < R)
        {
            y[i] = (R - x[i])/(R - C2);
        }
        else
        {
            y[i] = 0;
        }
    }
    return y;
}

double* OR_Max(double* muyA, double* muyB, int div)
{
    double *y = calloc(div + 1, sizeof(double));

    for (int i = 0; i <= div; i++)
    {
        if (muyA[i] >= muyB[i])
        {
            y[i] = muyA[i];
        }
        else
        {
            y[i] = muyB[i];
        }
    }
    return y;
}


double* And_PROD(double* muyA, double* muyB, int div)
{
    double *y = calloc(div + 1, sizeof(double));

    for (int i = 0; i <= div; i++)
    {
        y[i] = muyA[i] * muyB[i];
    }
    return y;
}

float* linspace(float x1, float x2, int n)
{
    float *x = calloc(n, sizeof(double));

    float step = (x2 - x1) / (float)(n);

    for (int i = 0; i <= n; i++)
    {
        x[i] = x1 + (float)i * step;
    }
    return x;
}

int main()
{   
    int div = 1000;
    float* x = linspace(0,10,div);
    // for (int i = 0; i <= div; i++)
    // {
    //     printf("%d. %f\n",i, x[i]);
    // }
    double* muyA = hlt_hinhthang(x, div, 1, 3, 5, 7);
    double* muyB = hlt_hinhthang(x, div, 3, 6, 6, 8);
    // for (int i = 0; i <= div; i++)
    // {
    //     printf("%d. %lf\n",i, muyB[i]);
    // }
    double* muyC = And_PROD(muyA, muyB, div);
    // for (int i = 0; i <= div; i++)
    // {
    //     printf("%d. %lf\n",i, muyC[i]);
    // }

    printf("Hello World");
    return 0;
}


