#include <stdio.h>
#include <math.h>
#define f(x) pow(5,x) - 6*x

int main()
{
    float x0, e, f0, x1, f1, x2, f2;
    int i = 1;
INPUT:
    printf("Enter lower and higher assumption for x0 and x1: \t");
    scanf("%f %f", &x0, &x1);
    f0 = f(x0);
    f1 = f(x1);
    if (f0 * f1 > 0.0)
    {
        printf("Incorrect initial guesses\n");
        goto INPUT;
    }
    printf("Enter the value of error: \t");
    scanf("%f", &e);

    printf("\n________________________________________________________________________\n");
    printf("Iteration\tx0\t\tx1\t\tx2\t\tf(x2)\n");
    printf("\n________________________________________________________________________\n");

    do
    {
        x2 = (x1 + x0) / 2;
        f2 = f(x2);
        printf("\n%d\t\t%f\t%f\t%f\t%f", i, x0, x1, x2, f2);
        if (f0 * f2 < 0.0)
        {
            x1 = x2;
            f1 = f2;
        }
        else
        {
            x0 = x2;
            f0 = f2;
        }
        i++;

    } while (fabs(f2) > e);

    printf("\n_______________________________________________________________________\n");

    printf("\nThe approximate real root is %.8f", x2);
    return 0;
}