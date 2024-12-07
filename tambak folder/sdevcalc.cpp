#include <stdio.h>

double meanCalc(int dataSet[], int size){
    int sum;
    for(int l = 0; l < size; l++){
        sum += dataSet[l];
    }

    return sum;
}

int main(){
    int size, mean;

    printf("How many numbers would you like to calculate?: ");
    scanf("%d", &size);

    int dataSet[size], squaredSet[size];
    
    for(int l = 0; l < size; l++){
        printf("Element[%d]: ",l);
        scanf("%d", &dataSet[l]);
    }
    
    mean = meanCalc(dataSet, size);
    printf("%d \n", mean);

}