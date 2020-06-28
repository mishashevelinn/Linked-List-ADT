
#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>


/**********************************************************************/
struct LLNode {
    Element data;
    struct LLNode *next;
};

/*************************************************************************************************/
struct LinkedList {
    LLNode head;
};

/*************************************************************************************************/
// e is supposed to be the copy we want to put inside

LLNode LLNodeCreate(Element e, LLNode next) {
    LLNode lln = (LLNode) malloc(sizeof(struct LLNode));
    if (lln == NULL) {
        fprintf(stderr, "%s, %d: failed to allocate memory for new LLNode\n", __FILE__, __LINE__);
        exit(-1);
    }
    lln->next = next;
    lln->data = e;
    return lln;
}

/*************************************************************************************************/
LinkedList LLCreate() {
    LinkedList ll = (LinkedList) malloc(sizeof(struct LinkedList));
    if (ll == NULL) {
        fprintf(stderr, "%s, %d: failed to allocate memory for new LinkedList\n", __FILE__, __LINE__);
        exit(-1);
    }
    ll->head = LLNodeCreate(NULL, NULL);

    return ll;
}

/*************************************************************************************************/
void LLRemove(LinkedList ll, Element e, cmp compare) {

    LLNode curr = ll->head->next;
    LLNode prev = ll->head;

    while (curr && compare((curr->data), e)) {
        prev = curr;
        curr = curr->next;
    }
    if (curr) {
        prev->next = curr->next;
        free(curr->data);
        free(curr);
    }
}

/*************************************************************************************************/
void LLDestroy(LinkedList ll, cmp compare) {
    while (ll->head->next)
        LLRemove(ll, ll->head->next->data, compare);

    free(ll->head);
    free(ll);
}

/*************************************************************************************************/
void LLAdd(LinkedList ll, Element e, unsigned int data_size) {
    Element p =  malloc(data_size);
    if (p == NULL) {
        fprintf(stderr, "%s, %d: failed to allocate memory for new int\n", __FILE__, __LINE__);
        exit(-1);
    }
    int i;
    for (i = 0; i < data_size; i++) {
        *(char *) (p + i) = *(char *) (e + i); //copy data byte by byte, for systems where char = 8 bit
    }
    ll->head->next = LLNodeCreate(p, ll->head->next);
}

/*************************************************************************************************/
int LLSize(LinkedList ll) {
    int i = 0;
    LLNode curr = ll->head->next;
    for (; curr; curr = curr->next, i++);

    return i;
}

/*************************************************************************************************/
Element LLGetData(LLNode lln) {
    return lln->data;
}

/*************************************************************************************************/
LLNode LLFirst(LinkedList ll) {
    return ll->head->next;
}

/*************************************************************************************************/
LLNode LLNext(LLNode lln) {
    return lln ? lln->next : NULL;
}



