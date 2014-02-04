#ifndef _HASH_TABLE
#define _HASH_TABLE
#include "mylist.h"
#define MAX_SIZE 103
typedef struct hash_table
{
	int size;
	List* bucket[MAX_SIZE];
}
hash_table;
hash_table* hash_init();//creates a hash table
int hash_add(hash_table*, char* );//adds an element of string type
int hash_remove(hash_table*, char*);//removes element
int hash_lookup(hash_table*, char*);//checks if element is in the table
int hash( char*);//hash function
int hash_delete(hash_table*);//deletes the hash table, frees memory
#endif
