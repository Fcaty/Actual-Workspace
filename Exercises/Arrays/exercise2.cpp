#include <stdio.h>

void reverseArray(int paramArray[], int size){
    for(size -= 1; size >= 0; size--){
        printf("%d ", paramArray[size]);
    }
}

int main(){
    int size;
    printf("How many numbers would you like to enter?: ");
    scanf("%d", &size);

    int testArray[size];
    printf("Input %d number of elements into the array. \n", size);
    for(int l = 0; l < size; l++){
        printf("element - %d : ", l);
        scanf("%d", &testArray[l]);
    }
    
    printf("The values stored into the array in reverse are: ");
    reverseArray(testArray, size);

    return 0;
}

//demo input: 3 2 3 4

