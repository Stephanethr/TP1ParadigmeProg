#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include "thirylisteint.h"

/* La fonction menu affiche un menu à l'utilisateur et demande à l'utilisateur de saisir un choix.
   @input: Aucun.
   @output: Le choix saisi par l'utilisateur.
   @precondition: Aucune.
   @postcondition: Le choix de l'utilisateur est renvoyé.
*/
int menu()
{
    int choix = 0;
    printf("1 Creer une liste d'entiers compris entre 0 et 20 de taille aleatoire comprise entre 1 et 20\n"
           "2 Ajouter un élément entier aléatoire (compris entre 0 et 20) en tête de liste\n"
           "3 Inserer un élément entier aléatoire dans sa place dans la liste suivant l'ordre croissant des premiers éléments\n"
           "4 Supprimer l'élément de tête\n"
           "5 Supprimer tous les maillons d'une valeur donnee\n"
           "6 Detruire liste\n"
           "7 Sauver la liste courante en binaire dans le fichier \"saveliste.bin\"\n"
           "8 Charger une liste depuis le fichier \"savelist.bin\"\n");

    scanf("%d", &choix);
    rewind(stdin);

    return choix;
}

/* La fonction principale du programme.
   @input: Aucun.
   @output: 0 en cas de succès.
   @precondition: Aucune.
   @postcondition: Le programme exécute les actions en fonction du choix de l'utilisateur.
*/
int main()
{
    maillon_int *premier = NULL;
    maillon_int *nouveau;
    int fin = 0;
    int i, nb;

    srand((unsigned)time(NULL));
    while (!fin)
    {
        i = menu();
        switch (i)
        {

        case 1:
            detruire_liste(&premier); // Détruire la liste précédente
            nb = rand() % 20 + 1;     // Taille aléatoire entre 1 et 20
            for (int j = 0; j < nb; j++)
            {
                nouveau = init_elt();                      // Initialiser un nouvel élément
                premier = ajout_tete_v1(premier, nouveau); // Ajouter à la tête de la liste
            }
            parcourir(premier); // Afficher la liste
            break;

        case 2:                               // Ajouter
            nouveau = init_elt();             // Initialiser un nouvel élément
            ajout_tete_v2(&premier, nouveau); // Ajouter à la tête de la liste
            parcourir(premier);               // Afficher la liste
            break;

        case 3:                          // Inserer (ordre croissant)
            nouveau = init_elt();        // Initialiser un nouvel élément
            inserer2(&premier, nouveau); // Insérer dans l'ordre croissant
            parcourir(premier);          // Afficher la liste
            break;

        case 4:                        // Supprimer debut
            supprimer_debut(&premier); // Supprimer le premier élément
            parcourir(premier);        // Afficher la liste
            break;

        case 5: // Supprimer un maillon d'une valeur donnee
            printf("Entrez la valeur à supprimer : ");
            scanf("%d", &nb);
            critere_supp_un2(&premier, nb); // Supprimer les éléments ayant la valeur donnée
            parcourir(premier);             // Afficher la liste
            break;

        case 6:                       // Detruire liste
            detruire_liste(&premier); // Détruire la liste
            parcourir(premier);       // Afficher la liste (devrait être vide)
            break;

        case 7:                    // Sauver liste
            sauver_liste(premier); // Sauvegarder la liste dans un fichier binaire
            break;

        case 8:                       // Charger liste
            detruire_liste(&premier); // Détruire la liste précédente
            premier = load_liste();   // Charger une liste depuis un fichier binaire
            parcourir(premier);       // Afficher la liste chargée
            break;

        default:
            fin = 1; // Terminer le programme si choix invalide ou autre
            break;
        }
    }
    free(premier);
    free(nouveau);
    return 0;
}
