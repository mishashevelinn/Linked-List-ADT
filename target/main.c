#include <stdio.h>
#include "LinkedList.h"

/*************************************DRIVER**CODE***********************************************/
/*provides functionality for LinkedList's comparison */
bool int_cmp(Element e, Element g) {
    return *((int *) e) != *((int *) g);
}

int main() {


    LinkedList ll = LLCreate();
    LLNode lln = NULL;
    int i;

    for (i = 0; i < 6; i++)
        LLAdd(ll, &i, sizeof(int));
    i = 3;
    LLRemove(ll, &i, int_cmp);
    i = 9;
    LLRemove(ll, &i, int_cmp);

    printf("The list contains %d elements after adding 6 and removing 1\n", LLSize(ll));
    printf("Items:\n");
    for (lln = LLFirst(ll); lln; lln = LLNext(lln))
        printf("%d\n", *(int *) LLGetData(lln));

    LLDestroy(ll, int_cmp);

    printf("Done\n");

    return 0;
}