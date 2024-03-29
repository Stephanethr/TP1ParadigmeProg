#ifndef LIB_GEST_TRAIN_H
#define LIB_GEST_TRAIN_H

#include <stdio.h> // Ajouté pour permettre l'utilisation de printf()

// Longueur maximale du nom de la ville
#define MAX_VILLE_LENGTH 50

// Structure de données pour représenter un horaire de train
typedef struct {
    char depart[MAX_VILLE_LENGTH];      // Ville de départ
    char arrivee[MAX_VILLE_LENGTH];     // Ville d'arrivée
    char heure_depart[6];               // Heure de départ (format HH:MM)
    char heure_arrivee[6];              // Heure d'arrivée (format HH:MM)
    int distance;                       // Distance entre les deux villes
} TrainHoraire;

// Structure de données pour représenter une liste d'horaires de trains
typedef struct {
    TrainHoraire* horaires; // Tableau dynamique d'horaires de trains
    int taille;             // Nombre d'horaires actuellement dans la liste
    int capacite;           // Capacité actuelle du tableau horaires
} ListeHoraires;

// Signature des fonctions
ListeHoraires* creerListeHoraires();
void detruireListeHoraires(ListeHoraires* liste);
void ajouterHoraire(ListeHoraires* liste, char depart[], char arrivee[], char heure_depart[], char heure_arrivee[], int distance);
void afficherHorairesDepart(ListeHoraires* liste, char villeDepart[]);
int trajetLePlusRapide(ListeHoraires* liste);
void trierHorairesParDepart(ListeHoraires* liste);
void chercherMoyenRapide(ListeHoraires* liste, char villeDepart[], char villeArrivee[]);
void chercherTrajetAvecCorrespondance(ListeHoraires* liste, char villeDepart[], char villeArrivee[]);
void chercherTrajetDirect(ListeHoraires* liste, char villeDepart[], char villeArrivee[]);

#endif
