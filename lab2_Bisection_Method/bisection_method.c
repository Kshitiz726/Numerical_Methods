// Numerical Method: Bisection Method

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float f(float x)
{
    return pow(5,x) - 6*x; //update here , according to your question (equation)
}

int main()
{
    float x0, x1, x2, f0, f1, f2, e;
    int N, iteration = 1;

    while(1)
    {
        printf("Enter initial guesses: ");
        scanf("%f%f", &x0, &x1);
        f0 = f(x0);
        f1 = f(x1);
        if (f0 * f1 < 0.0)
        {
            break;
        }
        printf("Incorrect Initial Guesses.\n");
    }

    printf("Enter tolerable error: ");
    scanf("%f", &e);
    printf("Enter maximum iteration: ");
    scanf("%d", &N);
    printf("------------------------------------------------------------------\n");
    printf("--------------------------THA078BCT021-----------------------------\n");
    printf("------------------------------------------------------------------\n");
    printf("\n------------------------------------------------------------------\n");
    printf("SN\t\tx0\t\tx1\t\tx2\n");
    printf("------------------------------------------------------------------\n");

    do
    {
        x2 = (x0 + x1) / 2;
        f2 = f(x2);

        printf("%d\t\t%f\t%f\t%f\n", iteration, x0, x1, x2);

        if (f0 * f2 < 0)
        {
            x1 = x2;
            f1 = f2;
        }
        else
        {
            x0 = x2;
            f0 = f2;
        }

        iteration++;
        if (iteration > N)
        {
            printf("Solution does not converge\n");
            exit(1);
        }
    } while (fabs(f2) > e);

    printf("------------------------------------------------------------------\n");
    printf("\nRoot is: %f\n", x2);
}