/* CS261- HW1 - Program3.c*/
/* Name: Juichi Lee
 * Date: 4/5/19
 * Solution description: Allocated an array of integers using malloc. Used srand() and rand to fill in the array with random numbers from 0-100. Passed in the array to sort function and used a simple selection sort algorithm to sort numbers in ascending order. 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int* number, int n){
     /*Sort the array of integeres of length n*/     
	int i;
	int j;
	for(i = 0; i < n; i++){
		int current = i;
		for(j = i; j < n; j++){
			if(number[current] > number[j]){
				int temp = number[j];
				number[j] = number[current];
				number[current] = temp;
			}
		}
	}
	
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
	int n = 20;
	if(n > 0){
    /*Allocate memory for an array of n integers using malloc.*/
		int* array = malloc(sizeof(int) * n);
    /*Fill this array with random numbers, using rand().*/
		srand(time(0));
		int i;
		for(i = 0; i < n; i++){
			array[i] = rand()%101;
		}
    /*Print the contents of the array.*/
		printf("Unsorted Array:\n");
		for(i = 0; i < n; i++){
			printf("%d\n", array[i]);
		}
    /*Pass this array along with n to the sort() function of part a.*/
		sort(array, n);
    /*Print the contents of the array.*/    
	   	 printf("Sorted Array:\n");
		for(i = 0; i < n; i++){
			printf("%d\n", array[i]);
		}
		free(array);
	}else{
		printf("Cannot create array\n");
	}
    return 0;
}
