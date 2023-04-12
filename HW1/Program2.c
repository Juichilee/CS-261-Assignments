/* CS261- HW1 - Program2.c*/
/* Name: Juichi Lee
 * Date: 4/6/19
 * Solution description: For the main parts of the program, I generated random numbers between 65-90 to represent the ASCII values of the capital letters, converted them into characters, and then assigned them to the student initials. For the summary, I found the max by comparing each score with the current maximum and replacing the current max score if the next analyzed score was greater. The same was for finding the min except with a less than sign.  
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct student{
	char initials[2];
	int score;
};

struct student* allocate(){
	/*Allocate memory for ten students*/
	int length = 10; 
     	struct student* studArray = malloc(sizeof(struct student) * length);

	/*return the pointer*/
	return studArray;
}

void generate(struct student* students){
     /*Generate random initials and scores for ten students.
	The two initial letters must be capital and must be between A and Z. 
	The scores must be between 0 and 100*/
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
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              1. Initials  Score
              2. Initials  Score
              ...
              10. Initials Score*/
	int i;
	for(i = 0; i < 10; i++){
		char a = students[i].initials[0];
		char b = students[i].initials[1];
		int score = students[i].score;
		printf("Initials:%c.%c	Score:%d\n",a, b, score);
	}
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/		int i;
	int max = 0;
	for(i = 0; i < 10; i++){
		if(students[max].score < students[i].score){
			max = i;
		}
	}
	int min = 0;
	for(i = 0; i < 10; i++){
		if(students[min].score > students[i].score){
			min = i;
		}
	}
	int sum = 0;
	int avg;
	for(i = 0; i < 10; i++){
		sum += students[i].score;
	}
	avg = sum/10;
	printf("Max:%d\nMin:%d\nAvg:%d\n", students[max].score, students[min].score, avg);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
	free(stud);
}

int main(){
	struct student* stud = NULL;
    	srand(time(0));
    /*call allocate*/
	stud = allocate();    
    /*call generate*/
    	generate(stud);
    /*call output*/
   	output(stud); 
    /*call summary*/
   	summary(stud); 
    /*call deallocate*/
	deallocate(stud);

    return 0;
}
