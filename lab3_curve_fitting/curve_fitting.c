// Linear curve fitting

#include <stdio.h>
#include <math.h>

int main()
{
    int i, n;
    float x[50], y[50];
    double sum_x = 0.0, sum_y = 0.0, sum_xy = 0.0, sum_x2 = 0.0, a, b;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Enter the values of x and y: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%f%f", &x[i], &y[i]);
    }

    // Calculating the required sum
    for (i = 0; i < n; i++)
    {
        sum_x = sum_x + x[i];
        sum_y = sum_y + y[i];
        sum_xy = sum_xy + x[i] * y[i];
        sum_x2 = sum_x2 + x[i] * x[i];
    }

    // Calculating the slope and intercept
    b = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    a = (sum_y - b * sum_x) / n;

    printf("The line is Y = %.9f + %.9f X\n", a, b);
}