/*
    DESCRIPTION: Implementation of hash table using Zed A. Shaw's list
    Author: Kailash Meiyappan
    email: kailash195@gmail.com
    version: 1.0
*/
#include "mylist.h"
#include "hashtable.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
//creates a hash table, return 1 success, -1 failure
hash_table* hash_init()
{
	hash_table* h;
	h = (hash_table*)malloc(sizeof(hash_table));
	int i = 0;
	for(;i<MAX_SIZE; i++)
	{
		h->bucket[i] = List_create();
		//if(h->bucket[i]->first == NULL)printf("%d\n",i);
		if(h->bucket[i] == NULL)
		{
			hash_delete(h);
			return NULL;
		}
	}
	h->size = 0;
	return h;
}

//bernstein's djb hash function
int hash(char str[])
{
	unsigned long hashv = 5381;
	int c;
	int i = 0;
	//printf("%s",str);
    	while (c = str[i++])
        	hashv = ((hashv << 5) + hash) + c; /* hashv * 33 + c */
	//printf("%d\n",(hashv%MAX_SIZE));
    	return hashv%MAX_SIZE;
}

//checks if element is in the table
int hash_lookup(hash_table *h, char key[])
{
	int value = hash(key);
	//if(h->bucket[value]->first == NULL) printf("yes2\n");
	return List_search_char(h->bucket[value], key);
}
//adds an element of string type
int hash_add(hash_table *h, char key[])
{
	int value = hash(key);
	if(hash_lookup(h, key)==-1)
	{	//printf("3\n");
		List_push(h->bucket[value],key);
		return 1;
	}
	return 0;	
}

//removes element
int hash_remove(hash_table *h, char key[])
{
	int value = hash(key);
	if(hash_lookup(h, key)==1)
	{	
		return List_remove_char(h->bucket[value],key);
	}
	
}
//deletes the hash table, frees memory
int hash_delete(hash_table *h)
{
	//printf("1\n");
	int i = 0;
	for(;i<MAX_SIZE; i++)
	{
		//printf("i\n");
		List_destroy(h->bucket[i]);
	}
	//size = 0;printf("1\n");
	free(h);
	return 1;
}














