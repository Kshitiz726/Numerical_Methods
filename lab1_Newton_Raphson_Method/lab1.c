// Numerical Method: Newton Raphson Method

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float f(float x)
{
    return x*exp(-x) - cos(x);
}

float df(float x)
{
    return -x*exp(-x) + exp(-x) + sin(x);
}

int main()
{
    float x0, x1, f0, df0, f1, e;
    int N, iteration = 1;

    printf("Enter initial guess: ");
    scanf("%f", &x0);
    printf("Enter tolerable error: ");
    scanf("%f", &e);
    printf("Enter maximum iteration: ");
    scanf("%d", &N);

    printf("\nSN\t\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");

    do
    {
        f0 = f(x0);
        df0 = df(x0);

        if (df0 == 0.0)
        {
            printf("Mathematical Error.\n");
            exit(1);
        }

        x1 = x0 - f0 / df0;
        f1 = f(x1);

        printf("%d\t\t%f\t%f\t%f\t%f\n", iteration, x0, f0, x1, f1);

        x0 = x1;
        iteration++;
        if (iteration > N)
        {
            printf("Solution does not converge\n");
            exit(1);
        }
    } while (fabs(f1) > e);
    
    printf("\nRoot is: %f\n", x1);

    return 0;
}