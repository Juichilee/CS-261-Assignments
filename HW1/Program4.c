/* CS261- HW1 - Program4.c*/
/* Name: Juichi Lee
 * Date: 4/6/19
 * Solution description: Drawing code from program2, created an array that holds student structs and assigned random initials and scores to each struct in the array. For the sort, I used two for loops based on the selection sort structure and swapped the positions of two students if the ASII value of the first student's initial is greater than the second student's. As an additional check for students with the same first initials, I would swap their positions if the second initial of the first student is greater than the second student's.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct student{
	char initials[2];
	int score;
};

void swap(struct student* students, int firstpos, int secondpos){
	struct student temp = students[firstpos];
	students[firstpos] = students[secondpos];
	students[secondpos] = temp;
}

void sort(struct student* students, int n){
     /*Sort n students based on their initials*/     
	int i, j;
	for(i = 0; i < n-1; i++){
		for(j = i+1; j < n; j++){
			if(students[j].initials[0] < students[i].initials[0]){
				swap(students, i, j);
			}else if(students[j].initials[0] == students[i].initials[0]){
				if(students[j].initials[1] < students[i].initials[1]){
					swap(students, i, j);
				}
			}	
		}	
	}
}

int main(){
	srand(time(0));
    /*Declare an integer n and assign it a value.*/
	int n = 10; 
	if(n > 0){   
    /*Allocate memory for n students using malloc.*/
    		struct student* students = malloc(sizeof(struct student)* n);
    /*Generate random IDs and scores for the n students, using rand().*/
    		int i;
		for(i = 0; i < 10; i++){
			int a = rand()%26 + 65;
			int b = rand()%26 + 65;
			char initialA = a;
			char initialB = b;
			students[i].initials[0] = initialA;
			students[i].initials[1] = initialB;
			students[i].score = rand()%101;
		}
    /*Print the contents of the array of n students.*/	
		printf("Before Sort:\n");
		for(i = 0; i < 10; i++){
			char a = students[i].initials[0];
			char b = students[i].initials[1];
			int score = students[i].score;
			printf("Initials:%c.%c	Score:%d\n",a, b, score);
		}
    /*Pass this array along with n to the sort() function*/
    		sort(students, n);
    /*Print the contents of the array of n students.*/
		printf("After Sort:\n");
		for(i = 0; i < 10; i++){
			char a = students[i].initials[0];
			char b = students[i].initials[1];
			int score = students[i].score;
			printf("Initials:%c.%c	Score:%d\n",a, b, score);
		}
		free(students);
	}else{
		printf("Array size is 0\n");
	}
    return 0;
}

