#include <stdio.h>
#include <math.h>
#include <stdlib.h>


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
    }
}


int main()
{
    double value  = functional_value(3.00, 1);
    printf("%f", value);
}