#include<stdio.h>
#include "mylist.h"
#include "hashtable.h"
void main()
{
	hash_table *h;
	if((h = hash_init())==NULL)return;
	printf("hash table initialised\n");
	//if(h->bucket[10]->first == NULL) printf("yes1\n");
	char ch[] = "hello world";
	hash_add(h,ch);
	printf("\'hello world\' added to hash table\n");

	if(hash_lookup(h,"hello world")==1)
		printf("found \'hello world\' in hash table successfully\n");
	if(hash_lookup(h,"hello")==-1)
		printf("tried searching for \'hello\' in hash table, not found\n");

	if(hash_remove(h,"hello world")==1)
		printf("removed \'hello world\'\n");
	if(hash_lookup(h,"hello world")==-1)
		printf("tried searching for \'hello world\' in hash table, not found\n");

	hash_delete(h);
	printf("hash table deleted\n");
}
