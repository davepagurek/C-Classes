#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../linkedlist/linkedlist.h"

List* merge(List* list1, List* list2);

List* mergesort(List* list);

int main() {

    srand(time(NULL));

    List* list = list_create();

    clock_t startTime = clock();

    int i=0;
    for (i=0; i<10000; i++) {
        list_push(list, rand()%1000+1);
    }
    List* list2 = mergesort(list);

    clock_t endTime = clock();

    printf("MERGE SORT time taken: %d milliseconds. ", endTime-startTime);

    return 0;
}

List* mergesort(List* list) {
    if (list->length==1) {
        return list;
    }
    List* half1 = list_create();
    List* half2 = list_create();

    int i=0;
    for (i=0; i<list->length; i++) {
        if (i<list->length/2) {
            list_push(half1, list_value(list, i));
        } else {
            list_push(half2, list_value(list, i));
        }
    }

    half1 = mergesort(half1);
    half2 = mergesort(half2);

    list = merge(half1, half2);

    list_delete(half1);
    list_delete(half2);
    free(half1);
    free(half2);

    return list;
}

List* merge(List* list1, List* list2) {

    int position1=0;
    int position2=0;
    int totalLength=0;

    List* output = list_create();

    //Begin merging of lists
    //Stop the loop after all both lists are exhausted
    while (totalLength<list1->length+list2->length) {

        //If there aren't any left in list 1, just add from list 2
        if (position1>=list1->length) {
            list_push(output, list_value(list2, position2));
            position2++;

        //If there aren't any left in list 2, just add from list 1
        } else if (position2>=list2->length) {
            list_push(output, list_value(list1, position1));
            position1++;

        //Otherwise, add from the list whose next number is the smallest
        } else if (list_value(list1, position1)<list_value(list2, position2)) {
            list_push(output, list_value(list1, position1));
            position1++;

        } else {
            list_push(output, list_value(list2, position2));
            position2++;
        }

        totalLength++;
    }

    return output;
}
