/*INTECH 1100 EXAM PART II - DIOPHANTINE EQUATION IN C*/
/*Members: Rion Fauszt O. Bustos, Neil Jacob E. Santiago, Kyx M. Hubilia*/

#include <stdio.h> //# include header

int main(){ 
    int x, y, z;
//The 3 nested loops below will start at 1 and 
//continue incrementing until all reach the value of 1000.
    for(z = 1; z <= 1000; z++){
        for (x = 1; x <= 1000; x++){
            for (y = 1; y <= 1000; y++){
                if(z*5 == 3*y + 2*x) //The values of x, y, and z are assessed and will only 
                printf("(x = %d, y = %d, z = %d)\n", x, y, z); // print their values if the 
            }                                                  // diophantine equation is solved    
        }                                                      // with the correct integers.
    }
    return 0;
}