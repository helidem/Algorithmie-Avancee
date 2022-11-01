/*******************************************************
Nom ......... : main.c
Role ........ : Le programme principal
Auteur ...... : Jordan LAIRES (N°Etu: 51802252)
Version ..... : V1 du 19/10/20
********************************************************/

#include <stdio.h> //Printf
#include <stddef.h> //Pour NULL
#include <stdlib.h> //Malloc
#include "t_file.h"

/* Résumé: Procédure qui recherche le plus court chemin depuis un sommet de référence
 * Paramètre adjacence: Matrice d'adjacence du graphe
 * Paramètre ordre: Nombre de sommets
 * Paramètre s: Numéro du sommet de référence
 * Paramètre l: Tableau dynamique alloué des longueurs minimales des sommets depuis s
 * Paramètre pred: Tableau dynamique alloué des prédécesseurs des sommets
 *
 * PS: J'ai remplacé "int** adjacence" par "int adjacence[6][6]" car la fonction
 * n'avait pas accès aux valeurs de la matrice sinon et faisait planter le programme.
 */
void plusCourtChemin(int adjacence[4][4], int ordre, int s, int* l, int* pred) {
    // Variables locales
    int* marques; // tableau dynamique indiquant si les sommets sont marqués ou non
    int x, y; // numéros de sommets intermédiaires
    t_file* f; // file d'attente de sommets à créer en s'inspirant des listes doublement chainée avec un .h et un .c dédié

    // Allouer le tableau marques
    marques = (int*)malloc(ordre*sizeof(int)); //c'etait marques

    if (marques == NULL) {
        printf("L'allocation mémoire de marques a échoué !");
        exit(1);
    }

    // Initialiser les marquages et les longueurs minimales à 0
    for (x = 0; x < ordre; x++) {
        marques[x] = 0;
        l[x] = 0;
    }

    // Marquer le sommet s à 1
    marques[s] = 1;

    // Créer (allouer) la file f et enfiler s dans f
    f = initialiser();
    enfiler(f, s);

    while (f->premierDeLaFile != NULL) { // Tant que la file f n'est pas vide
        x = defiler(f);// Défiler le premier sommet x de la file f

        // Pour tous les sommets y adjacents à x et non marqués
        for (y = 0; y < ordre; y++)
            if (adjacence[x][y] == 1 && !marques[y]) {
                marques[y] = 1; // marquer le sommet y
                enfiler(f, y); // enfiler le sommet y dans f
                pred[y] = x; // x est le prédécesseur de y
                l[y] = l[x] + 1; // // incrémenter la longueur de y
            }
    }
}

/* Résumé: Fonction qui crée un graphe aléatoire (Modifier le nombre de sommets dans la fonction en dur
 *         Puis elle va exécuter la fonction de recherche du plus court chemin avec ce graphe aléatoire précédemment crée.
 *
 * PS: On ne peut pas mettre de variable en taille de matrice en C....
 *     Sinon j'aurais mis en Paramètre le nombre de sommets....
 */
void grapheAleatoire() {
    int nbsommets = 4;

    int randomMat[4][4]; //Initialisation

    //Remplissage
    for (int col = 0; col < nbsommets; col++) {
        for (int ligne = 0; ligne < nbsommets; ligne++) {
            randomMat[col][ligne] = rand() % 2; //drand48() n'est pas connu par mon compilateur (undefined reference)
        }
    }

    //========================= PUIS ON ESSAIE L'ALGORITHME.

    //Initialisation des tableaux pour les utiliser dans la fonction plusCourtChemin
    int* longueursMini = malloc(sizeof(*longueursMini));
    int* predecesseurs = malloc(sizeof(*predecesseurs));

    //Si le malloc échoue
    if (longueursMini == NULL || predecesseurs == NULL) {
        printf("L'allocation mémoire de longueursMini ET/OU predecesseurs a échouée !");
        exit(1);
    }

    plusCourtChemin(randomMat, nbsommets, 1, longueursMini, predecesseurs);

}

//Le programme principal
int main() {
    //Pour tester si le type t_file marche bien, décommenter.
    //testFile()
    int ordre = 4;

    //La matrice d'adjacence de l'exercice 1.1 du TP1
    /*int mat[6][6] = {
        {0,1,0,0,1,0},
        {0,0,1,1,0,0},
        {0,1,0,1,0,1},
        {0,1,1,0,1,1},
        {1,0,0,1,0,0},
        {0,0,1,1,0,0}
    };*/

    int mat[4][4] = {
        {0,0,1,0},
        {0,0,1,1},
        {1,1,0,1},
        {0,1,1,0}
    };

    //Initialisation des tableaux pour les utiliser dans la fonction plusCourtChemin
    //int* longueursMini = malloc(sizeof(*mat));
    //int* predecesseurs = malloc(sizeof(*mat));
    int* longueursMini = (int*)malloc(ordre * sizeof(int));
    int* predecesseurs = (int*)malloc(ordre * sizeof(int));

    //Si le malloc échoue
    if (longueursMini == NULL || predecesseurs == NULL) {
        printf("L'allocation mémoire de longueursMini ET/OU predecesseurs a échouée !");
        exit(1);
    }

    plusCourtChemin(mat, ordre, 1, longueursMini, predecesseurs);

    //Affichage des résultats
    for (int x = 0; x < ordre; x++) {
        printf("Sommet %d : longueur minimale = %d, predecesseur = %d\n", x, longueursMini[x], predecesseurs[x]);
    }

    //Libération de la mémoire
    //free(longueursMini);
    //free(predecesseurs);
    

    

    return 0;
}
