#include <stdio.h>
#include <math.h>
#define e 0.00001
int option;

int get_option()
{
    return option;
}

double func(double x, int option){
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

double bisection(double a, double b)
{
    if(func(a,get_option()) * func(b, get_option()) >= 0){
        printf("Incorrect interval");
        return 0;
    }
    double c = a;
    while ((b-a) >= e)
    {
        c = (a+b) /2;
        if(func(c, get_option()) == 0.0){
            break;
        }else if(func(c, get_option()) * func(a, get_option()) < 0)
        {
            b = c;
        }
        else{
            a = c;
        }
    }
    return c;
}

int main(){
    printf("Choose the equation to find the root of :\n1)x^2 - 3x +2\n2)xlog10(x) - 1.2 \n3)xln(x) - 1.2 \n4)3x -  cos(x) + 1 \n5)xe^(-x) - cos(x)\n6)1/3\n");
    printf("Question Number: ");
    scanf("%d", &option);
    double a = 0.5;
    double b = 1.5;
    printf("Root is: %f\n"  ,bisection(a,b));
    double c  = 1.5 ;
    double d = 2.5;
    printf("Root is: %f\n"  ,bisection(c,d));
    return 0;
}