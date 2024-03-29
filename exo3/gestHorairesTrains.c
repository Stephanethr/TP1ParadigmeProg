#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libGestTrain.h"

// Fonction pour créer une liste d'horaires
ListeHoraires* creerListeHoraires() {
    // Allocation de mémoire pour la liste d'horaires
    ListeHoraires* liste = (ListeHoraires*)malloc(sizeof(ListeHoraires));
    if (liste == NULL) {
        perror("Erreur lors de l'allocation de mémoire pour la liste d'horaires");
        exit(EXIT_FAILURE);
    }
    // Initialisation des attributs de la liste
    liste->taille = 0;
    liste->capacite = 10; // Capacité initiale, peut être ajustée si nécessaire
    // Allocation de mémoire pour les horaires
    liste->horaires = (TrainHoraire*)malloc(liste->capacite * sizeof(TrainHoraire));
    if (liste->horaires == NULL) {
        perror("Erreur lors de l'allocation de mémoire pour les horaires");
        exit(EXIT_FAILURE);
    }
    return liste;
}

// Fonction pour détruire une liste d'horaires
void detruireListeHoraires(ListeHoraires* liste) {
    free(liste->horaires);
    free(liste);
}

// Fonction pour ajouter un horaire à la liste d'horaires
void ajouterHoraire(ListeHoraires* liste, char depart[], char arrivee[], char heure_depart[], char heure_arrivee[], int distance) {
    // Vérifier si la liste doit être agrandie
    if (liste->taille == liste->capacite) {
        liste->capacite *= 2;
        TrainHoraire* new_horaires = (TrainHoraire*)realloc(liste->horaires, liste->capacite * sizeof(TrainHoraire));
        if (new_horaires == NULL) {
            perror("Erreur lors de la réallocation de mémoire pour les horaires");
            exit(EXIT_FAILURE);
        }
        liste->horaires = new_horaires;
    }
    // Copier les données de l'horaire dans la liste
    strcpy(liste->horaires[liste->taille].depart, depart);
    strcpy(liste->horaires[liste->taille].arrivee, arrivee);
    strcpy(liste->horaires[liste->taille].heure_depart, heure_depart);
    strcpy(liste->horaires[liste->taille].heure_arrivee, heure_arrivee);
    liste->horaires[liste->taille].distance = distance;
    liste->taille++;
}

// Fonction pour afficher les horaires de départ pour une ville donnée
void afficherHorairesDepart(ListeHoraires* liste, char villeDepart[]) {
    for (int i = 0; i < liste->taille; ++i) {
        if (strcmp(liste->horaires[i].depart, villeDepart) == 0) {
            printf("Départ de %s à destination de %s à %s\n", liste->horaires[i].depart,
                   liste->horaires[i].arrivee, liste->horaires[i].heure_depart);
        }
    }
}

// Fonction pour trouver l'indice du trajet le plus rapide
int trajetLePlusRapide(ListeHoraires* liste) {
    int index = -1;
    double max_vitesse = 0.0;

    for (int i = 0; i < liste->taille; ++i) {
        TrainHoraire trajet = liste->horaires[i];
        double temps_heures = (trajet.distance / 60.0); // Conversion en heures
        double vitesse = temps_heures / atof(trajet.heure_arrivee) - atof(trajet.heure_depart);

        if (vitesse > max_vitesse) {
            max_vitesse = vitesse;
            index = i;
        }
    }

    return index;
}

// Fonction de comparaison pour le tri des horaires par heure de départ
int compareHoraires(const void* a, const void* b) {
    return strcmp(((TrainHoraire*)a)->heure_depart, ((TrainHoraire*)b)->heure_depart);
}

// Fonction pour trier les horaires par heure de départ
void trierHorairesParDepart(ListeHoraires* liste) {
    qsort(liste->horaires, liste->taille, sizeof(TrainHoraire), compareHoraires);
}

// Fonction pour chercher le moyen le plus rapide de voyager entre deux villes
void chercherMoyenRapide(ListeHoraires* liste, char villeDepart[], char villeArrivee[]) {
    chercherTrajetDirect(liste, villeDepart, villeArrivee);
    chercherTrajetAvecCorrespondance(liste, villeDepart, villeArrivee);
}

// Fonction pour chercher un trajet direct entre deux villes
void chercherTrajetDirect(ListeHoraires* liste, char villeDepart[], char villeArrivee[]) {
    for (int i = 0; i < liste->taille; ++i) {
        if (strcmp(liste->horaires[i].depart, villeDepart) == 0 && strcmp(liste->horaires[i].arrivee, villeArrivee) == 0) {
            printf("Trajet direct trouvé de %s à %s : %s - %s\n", villeDepart, villeArrivee, liste->horaires[i].heure_depart, liste->horaires[i].heure_arrivee);
            return;
        }
    }
    printf("Aucun trajet direct trouvé de %s à %s\n", villeDepart, villeArrivee);
}

// Fonction pour chercher un trajet avec correspondance entre deux villes
void chercherTrajetAvecCorrespondance(ListeHoraires* liste, char villeDepart[], char villeArrivee[]) {
    for (int i = 0; i < liste->taille; ++i) {
        if (strcmp(liste->horaires[i].depart, villeDepart) == 0) {
            for (int j = 0; j < liste->taille; ++j) {
                if (strcmp(liste->horaires[j].depart, liste->horaires[i].arrivee) == 0 && strcmp(liste->horaires[j].arrivee, villeArrivee) == 0) {
                    printf("Trajet avec correspondance trouvé de %s à %s : %s - %s puis %s - %s\n", villeDepart, villeArrivee, liste->horaires[i].heure_depart, liste->horaires[i].heure_arrivee, liste->horaires[j].heure_depart, liste->horaires[j].heure_arrivee);
                    return;
                }
            }
        }
    }
    printf("Aucun trajet avec correspondance trouvé de %s à %s\n", villeDepart, villeArrivee);
}

