/* CS261- HW1 - Program1.c*/
/* Name: Juichi Lee
 * Date: 4/4/19
 * Solution description: used srand() and rand() to randomly generate integers from 0-10 for x, y, z. In the function foo, changed the value at the addresses stored in pointers a and b by using *(pointer) to access and make changes. 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int foo(int* a, int* b, int c){
    /* Increment a */

	*a = *(a)-1;

    /* Decrement  b */

    	*b = *(b)-1;

    /* Assign a-b to c */

    	c = *(a)-*(b);

    /* Return c */

	return c;
}

int main(){
    /* Declare three integers x,y and z and initialize them randomly to values in [0,10] */
	srand(time(0));

	int x, y, z;

	x = rand()%11;

	y = rand()%11;

	z = rand()%11;

    /* Print the values of x, y and z */

    	printf("Before foo:\nx.%d\ny.%d\nz.%d\n", x, y, z);

    /* Call foo() appropriately, passing x,y,z as parameters */

	int fooValue = foo(&x, &y, z); 
	
	printf("After foo:\nx.%d\ny.%d\nz.%d\n", x, y, z);

    /* Print the value returned by foo */

	printf("value returned by foo:%d\n", fooValue);

    /* Is the return value different than the value of z?  Why? */

	printf("The reason why the return value from foo is different from z is because since z wasn't passed in by pointer or by reference, therefore no actual changes could be made to the value at z's memory address.\n");
	return 0;
}
    
    
