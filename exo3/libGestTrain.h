#ifndef LIB_GEST_TRAIN_H
#define LIB_GEST_TRAIN_H

// Longueur maximale du nom de la ville
#define MAX_VILLE_LENGTH 50

// Structures de données
typedef struct {
    char depart[MAX_VILLE_LENGTH];
    char arrivee[MAX_VILLE_LENGTH];
    char heure_depart[6]; // Format HH:MM
    char heure_arrivee[6]; // Format HH:MM
    int distance; // Distance entre les deux villes
} TrainHoraire;

typedef struct {
    TrainHoraire* horaires;
    int taille;
    int capacite;
} ListeHoraires;

// Prototypes de fonctions
ListeHoraires* creerListeHoraires();
void detruireListeHoraires(ListeHoraires* liste);
void ajouterHoraire(ListeHoraires* liste, char depart[], char arrivee[], char heure_depart[], char heure_arrivee[], int distance);
void afficherHorairesDepart(ListeHoraires* liste, char villeDepart[]);

#endif
