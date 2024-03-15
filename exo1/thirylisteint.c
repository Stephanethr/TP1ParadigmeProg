#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include "thirylisteint.h"


/* Initialise un nouveau maillon avec une valeur aléatoire entre 0 et 20.
   @input: Aucun.
   @output: Un pointeur vers le nouveau maillon initialisé.
   @precondition: Aucune.
   @postcondition: Un nouveau maillon avec une valeur aléatoire est créé et retourné.
*/
maillon_int *init_elt()
{
    maillon_int *p_nv_elt = malloc(sizeof(maillon_int));
    p_nv_elt->val = rand() % 21;
    p_nv_elt->p_suiv = NULL;
    return p_nv_elt;
}

/* Ajoute un nouveau maillon en tête de liste (version 1).
   @input: p_tete - Pointeur vers la tête de liste existante, p_nv_elt - Pointeur vers le nouveau maillon.
   @output: Le pointeur vers la nouvelle tête de liste.
   @precondition: Aucune.
   @postcondition: Le nouveau maillon est ajouté en tête de liste et la nouvelle tête est retournée.
*/
maillon_int *ajout_tete_v1(maillon_int *p_tete, maillon_int *p_nv_elt)
{
    p_nv_elt->p_suiv = p_tete;
    p_tete = p_nv_elt;
    return p_tete;
}

/* Ajoute un nouveau maillon en tête de liste (version 2).
   @input: p_p_tete - Pointeur vers le pointeur de la tête de liste, p_nv_elt - Pointeur vers le nouveau maillon.
   @output: Aucun.
   @precondition: Aucune.
   @postcondition: Le nouveau maillon est ajouté en tête de liste.
*/
void ajout_tete_v2(maillon_int **p_p_tete, maillon_int *p_nv_elt)
{
    p_nv_elt->p_suiv = *p_p_tete;
    *p_p_tete = p_nv_elt;
}

/* Parcourt et affiche les éléments de la liste.
   @input: p_tete - Pointeur vers la tête de liste.
   @output: Aucun.
   @precondition: Aucune.
   @postcondition: Les éléments de la liste sont affichés à l'écran.
*/
void parcourir(maillon_int *p_tete)
{
    if (p_tete == NULL)
        printf("liste vide");
    else
        while (p_tete != NULL)
        {
            printf("%d--", p_tete->val);
            p_tete = p_tete->p_suiv;
        }
    putchar('\n');
}

/* Insère un nouveau maillon dans la liste suivant l'ordre croissant des premiers éléments.
   @input: p_tete - Pointeur vers la tête de liste existante, p_nv_elt - Pointeur vers le nouveau maillon.
   @output: Le pointeur vers la nouvelle tête de liste.
   @precondition: Aucune.
   @postcondition: Le nouveau maillon est inséré dans la liste selon l'ordre croissant et la nouvelle tête est retournée.
*/
maillon_int *inserer1(maillon_int *p_tete, maillon_int *p_nv_elt)
{
    maillon_int *n, *prec;

    if (p_tete == NULL || p_nv_elt->val <= p_tete->val)
    {
        p_nv_elt->p_suiv = p_tete;
        p_tete = p_nv_elt;
    }
    else
    {
        n = prec = p_tete;
        while (n != NULL && p_nv_elt->val > n->val)
        {
            prec = n;
            n = n->p_suiv;
        }
        p_nv_elt->p_suiv = n;
        prec->p_suiv = p_nv_elt;
    }
    return p_tete;
}

/* Insère un nouveau maillon dans la liste suivant l'ordre croissant des premiers éléments (version 2).
   @input: prem - Pointeur vers le pointeur de la tête de liste, e - Pointeur vers le nouveau maillon.
   @output: Aucun.
   @precondition: Aucune.
   @postcondition: Le nouveau maillon est inséré dans la liste selon l'ordre croissant.
*/
void inserer2(maillon_int **prem, maillon_int *e)
{
    maillon_int *n, *prec;
    if (*prem == NULL || e->val <= (*prem)->val)
    {
        e->p_suiv = *prem;
        *prem = e;
    }
    else
    {
        n = prec = *prem;
        while (n != NULL && e->val > n->val)
        {
            prec = n;
            n = n->p_suiv;
        }
        e->p_suiv = n;
        prec->p_suiv = e;
    }
}

/* Supprime le premier élément de la liste.
   @input: prem - Pointeur vers le pointeur de la tête de liste.
   @output: Aucun.
   @precondition: Aucune.
   @postcondition: Le premier élément de la liste est supprimé.
*/
void supprimer_debut(maillon_int **prem)
{
    maillon_int *n;
    if (*prem != NULL)
    {
        n = *prem;
        *prem = (*prem)->p_suiv;
        free(n);
    }
}

/* Supprime tous les maillons de la liste ayant une valeur donnée.
   @input: prem - Pointeur vers la tête de liste, val - Valeur à supprimer.
   @output: Le pointeur vers la nouvelle tête de liste.
   @precondition: Aucune.
   @postcondition: Tous les maillons de la liste ayant la valeur donnée sont supprimés et la nouvelle tête est retournée.
*/
maillon_int *critere_supp_un1(maillon_int *prem, int val)
{
    maillon_int *e = prem, *prec = NULL, *n;

    while (e != NULL)
    {
        n = NULL;
        if (e->val == val)
        {
            n = e;
            if (prec == NULL)
                prem = e->p_suiv;
            else
                prec->p_suiv = e->p_suiv;
        }
        else
            prec = e;
        e = e->p_suiv;
        if (n != NULL)
            free(n);
    }
    return prem;
}

/* Supprime tous les maillons de la liste ayant une valeur donnée (version 2).
   @input: prem - Pointeur vers le pointeur de la tête de liste, val - Valeur à supprimer.
   @output: Aucun.
   @precondition: Aucune.
   @postcondition: Tous les maillons de la liste ayant la valeur donnée sont supprimés.
*/
void critere_supp_un2(maillon_int **prem, int val)
{
    maillon_int *e = *prem, *prec = NULL, *n;

    while (e != NULL)
    {
        n = NULL;
        if (e->val == val)
        {
            n = e;
            if (prec == NULL)
                *prem = e->p_suiv;
            else
                prec->p_suiv = e->p_suiv;
        }
        else
            prec = e;
        e = e->p_suiv;
        if (n != NULL)
            free(n);
    }
}

/* Détruit tous les maillons de la liste.
   @input: prem - Pointeur vers le pointeur de la tête de liste.
   @output: Aucun.
   @precondition: Aucune.
   @postcondition: Tous les maillons de la liste sont supprimés.
*/
void detruire_liste(maillon_int **prem)
{
    maillon_int *n;
    while (*prem != NULL)
    {
        n = *prem;
        *prem = (*prem)->p_suiv;
        free(n);
    }
}

/* Détruit tous les maillons de la liste (version 2).
   @input: prem - Pointeur vers le pointeur de la tête de liste.
   @output: Aucun.
   @precondition: Aucune.
   @postcondition: Tous les maillons de la liste sont supprimés.
*/
void detruire_liste2(maillon_int **prem)
{
    while (*prem != NULL)
        supprimer_debut(prem);
}

/* Permet la sérialisation format binaire dans le fichier
"saveliste.bin" de la liste d'entier (maillon_int) dont
le pointeur sur le premier élément est passé en paramètre
@input : maillon_int * prem, pointeur sur l'élément de tête de la liste à sérialiser
@output : void
@precondition : le répertoire courant et le processus père permettent l'écriture
                le pointeur prem, est soit NULL (aucune action) soit pointe sur
                le premier élément d'une liste d'entiers
@postcondition : le fichier saveliste.bin contient les éléments de la liste
                dont le premier élément est pointé par prem.
                Nota : il n'y a pas de libération de la mémoire occupée par la
                liste. Il faut donc la détruire avant d'éventuellement la recharger.
*/
void sauver_liste(maillon_int *prem)
{
    // ouvrir un fichier binaire en écriture : suffixe b
    FILE *f = fopen("saveliste.bin", "wb");
    printf("Ouvertude du fichier %p\n", f);
    // si liste non vide
    if (prem != NULL)
    {
        if (f == NULL)
            fprintf(stderr, "erreur création fichier :%i\n", errno);
        else // parcourir la liste jusque fin
            while (prem != NULL)
            {
                // écrire chaque maillon en binaire
                if (1 != fwrite(prem, sizeof(maillon_int), 1, f))
                    fprintf(stderr, "Erreur d'écriture du maillon %p\n", prem);
                else
                    // passer au maillon suivant
                    prem = prem->p_suiv;
            }
        fclose(f); // fermer le fichier
    }
    else
        fprintf(stderr, "pas de sauvegarde pour une liste vide\n");
}

/* Charge une liste depuis un fichier binaire.
   @input: Aucun.
   @output: Un pointeur vers la tête de liste chargée.
   @precondition: Aucune.
   @postcondition: Si le fichier "saveliste.bin" existe, la liste est chargée et retournée.
                   Sinon, un message d'erreur est affiché et NULL est retourné.
*/
maillon_int *load_liste()
{
    FILE *f;
    maillon_int *prem = NULL, *p, e;
    if ((f = fopen("saveliste.bin", "rb")) != NULL)
    {
        prem = malloc(sizeof(maillon_int));
        fread(prem, sizeof(maillon_int), 1, f);
        p = prem;
        while (fread(&e, sizeof(maillon_int), 1, f))
        {
            p->p_suiv = malloc(sizeof(maillon_int));
            p = p->p_suiv;
            *p = e;
            p->p_suiv = NULL;
        }
        fclose(f);
    }
    else
        printf("erreur ou fichier inexistant");
    return prem;
}