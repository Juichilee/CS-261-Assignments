#include <stdlib.h>
#include "hashMap.h"
#include "structs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

int stringHash1(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += str[i];
	return r;
}

int stringHash2(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += (i+1) * str[i]; /*the difference between 1 and 2 is on this line*/
	return r;
}

void initMap (struct hashMap * ht, int tableSize)
{
	int index;
	if(ht == NULL)
		return;
	ht->table = (hashLink**)malloc(sizeof(hashLink*) * tableSize);
	ht->tableSize = tableSize;
	ht->count = 0;
	for(index = 0; index < tableSize; index++)
		ht->table[index] = NULL;
}

void freeMap (struct hashMap * ht)
{  /*write this*/
	int i;
	for(i = 0; i < ht->tableSize; i++){ 
		struct hashLink *current = ht->table[i];
		while(current != 0){
			struct hashLink *temp = current->next;
			free(current);
			current = temp;
		}
	}
	free(ht->table);
	
}

void insertMap (struct hashMap * ht, KeyType k, ValueType v)
{  /*write this*/
	int hash;
	int a = containsKey(ht, k);
	
	if(HASHING_FUNCTION == 1){
		hash = stringHash1(k);
	}else{
		hash = stringHash2(k);
	}

	int hashIndex = (int)(labs(hash)%ht->tableSize);
	
	if(a == 1){
		struct hashLink *current = ht->table[hashIndex];
		while(current != 0){
			KeyType currKey = current->key;
			if(currKey == k){
				current->value += 1;
				break;
			}
			current = current->next;
		}	
	}else{
	
		struct hashLink *newLink = (struct hashLink*)malloc(sizeof(struct hashLink));
		assert(newLink);
		newLink->key = k;
		newLink->value = v;
		while(ht->table[hashIndex] != NULL){
			++hashIndex;
			hashIndex %= ht->tableSize;
		}	
		ht->table[hashIndex] = newLink;
	}
		
	printf("%s: %d\n", ht->table[hashIndex]->key, ht->table[hashIndex]->value);
	
//	ValueType* a = atMap(ht, k);
//	printf("Index: %d, Val: %d\n", hashIndex, *a);

		/**
		float loadFactor = tableLoad(ht)
		if(loadFactor > 20){
			int oldsize = ht->tableSize;
			struct hashMap *oldht = ht;
			
		}
		**/	
//	}
}

ValueType* atMap (struct hashMap * ht, KeyType k)
{ /*write this?*/

	int hash;

	if(HASHING_FUNCTION == 1){
		hash = stringHash1(k);
	}else{
		hash = stringHash2(k);
	}

	int hashIndex = (int)(labs(hash)%ht->tableSize);
	//printf("AtMap HashIndex: %d\n", hashIndex);
	
	struct hashLink *current = ht->table[hashIndex];
	while(current != 0){
		KeyType currKey = current->key;
		if(currKey == k){
			//printf("%s\n", currKey);
			//printf("%d\n", current->value);
			ValueType a;
			ValueType *b = &a;
			*b = current->value;
		//	printf("%d\n", *b);	
			return b;
		}
		current = current->next;
	}	

	return NULL;
}


int containsKey (struct hashMap * ht, KeyType k)
{  /*write this*/
	int hash;

	if(HASHING_FUNCTION == 1){
		hash = stringHash1(k);
	}else{
		hash = stringHash2(k);
	}

	int hashIndex = (int)(labs(hash)%ht->tableSize);
	
	if(ht->table[hashIndex] != NULL && k == ht->table[hashIndex]->key){
		return 1;
	}
	return 0;

}

void removeKey (struct hashMap * ht, KeyType k)
{  /*write this?*/
	int a = containsKey(ht, k);
	if(a == 1){
		struct hashLink *cur, *last;
		int hash = stringHash1(k);
		int hashIndex = (int)(labs(hash)%ht->tableSize);

		cur = ht->table[hashIndex];
		last = ht->table[hashIndex];
		while(cur != 0){
			KeyType currKey = cur->key;
			if(currKey == k){
				if(cur == ht->table[hashIndex]){
					ht->table[hashIndex] = cur->next;
				}else{
					last->next = cur->next;
				}
				free(cur);
				cur = 0;
				ht->count--;
			}else{
				last = cur;
				cur = cur->next;	
			}
		}	
	}
}

int sizeMap (struct hashMap *ht)
{  /*write this*/
	int count = 0;
	int i;
	for(i = 0; i < ht->tableSize; i++){
		struct hashLink *current = ht->table[i];
		while(current != 0){
			count++;	
			current = current->next;
		}	
	}
	return count;
}

int capacityMap(struct hashMap *ht)
{  /*write this*/
	return ht->tableSize;	
}

int emptyBuckets(struct hashMap *ht)
{  /*write this*/
	int count = 0;
	int i;
	for(i = 0; i < ht->tableSize; i++){
		if(ht->table[i] == 0){
			count++;	
		}
	}
	return count;
}

float tableLoad(struct hashMap *ht)
{  /*write this*/
	int capacity = capacityMap(ht);
	int size = sizeMap(ht);
	return (float)size/(float)capacity; 	
}
