#include <stdio.h>

int main(){
    int testArray[10];
    printf("Input 10 elements into the array: \n");
    
    for(int limit = 0; limit < 10; limit++){
        printf("element - %d : ", limit);
        scanf("%d", &testArray[limit]);
    }

    printf("Elements in array are: ");

    for(int limit = 0; limit < 10; limit++){
        printf("%d ", testArray[limit]);
    }

    return 0;
}

//demo input 1 1 2 3 4 5 6 7 8 9
