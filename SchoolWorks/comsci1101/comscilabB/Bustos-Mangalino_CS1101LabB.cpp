//COMSCI 1101 LAB B FINAL PROJECT, BUSTOS & MANGALINO 
#include <stdio.h>
//The variables are global so that all functions may have access to them.
int id, age, course, yearlvl;
float grade;

//This function displays the menu that presents the user with all of the operations they can execute.
void displayMenu(){
    printf("==============================\n");
    printf("==============================\n");
    printf("Bustos, Mangalino | BSIT 1-1\n\n");
    printf("Student Information System\n\n");
    printf("[1] Add Student Information\n");
    printf("[2] Edit Student Details\n");
    printf("[3] Show Student Information Summary\n");
    printf("[4] Delete Student Information\n");
    printf("[5] Exit\n\n");
}


//This function enables the user to select the operation they would like to execute.
int menuSelect(){
    int option;
    printf("==============================\n");
    printf("==============================\n");
    printf("Select operation: ");
    scanf("%d", &option);

    return option;
}

//The next 5 functions are functions that are called by infoInput() and editInput().
//This function reads a student ID input from the user.
int idInput(){
    int tempID;
    printf("Enter student ID #: ");
    scanf("%d", &tempID);

    return tempID;
}

/*This function reads a student age input from the user.
It will also ensure that the user does NOT input a negative number
using an if statement.*/
int ageInput(){
    int tempAge;

    repeat:
    printf("Enter student age: ");
    scanf("%d", &tempAge);

//Negative number check
    if(tempAge < 0){
        printf("Invalid! Age cannot be a negative number.\n\n");
        goto repeat;
    }

    return tempAge;
}

/*This function reads a student course input from the user.
It will also ensure that the user does NOT input a number not assigned to any course
with the use of an if statement.*/
int courseInput(){
    int tempCourse;
    
    printf("[1] Bachelor of Science in Civil Engineering\n");
    printf("[2] Bachelor of Science in Agriculture and Biosystems Engineering\n");
    printf("[3] Bachelor of Science in Information Technology\n");
    printf("[4] N/A\n\n");
    repeat:
    printf("Select your course: ");
    scanf("%d", &tempCourse);

//Proper Input Check (Greater than 0, less than 5)
    if(tempCourse <= 0 || tempCourse > 4){
        printf("Invalid Course! Select Again.\n\n");
        goto repeat;
    }
    
    return tempCourse;
}

/*This function reads a student year input from the user.
It will also ensure that the user does not input a year level that does not exist
with the use of an if statement.*/
int yearInput(){
    int tempYearlvl;
    repeat:
    printf("Enter student year level [1-4]: ");
    scanf("%d", &tempYearlvl);

//Proper Input Check (Greater than 0, less than 5)
    if(tempYearlvl <= 0 || tempYearlvl > 4){
        printf("Invalid Year Level! Select Again.\n\n");
        goto repeat;
    }

    return tempYearlvl;
}

/*This function reads a student grade input from the user.
It will also ensure that the user does not input an invalid grade 
with the use of an if statement.*/
int gradeInput(){
    int tempGrade;
    repeat:
    
    printf("Enter student grade [0-100]: ");
    scanf("%d", &tempGrade);

//Proper Input Check (Greater than -1, less than 101)
    if(tempGrade < 0 || tempGrade > 100){
        printf("Invalid Grade! Input Again.\n\n");
        goto repeat;
    }

    return tempGrade;
}

//The previous 5 functions are functions that are called by infoInput() and editInput().

//This function calls the other functions that take in inputs from the user.
void infoInput(){
    id = idInput();
    age = ageInput();
    course = courseInput();
    yearlvl = yearInput();
    grade = gradeInput();
}

//This function allows the user to edit each detail of the student.
void editInput(){
    int option;
    
    printf("==============================\n");
    printf("==============================\n");
    printf("\nEdit Student Details\n");
    printf("[1] Edit Student ID\n");
    printf("[2] Edit Student Age\n");
    printf("[3] Edit Student Course\n");
    printf("[4] Edit Student Year Level\n");
    printf("[5] Edit Student Grade\n");
    printf("[6] Cancel\n");
    
    repeat:
    
    printf("Select Edit Option: ");
    scanf("%d", &option);

    switch(option){
        case 1: id = idInput(); break;
        case 2: age = ageInput(); break;
        case 3: course = courseInput(); break;
        case 4: yearlvl = yearInput(); break;
        case 5: grade = gradeInput(); break;
        case 6: break;
        default: printf("Invalid Input!\n"); goto repeat;
    }
}

//This function displays the current information stored by the system.
void showInput(){
    printf("==============================\n");
    printf("==============================\n");
    printf("\nStudent Information Summary: \n");
    printf("Student ID: %d\n", id);
    printf("Student Age: %d\n", age);
    printf("Student Course: ");
    
    switch(course){
        case 1: printf("Bachelor of Science in Civil Engineering\n"); break;
        case 2: printf("Bachelor of Science in Agriculture and Biosystems Engineering\n"); break;
        case 3: printf("Bachelor of Science in Information Technology\n"); break;
        default: printf("No course selected.\n"); break;
    }

    printf("Student Year Level: %d\n", yearlvl);
    printf("Student Grade: %.2f\n\n", grade);
    printf("==============================\n");
    printf("==============================\n");
}

/*This function wipes the current information stored on the system. 
Before doing so, it will require proper confirmation. 
If the user does not confirm, it will NOT wipe.*/
void deleteInput(){
    char yon; 
    
//Confirmation prompt (Will only accept 'Y', not 'y'.)
    printf("Are you sure? [Y to Confirm]: ");
    scanf("\n%c", &yon);
    
    if(yon == 'Y'){
        id = 0;
        age = 0;
        course = 0;
        yearlvl = 0;
        grade = 0;

        printf("==============================\n");
        printf("==============================\n");
        printf("\nStudent Information Wiped.\n\n");
        printf("==============================\n");
        printf("==============================\n");
    } else {
        printf("==============================\n");
        printf("==============================\n");
        printf("\nInformation Wipe Cancelled.\n\n");
        printf("==============================\n");
        printf("==============================\n");
    }
}

//This is the main function.
 int main(){
    int option;
    char yon;
    
    repeat:
    displayMenu();
    option = menuSelect();
    
    switch(option){
        case 1: infoInput(); break;
        case 2: editInput(); break;
        case 3: showInput(); break;
        case 4: deleteInput(); break;
        case 5: printf("Terminating program...\n"); goto end;
        default: printf("Invalid Input!\n"); goto repeat; 
    }

/*This do while loop makes the user experience seamless
by allowing the user to repeat the program until they choose to
terminate it safely.*/
    do{ 

        printf("\nWould you like to use the program again? [Y/N]: ");
        scanf("\n%c", &yon);

        if(yon == 'Y' || yon == 'y'){
        goto repeat;
        } 
    
        else if (yon == 'N' || yon == 'n'){
        printf("Terminating program...\n");
        }
        
    }while((yon != 'Y' && yon != 'y') && (yon != 'N' && yon != 'n'));

    end:
    return 0;
 }