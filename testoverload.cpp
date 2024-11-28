#include <stdio.h>
#include <math.h>

double function1(int test1){
    return sqrt(test1);
}

double function1(int test1, int test2){
    return pow(test1, test2);
}

int main(){
    double test1 = 4, test2 = 2, result;

    result = function1(test1, test2);

    printf("%.2lf", result);

    return 0;
}