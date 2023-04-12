#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"

int main(void){
int i = 0;
int cap = 5;

//Make Array
DynArr* v = newDynArr(cap); 

//Fill Array
for(i = 0; i < cap; i++){
	if(i%2 == 0){
		addDynArr(v, 'c');
	}else{
		addDynArr(v, 'd');
	}
}

//Print Array
printf("BEFORE\n");
printf("Size:%d Capacity:%d\n",v->size, v->capacity);
for(i = 0; i < v->capacity; i++){
	printf("|%c\n", v->data[i]);
}	
char x;
x = topDynArr(v);
printf("Top of Array:%c\n", x);

//Remove value
removeDynArr(v, 'c');

//Print Array
printf("AFTER\n");
printf("Size:%d Capacity:%d\n",v->size, v->capacity);
for(i = 0; i < v->capacity; i++){
	printf("|%c\n", v->data[i]);
}		
x = topDynArr(v);
printf("Top of Array:%c\n", x);

int p = containsDynArr(v, 'b');

printf("Contains:%d\n", p);

//Delete array
deleteDynArr(v);

return 0;
}
