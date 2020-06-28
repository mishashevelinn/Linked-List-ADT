//
// Created by misha on 25/06/2020.
//


#ifndef UNTITLED3_LINKEDLIST_H
#define UNTITLED3_LINKEDLIST_H

#include <stdbool.h>


typedef void *Element;
typedef struct LinkedList *LinkedList;
typedef struct LLNode *LLNode;

typedef bool (cmp)(Element, Element);
/*remove single node from list function pointer*/
typedef void (*clear)(Element);
/*Single Element constructor declaration*/
LLNode LLNodeCreate(Element, LLNode);

/*//Linked list constructor declaration, gets two pointers to functions*/
LinkedList LLCreate();

/*Remove single Element from hte list*/
void LLRemove(LinkedList, Element, cmp);

/*Destroys the whole list*/
void LLDestroy(LinkedList, cmp);

/*Add element to the list*/
void LLAdd(LinkedList, Element, unsigned int);

/*Get the number of elements in the list*/
int LLSize(LinkedList);

/*Get the Node's content*/
Element LLGetData(LLNode);

LLNode LLFirst(LinkedList);

LLNode LLNext(LLNode);

#endif //UNTITLED3_LINKEDLIST_H
