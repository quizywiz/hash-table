/*
    DESCRIPTION: Implementation of Doubly Linked List
    Author: Zed A. Shaw
    Modded by: Faiz Kothari
    email: faiz.off93@gmail.com
    version: 0.1

    TODO:
    1. Implement Mapping
    2. Implement Insertion
*/

#ifndef _MY_LIST_H
#define _MY_LIST_H

#include <stdlib.h>
#include <string.h>
struct ListNode;

typedef struct ListNode {
    struct ListNode *next;
    struct ListNode *prev;
    char value[25];
} ListNode;

typedef struct List {
    int count;
    ListNode *first;
    ListNode *last;
} List;

List *List_create();
void List_destroy(List *list);

#define List_count(A) ((A)->count)
#define List_first(A) ((A)->first != NULL ? (A)->first->value : NULL)
#define List_last(A) ((A)->last != NULL ? (A)->last->value : NULL)

void List_push(List *list, char value[]);
int List_pop(List *list);

//void List_unshift(List *list, void *value);
//void *List_shift(List *list);

int List_remove(List *list, ListNode *node);
int List_search_char(List *, char *);
int List_remove_char(List *, char *);
#define LIST_FOREACH(L, S, M, V) ListNode *_node = NULL;\
    ListNode *V = NULL;\
    for(V = _node = L->S; _node != NULL; V = _node = _node->M)

#endif
