#include <stdio.h>

// Function to define x^2 + 2x
double quadratic(double x) {
    return x*sin(x) + cos(x);
}

double derive(double (*f)(double), double x0) {
    const double delta = 1.0e-6;
    double x1 = x0 - delta;
    double x2 = x0 + delta;
    double y1 = f(x1);
    double y2 = f(x2);
    return (y2 - y1) / (x2 - x1);
}

int main() {
    double der = derive(quadratic, 3.0); // Calculate derivative of x^2 + 2x at x = 3
    printf("The derivative value is: %lf\n", der);

    return 0;
}
