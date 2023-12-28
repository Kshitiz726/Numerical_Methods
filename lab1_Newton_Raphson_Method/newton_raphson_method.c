#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int option, max_iterations;
double guess;
#define e 0.0000001
//get options
int get_option()
{
    return option;
}

//calculate the functional value at given point by user guess and selected question
double functional_value(double x, int option){
    switch(option)
    {
        case 1: 
         return x*x - 3*x +2;
         break;
        case 2:
         return x * log10(x) - 1.2;
         break;
        case 3:
         return x * log(x) - 1.2;
         break;
        case 4:
         return 3 * x -  cos(x) + 1;
         break;
        case 5:
         return x * exp(-x) - cos(x);
         break;
        case 6:
         return 0.333;
         break;

         default:
         return 0.2;
    }
}

// Use Newton's Finite Difference Method to find the derivative
double derive(double (*f)(double, int), double x0) {
    const double delta = 1.0e-6;
    double x1 = x0 - delta;
    double x2 = x0 + delta;
    double y1 = f(x1,get_option());
    double y2 = f(x2, get_option());
    return (y2 - y1) / (x2 - x1);
}

// Newton's Rahpson Method to find the root 

double NewtonRahpson(double x) {
    double x_next;
    int N = 1;
    while (N <= max_iterations) {
        double value = functional_value(x, option);
        double derived_value = derive(functional_value, x);
        x_next = x - (value / derived_value);

        if (fabs(x_next - x) < e) {
            break;
        }
    
        printf("|%d|\t|%f|\t|%f|\t|%f|\t|%f|\n", N, x, x_next, value , derived_value);
        x = x_next; // Update x for the next iteration
        N++;
    }

 if (N > max_iterations) {
       printf("\n__________________________________________________________________\n");
        printf("Solution doesn't converge within the maximum number of iterations.\n");
        return 0; // Or any other value to indicate lack of convergence
    }

    return x_next;
}


int main()
{
    printf("Choose the equation to find the root of :\n1)x^2 - 3x +2\n2)xlog10(x) - 1.2 \n3)xln(x) - 1.2 \n4)3x -  cos(x) + 1 \n5)xe^(-x) - cos(x)\n6)1/3\n");
    printf("Question Number: ");
    scanf("%d", &option);
    printf("Guess: ");
    scanf("%lf", &guess); 
    printf("Iterations: ");
    scanf("%d", &max_iterations); 
    printf("|No|\t|xn|\t\t|xn+1|\t\t|f(xn)|\t\t|f'(xn)|");
    printf("\n__________________________________________________________________\n");
    double approximate_root = NewtonRahpson(guess);
    printf("__________________________________________________________________\n");
    printf("|Approximate root| |%lf|", approximate_root);
}