#include <stdio.h>
#include <math.h>

/*The op integer is an external variable so that displayNumber() is able to
read the value of op*/ 
int op = 0;

//This function adds two numbers together  
double computeSum(double num1, double num2){
    return num1 + num2;
}
//This function subtracts the second number from the first number
double computeDifference(double num1, double num2){
    return num1 - num2;
}
//This function multiplies two integers
double computeProduct(double num1, double num2){
    return num1 * num2;
}
//This function divides a number by another number
double computeQuotient(double num1, double num2){
    if (num2 == 0){
        printf("Anything divided by 0 is undefined.\n\n");
        return 0;
    }
    return (double) num1 / num2; 
}
//This function calculates the square root of a number
double computeSquareRoot(double num1){
    if (num1 < 0){
        printf("Negative numbers are imaginary numbers.\n\n");
        return 0;
    }
    return sqrt(num1);
}
/*This function calculates the exponent from 2 numbers; the first being the
base while the second number is the exponent: a^b*/
double computeExponent(double num1, double num2){
    return pow(num1,num2);
}

//This function displays the result
void displayResult(double num1, double num2, double resultSum){
    printf("The sum of %.2lf and %.2lf is %.2lf", num1, num2, resultSum);
    }

 displayResult(double num1, double num2, double resultDiff){
    printf("The difference of %.2lf and %.2lf is %.2lf", num1, num2, resultDiff);
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
    double num1, num2, resultSum, resultDiff, resultProd, resultQuot, resultSqrt, resultExp;
    char conf;

    repeat:
    op = 0;
    displayMenu();
    scanf("%d", &op);

    printf("Input the 1st number: ");
    scanf("%lf", &num1);
    printf("Input the 2nd number: ");
    scanf("%lf", &num2);

    switch(op){
        case 1:
            result=computeSum(num1, num2); 
            displayResult(num1, num2, resultSum, A);
            break;
        case 2:
            result=computeDifference(num1, num2,); 
            displayResult(num1, num2, resultDiff, 1);
            break;
        case 3:
            result=computeProduct(num1, num2); 
            displayResult(num1, num2, resultProd);
            break;
        case 4:
            result=computeQuotient(num1, num2); 
            displayResult(num1, num2, resultQuot);
            break;
        case 5:
            printf("Input a number: ");
            scanf("%lf", &num1);
            result=computeSquareRoot(num1); 
            displayResult(num1, 0, resultSqrt);
            break;
        case 6:
            printf("Input the base: ");
            scanf("%lf", &num1);
            printf("Input the exponent: ");
            scanf("%lf", &num2);
            result=computeExponent(num1, num2); 
            displayResult(num1, num2, resultExp);
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
