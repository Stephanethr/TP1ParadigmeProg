#ifndef PILE_H
#define PILE_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Taille maximale de la pile

typedef struct {
    int data[MAX_SIZE];
    int top; // Indice du sommet de la pile
} Stack;

// Créer une pile et renvoyer un pointeur vers elle
Stack* createStack();

// Vérifier si la pile est vide
int isEmpty(Stack* stack);

// Empiler un élément sur la pile
void push(Stack* stack, int value);

// Dépiler un élément de la pile et le renvoyer
int pop(Stack* stack);

// Libérer la mémoire allouée à la pile
void destroyStack(Stack* stack);

// Renverser et afficher une liste d'entiers en utilisant une pile
void reverseAndPrint(int* list, int size);

#endif /* PILE_H */
