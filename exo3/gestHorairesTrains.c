#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libGestTrain.h"


ListeHoraires* creerListeHoraires() {
    ListeHoraires* liste = (ListeHoraires*)malloc(sizeof(ListeHoraires));
    if (liste == NULL) {
        fprintf(stderr, "Erreur lors de l'allocation de mémoire pour la liste d'horaires\n");
        exit(EXIT_FAILURE);
    }
    liste->taille = 0;
    liste->capacite = 10; // Capacité initiale, peut être ajustée si nécessaire
    liste->horaires = (TrainHoraire*)malloc(liste->capacite * sizeof(TrainHoraire));
    if (liste->horaires == NULL) {
        fprintf(stderr, "Erreur lors de l'allocation de mémoire pour les horaires\n");
        exit(EXIT_FAILURE);
    }
    return liste;
}

void detruireListeHoraires(ListeHoraires* liste) {
    free(liste->horaires);
    free(liste);
}

void ajouterHoraire(ListeHoraires* liste, char depart[], char arrivee[], char heure_depart[], char heure_arrivee[], int distance) {
    if (liste->taille == liste->capacite) {
        liste->capacite *= 2;
        liste->horaires = (TrainHoraire*)realloc(liste->horaires, liste->capacite * sizeof(TrainHoraire));
        if (liste->horaires == NULL) {
            fprintf(stderr, "Erreur lors de la réallocation de mémoire pour les horaires\n");
            exit(EXIT_FAILURE);
        }
    }
    strcpy(liste->horaires[liste->taille].depart, depart);
    strcpy(liste->horaires[liste->taille].arrivee, arrivee);
    strcpy(liste->horaires[liste->taille].heure_depart, heure_depart);
    strcpy(liste->horaires[liste->taille].heure_arrivee, heure_arrivee);
    liste->horaires[liste->taille].distance = distance;
    liste->taille++;
}

void afficherHorairesDepart(ListeHoraires* liste, char villeDepart[]) {
    for (int i = 0; i < liste->taille; ++i) {
        if (strcmp(liste->horaires[i].depart, villeDepart) == 0) {
            printf("Départ de %s à destination de %s à %s\n", liste->horaires[i].depart,
                   liste->horaires[i].arrivee, liste->horaires[i].heure_depart);
        }
    }
}
