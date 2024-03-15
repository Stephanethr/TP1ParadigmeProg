#include <stdio.h>
#include "libGestTrain.h"

int main() {
    ListeHoraires* liste = creerListeHoraires();

    ajouterHoraire(liste, "Lille", "Paris", "08:00", "08:59", 237);
    ajouterHoraire(liste, "Lille", "Lyon", "07:00", "10:00", 709);
    ajouterHoraire(liste, "Lille", "Calais", "15:19", "18:34", 110);
    ajouterHoraire(liste, "Paris", "Marseille", "12:00", "18:00", 900);
    ajouterHoraire(liste, "Lyon", "Marseille", "10:07", "15:01", 450);
    ajouterHoraire(liste, "Lyon", "Marseille", "11:50", "17:00", 450);

    printf("\nHoraires de départ de Lille :\n");
    afficherHorairesDepart(liste, "Lille");

    printf("\nHoraires de départ de Lyon :\n");
    afficherHorairesDepart(liste, "Lyon");

    printf("\nHoraires de départ de Paris :\n");
    afficherHorairesDepart(liste, "Paris");

    detruireListeHoraires(liste);

    return 0;
}
