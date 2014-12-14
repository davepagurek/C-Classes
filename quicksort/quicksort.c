#include <stdio.h>
#include <time.h>

void quicksort(int arr[], int n) {
    if (n < 2) return;

    srand(time(NULL));

    //random pivot
    int pivot = rand()%n;
    int *head = arr;
    int *tail = arr+n-1;
    while (head <= tail) {
        if (*head < arr[pivot]) {
            head++;
        } else if (*tail > arr[pivot]) {
            tail--;
        } else {
            int temp = *head;
            *head = *tail;
            *tail = temp;
            head++;
            tail--;
        }
    }
    quicksort(arr, tail - arr + 1);
    quicksort(head, arr + n - head);
}

int main() {
    int arr[] = {5, 2, 9, 1, 7, 3, 4, 6, 8, 0};
    quicksort(arr, sizeof(arr)/sizeof(int));
    int i;
    for (i=0; i<sizeof(arr)/sizeof(int); i++) {
        printf("%d\n", arr[i]);
    }
}
