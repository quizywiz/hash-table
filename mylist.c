/*
    DESCRIPTION: Implementation of Doubly Linked List
    Author: Zed A. Shaw
    Modded by: Faiz Kothari
    email: faiz.off93@gmail.com
    version: 0.1

    TODO:
    1. Implement Mapping
*/
#include<stdio.h>
#include "mylist.h"
#include <stdlib.h>
#include <string.h>
#include<string.h>
List *List_create()
{
    List * p = malloc(sizeof(List));
    if(p){
        p->count = 0;
        p->first = NULL;
        p->last = NULL;
        return p;
    }
    else
        return NULL;
}
void List_destroy(List *list)
{//printf("2\n");
    LIST_FOREACH(list, first, next, cur){
        if(cur->prev) {
            free(cur->prev);
        }
    }

    free(list->last);
    free(list);
}
void List_push(List *list, char value[])
{
    ListNode *node = malloc(sizeof(ListNode));
    if(node){
	int m = 25>strlen(value)?strlen(value):25;
        int i;
	for(i=0;i<m;i++)
	node->value[i] = value[i];
        if(list->last == NULL){
            list->first = node;
            list->last = node;
        }
        else{
            list->last->next = node;
            node->prev = list->last;
            list->last = node;
        }
        list->count++;
        return;
    }
    else
        return;
}
int List_pop(List *list)
{
    ListNode *node = list->last;
    return (node != NULL) ? List_remove(list, node) : -1;
}
/*void List_unshift(List *list, void *value)
{
    ListNode *node = malloc(sizeof(ListNode));
    if(node){
        node->value = value;
        if(list->first == NULL){
            list->first = node;
            list->last = node;
        }
        else{
            node->next = list->first;
            list->first->prev = node;
            list->first = node;
        }
        list->count++;
    }
    else
        return;
}

void *List_shift(List *list)
{
    ListNode *node = list->first;
    return node != NULL ? List_remove(list, node) : NULL;
}
*/
int List_remove(List *list, ListNode *node)
{
    int result = -1;

    if(list->count != 0 && node != NULL){
        if(node == list->first && node == list->last) {
            list->first = NULL;
            list->last = NULL;
        }
        else if(node == list->first) {
            list->first = node->next;
            //check(list->first != NULL, "Invalid list, somehow got a first that is NULL.");
            list->first->prev = NULL;
        }
        else if (node == list->last) {
            list->last = node->prev;
            //check(list->last != NULL, "Invalid list, somehow got a next that is NULL.");
            list->last->next = NULL;
        }
        else{
            ListNode *after = node->next;
            ListNode *before = node->prev;
            after->prev = before;
            before->next = after;
        }
        list->count--;
        //result = node->value;
        free(node);
        return -result;
    }
    else
        return result;
}

int List_search_char(List *list, char element[])
{
	//printf("00\n");
	ListNode *node = list->first;
	//printf("1\n");
	while(node!=NULL)
	{
		//printf("1\n");
		//printf("comparing %s and %s",(char*)(node->value),element);
		if(strcmp(node->value, element)==0)
		{
			return 1;
		}
	node= node->next;
	}
	//printf("2\n");
	return -1;
}

int List_remove_char(List * list, char * element)
{
	ListNode *node = list->first;
	while(node!=NULL)
	{
		if(strcmp(node->value, element)==0)
		{
			List_remove(list,node);
			return 1;
		}
	node= node->next;
	}
	return -1;
}

