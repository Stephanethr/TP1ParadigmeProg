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

    int index_trajet_rapide = trajetLePlusRapide(liste);
    if (index_trajet_rapide != -1) {
        printf("\nTrajet avec la vitesse moyenne la plus élevée :\n");
        printf("Départ de %s à destination de %s à %s\n", liste->horaires[index_trajet_rapide].depart,
               liste->horaires[index_trajet_rapide].arrivee, liste->horaires[index_trajet_rapide].heure_depart);
    } else {
        printf("\nAucun trajet trouvé.\n");
    }

    trierHorairesParDepart(liste);
    printf("\nListe des horaires triée par heure de départ :\n");
    for (int i = 0; i < liste->taille; ++i) {
        printf("Départ de %s à destination de %s à %s\n", liste->horaires[i].depart,
               liste->horaires[i].arrivee, liste->horaires[i].heure_depart);
    }

    printf("\nRecherche du moyen le plus rapide pour aller de Lille à Marseille :\n");
    chercherMoyenRapide(liste, "Lille", "Marseille");

    detruireListeHoraires(liste);

    return 0;
}
