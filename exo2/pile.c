#include "pile.h"
#include <stdio.h>
#include <stdlib.h>


// Créer une pile et renvoyer un pointeur vers elle
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        perror("Erreur lors de l'allocation de mémoire pour la pile");
        exit(EXIT_FAILURE);
    }
    stack->top = -1; // Initialiser la pile comme vide
    return stack;
}

// Vérifier si la pile est vide
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Empiler un élément sur la pile
void push(Stack* stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        fprintf(stderr, "La pile est pleine, impossible d'empiler\n");
        exit(EXIT_FAILURE);
    }
    stack->data[++stack->top] = value; // Incrémenter le sommet puis ajouter l'élément
}

// Dépiler un élément de la pile et le renvoyer
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "La pile est vide, impossible de dépiler\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--]; // Retourner la valeur et décrémenter le sommet
}

// Libérer la mémoire allouée à la pile
void destroyStack(Stack* stack) {
    free(stack);
}

// Renverser et afficher une liste d'entiers en utilisant une pile
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

