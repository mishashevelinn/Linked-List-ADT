#include <stdio.h>
#include "LinkedList.h"
#include <string.h>

/*************************************DRIVER**CODE***********************************************/
/*provides functionality for LinkedList's comparison */
#define  MAX_STR_LEN 28

bool int_cmp(Element e, Element g) {
    return *((int *) e) != *((int *) g);
}

bool str_cmp(Element e, Element g){
    return strcmp(((const char *) e), (( const char *) g));
}

int main() {

/****************************TEST**FOR**INTEGERS********************************/
    LinkedList ll_int = LLCreate();
    LLNode lln_int = NULL;
    int j;

    for (j = 0; j < 6; j++)
        LLAdd(ll_int, &j, sizeof(int));
    j = 3;
    LLRemove(ll_int, &j, int_cmp);
    j = 9;
    LLRemove(ll_int, &j, int_cmp);
    printf("\n--------RUNNING---TEST----FOR-----INTEGERS----------------\n");
    printf("The list contains %d elements after adding 6 and removing 1\n", LLSize(ll_int));
    printf("Items:\n");
    for (lln_int = LLFirst(ll_int); lln_int; lln_int = LLNext(lln_int))
        printf("%d\n", *(int *) LLGetData(lln_int));

    LLDestroy(ll_int, int_cmp);


    printf("Done\n");

 /****************************TEST**FOR**STRINGS********************************/

    char * abc[] = {"Galois is cool", "misha", "Lagrange", "adir", "L'hopital"};
    LinkedList ll = LLCreate();
    LLNode lln = NULL;
    int i;

    for (i = 0; i < 5; i++)
        LLAdd(ll, abc[i], MAX_STR_LEN );
    i = 1;
    LLRemove(ll, abc[i], str_cmp);
    i = 9;
    LLRemove(ll, abc[i], str_cmp);
    printf("\n--------RUNNING---TEST----FOR-----STRINGS-----------------\n");
    printf("The list contains %d elements after adding 5 and removing 1\n", LLSize(ll));
    printf("Items:\n");
    for (lln = LLFirst(ll); lln; lln = LLNext(lln))
        printf("%s\n", (char *) LLGetData(lln));
    LLDestroy(ll, str_cmp);
    printf("Done\n");
    return 0;

}

