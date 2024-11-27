#include <stdio.h>
#include <math.h>

//op is an external variable so that it affects displayResult(); 
int op = 0;

//This function adds the sum of 2 numbers
int computeSum(int num1, int num2){
    int sum;
    sum = num1 + num2;
    return sum;
}

//This function subtracts the second number from the first number
int computeDifference(int num1, int num2){
    int diff;
    diff = num1 - num2;
    return diff;
}

//This function multiplies two numbers 
int computeProduct(int num1, int num2){
    int prod;
    prod = num1 * num2;
    return prod;
}
//This function divides a number by another number
double computeQuotient(int num1, int num2){
    double quot;
    quot = (double) num1 / num2;
    return quot; 
}
//This function calculates the square root of a number
double computeSquareRoot(int num1){
    double result;
    result = sqrt(num1);
    return result;
}
/*This function calculates the exponent from 2 numbers; the first being the
base while the second number is the exponent: a^b*/
double computeExponent(int num1, int num2){
    double exponent;
    exponent = pow(num1,num2);
    return exponent;
}

//These funcions display the result
int displayResult(int num1, int num2, int result){
    switch(op){
        case 1: printf("The sum of %d and %d is: %d\n",num1, num2, result); break;
        case 2: printf("The difference of %d and %d is: %d\n",num1, num2, result); break;
        case 3: printf("The product of %d and %d is: %d\n", num1, num2, result); break;
        case 6: printf("%d raised to %d is: %d\n", num1, num2, result); break;
    }
}

double dDisplayResult(int num1, int num2, double result){
    switch(op){
        case 4: printf("The quotient of %d and %d is: %.2lf\n", num1, num2, result); break;
        case 5: printf("The square root of %d is: %.2lf\n",num1, result); break;
    }
}

//This is the function that displays the initial options
void displayMenu(){
    printf("\nYou are now using the calculator.\n");
    printf("1: Addition\n");
    printf("2: Subtraction\n");
    printf("3: Multiplication\n");
    printf("4: Division\n");
    printf("5: Square Root\n");
    printf("6: Exponent\n");
    printf("7: Exit Program\n");
    printf("\nChoose an operation: ");
}

//This is the main function
int main(){
    int num1, num2, iResult;
    double dResult;
    char conf;

    repeat:
    op = 0;
    displayMenu();
    scanf("%d", &op);

//This switch-case statement determines how many numbers the program will request from the user based on "op"
    switch(op){
        case 1: case 2: case 3: case 4: 
            printf("Input the 1st number: ");
            scanf("%d", &num1);
            printf("Input the 2nd number: ");
            scanf("%d", &num2);
            break;
        case 5:
            printf("Input a number: ");
            scanf("%d", &num1);
            break;
        case 6:
            printf("Input the base: ");
            scanf("%d", &num1);
            printf("Input the exponent: ");
            scanf("%d", &num2);
            break;
        case 7: default: 
            break;
    }

//This switch-case statement determines what function to use based on "op"
    switch(op){
        case 1: 
            iResult=computeSum(num1, num2); 
            displayResult(num1, num2, iResult);
            break;

        case 2: 
            iResult=computeDifference(num1, num2); 
            displayResult(num1, num2, iResult);
            break;

        case 3: 
            iResult=computeProduct(num1, num2); 
            displayResult(num1, num2, iResult);
            break;

        case 4: 
            dResult=computeQuotient(num1, num2); 
            dDisplayResult(num1, num2, dResult);
            break;

        case 5: 
            dResult=computeSquareRoot(num1); 
            dDisplayResult(num1, 0, dResult);
            break;

        case 6: 
            iResult=computeExponent(num1, num2); 
            displayResult(num1, num2, iResult);
            break;

        case 7: printf("Exiting...\n"); goto end;
        default: printf("Error: Not a Valid Operation"); break; 
    }

//This allows the user to repeat using the program until 'N' is input
    printf("\nWould you like to use the program again? [Y/N]: ");
    scanf("\n%c",&conf);
    
    if(conf == 'Y' || conf == 'y') goto repeat;
    else printf("Exiting...\n");
    
    end:
    return 0;
}
