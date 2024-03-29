#include <stdio.h>
#include "pile.h"
int main() {
    int list[] = {1, 2, 3, 4, 5};
    int size = sizeof(list) / sizeof(list[0]);

    printf("Liste originale : ");
    for (int i = 0; i < size; ++i) {
        printf("%d ", list[i]);
    }
    printf("\n");

    reverseAndPrint(list, size);

    return 0;
}