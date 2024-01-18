#include <stdio.h>
#include <math.h>

void question_a(int n, float *x, float *y){
    FILE *fptr = fopen("a.txt", "r");
    for(int i = 0; i < n; i++){
        fscanf(fptr, "%f %f", &x[i], &y[i]); 
        printf("%f %f\n", x[i], y[i]);
    }
    fclose(fptr);
}
void question_b(int n, float *x, float *y){
    FILE *fptr = fopen("b.txt", "r");
    for(int i = 0; i < n; i++){
        fscanf(fptr, "%f %f", &x[i], &y[i]); 
        printf("%f %f\n", x[i], y[i]);
    }
    fclose(fptr);
}

int main(){
    int n, i;
    float x[50], y[50];
    int question;
    double sumx = 0, sumx2 = 0, sumxy = 0, sumy = 0, a, b;
    printf("\nLinear Curve Fitting\n");
    printf("\nEnter number of data points: ");
    scanf("%d", &n);
    printf("\nQuestion Number: ");
    scanf("%d", &question);
    if(question == 1)
    {
        question_a(n,x,y);
    }
    else  if(question == 2)
    {
        question_b(n,x,y);
    }

    printf("\nThe table of values you entered is as follows:\n");
    printf("\nx\t\t\ty\n");
    printf("\n___________________________________\n");
    for(i = 0; i < n; i++){
        printf("\n%f\t\t%f\n", x[i], y[i]);
    }
    for(i = 0; i < n; i++){
        sumx += x[i];
        sumx2 += x[i] * x[i];
        sumy += y[i];
        sumxy += x[i] * y[i];
    }

    b = (n * sumxy - sumx * sumy) / (n * sumx2 - sumx * sumx);
    a = (sumy - b * sumx) / n;

    printf("\nThe values of a and b are: a = %0.8lf, b = %0.8lf", a, b);
    printf("\nThe required fitted regression line is y = %0.8lf + %0.8lfx\n", a, b);

    return 0; 
}
