#include <stdio.h>
#include <math.h>

#define EPSILON 0.1 

int i = 1;
double func(double x) {
    return x * x * x - 2 * x - 5;
}


double derivative(double x) {
    return 3 * x * x - 2;
}


double newtonRaphson(double x) {
    while (1) {
        double f_value = func(x);
        double f_derivative = derivative(x);
        double x_next = x - (f_value / f_derivative);

       
        if (fabs(x_next - x) < EPSILON) {
            break;
        }
        
        
        printf("%d\t%f\t%f\t%f\t%f\n", i, x, x_next, f_value , f_derivative);
        x = x_next;
        i++;
    }
    return x;
}

int main() {
    double initial_guess;
    printf("Enter initial guess for the roo̥t: ");
    scanf("%lf", &initial_guess);
    printf("No\t\txn\t\t\txn+1\t\tf(xn)\t\tf'(xn)\n");
    double root = newtonRaphson(initial_guess);
    
    printf("______________________________________________\n");
    printf("Root of the equation is approximately: %f\n", root);
    return 0;
}
