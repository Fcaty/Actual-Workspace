#include <stdio.h>
#include <math.h>

/*The op integer is an external variable so that displayNumber() is able to
read the value of op*/ 
int op = 0;

//This function adds two numbers together  
double computeSum(float num1, float num2){
    return num1 + num2;
}
//This function subtracts the second number from the first number
double computeDifference(float num1, float num2){
    return num1 - num2;
}
//This function multiplies two integers
double computeProduct(float num1, float num2){
    return num1 * num2;
}
//This function divides a number by another number
double computeQuotient(float num1, float num2){
    return (double) num1 / num2; 
}
//This function calculates the square root of a number
double computeSquareRoot(float num1){
    return sqrt(num1);
}
/*This function calculates the exponent from 2 numbers; the first being the
base while the second number is the exponent: a^b*/
double computeExponent(float num1, float num2){
    return pow(num1, num2);
}

//These functions display the result for the sum and difference functions
void displayResult(float num1, float num2, float result){
    switch(op){
        case 1: printf("The sum of %.2f and %.2f is %.2lf\n", num1, num2, result); break;
        case 2: printf("The difference of %.2f and %.2f is %.2f\n", num1, num2, result); break;
    }
}
//These functions display the result for the product, quotient, and exponent functions
void displayResult(float num1, float num2, double result){
    switch(op){
        case 3: printf("The product of %.2f and %.2f is %.4lf\n", num1, num2, result); break;
        case 4: printf("%.2f divided by %.2f is %.4lf\n", num1, num2, result); break;
        case 6: printf("%.2f raised to %.2f is %.4lf\n", num1, num2, result); break;
    }
}
//These functions display the result for the square root functions
void displayResult(float num1, double result){
    printf("The square root of %.2f is %.4lf\n", num1, result);
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
    float num1, num2, fResult;
    double  resultProd, dResult;
    char conf;

    repeat:
    op = 0;
    displayMenu();
    scanf("%d", &op);

    switch(op){
        case 1: 
            printf("Input the 1st number: ");
            scanf("%f", &num1);
            printf("Input the 2nd number: ");
            scanf("%f", &num2);
            fResult=computeSum(num1, num2); 
            displayResult(num1, num2, fResult);
            break;
        case 2:
            printf("Input the 1st number: ");
            scanf("%f", &num1);
            printf("Input the 2nd number: ");
            scanf("%f", &num2);
            fResult=computeDifference(num1, num2); 
            displayResult(num1, num2, fResult);
            break;
        case 3:
            printf("Input the 1st number: ");
            scanf("%f", &num1);
            printf("Input the 2nd number: ");
            scanf("%f", &num2);
            dResult=computeProduct(num1, num2); 
            displayResult(num1, num2, dResult);
            break;
        case 4:
            printf("Input the 1st number: ");
            scanf("%f", &num1);
            printf("Input the 2nd number: ");
            scanf("%f", &num2);
                if(num2 == 0){
                    printf("Anything divided by 0 is undefined.\n");
                    break;
                } 
            dResult=computeQuotient(num1, num2); 
            displayResult(num1, num2, dResult);
            break;
        case 5:
            printf("Input a number: ");
            scanf("%f", &num1);
            if(num1 < 0){
                printf("The square root of a negative number is imaginary.\n");
                break;
            }
            dResult=computeSquareRoot(num1); 
            displayResult(num1, dResult);
            break;
        case 6:
            printf("Input the base: ");
            scanf("%f", &num1);
            printf("Input the exponent: ");
            scanf("%f", &num2);
            dResult=computeExponent(num1, num2); 
            displayResult(num1, num2, dResult); 
            break;
        case 7: printf("Exiting...\n"); goto end;
        default: printf("Error: Not a Valid Operation"); break; 
    }

    printf("\nWould you like to use the program again? [Y/N]: ");
    scanf("\n%c",&conf);
    
    if(conf == 'Y' || conf == 'y') goto repeat;
    else printf("Exiting...\n");
    
    end:
    return 0;
}
