#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Taille maximale de la pile

typedef struct {
    int data[MAX_SIZE];
    int top; // Indice du sommet de la pile
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        fprintf(stderr, "Erreur lors de l'allocation de mémoire pour la pile\n");
        exit(EXIT_FAILURE);
    }
    stack->top = -1; // Initialiser la pile comme vide
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        fprintf(stderr, "La pile est pleine, impossible d'empiler\n");
        exit(EXIT_FAILURE);
    }
    stack->data[++stack->top] = value; // Incrémenter le sommet puis ajouter l'élément
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "La pile est vide, impossible de dépiler\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--]; // Retourner la valeur et décrémenter le sommet
}

void destroyStack(Stack* stack) {
    free(stack);
}

// Fonction pour renverser et afficher une liste d'entiers en utilisant une pile
void reverseAndPrint(int* list, int size) {
    Stack* stack = createStack();
    // Empiler les éléments de la liste sur la pile
    for (int i = 0; i < size; ++i) {
        push(stack, list[i]);
    }
    // Dépiler et afficher les éléments pour obtenir la liste renversée
    printf("Liste renversée : ");
    while (!isEmpty(stack)) {
        printf("%d ", pop(stack));
    }
    printf("\n");
    // Libérer la mémoire allouée à la pile
    destroyStack(stack);
}

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
