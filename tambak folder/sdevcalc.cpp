#include <stdio.h>
#include <math.h>

double meanCalc(int dataSet[], int size){
    double sum;
    for(int l = 0; l < size; l++){
        sum += dataSet[l];
    }

    return (double) sum / size;
}

double varianceCalc(double squaredSet[], int size){
    double sum;
    for(int l = 0; l < size; l++){
        sum += squaredSet[l];
    }

    return sum / (size - 1);
}

int main(){
    int size;
    double mean, variance, sd;

//Array size indicator
    printf("How many numbers would you like to calculate?: ");
    scanf("%d", &size);

//Array initialization
    int dataSet[size];
    double squaredSet[size];

//Data set input
    for(int l = 0; l < size; l++){
        printf("Item [%d]: ",l);
        scanf("%d", &dataSet[l]);
    }

//Calculating the mean
    mean = meanCalc(dataSet, size);
    printf("The mean is: %.2lf \n", mean);

//Calculating (x - mean)^2 
    for(int l = 0; l < size; l++){
        squaredSet[l] = pow(dataSet[l] - mean, 2);
    }

//Calculating Variance
    variance = varianceCalc(squaredSet, size);
    printf("The variance is: %.2lf \n", variance);

//Calculating Standard Deviation
    sd = sqrt(variance);
    printf("The standard deviation is: %.2lf \n", sd);

    return 0;
}