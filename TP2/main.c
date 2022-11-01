/*******************************************************
Nom ......... : main.c
Role ........ : Le programme principal
Auteur ...... : Jordan LAIRES (N�Etu: 51802252)
Version ..... : V1 du 19/10/20
********************************************************/

#include <stdio.h> //Printf
#include <stddef.h> //Pour NULL
#include <stdlib.h> //Malloc
#include "t_file.h"

/* R�sum�: Proc�dure qui recherche le plus court chemin depuis un sommet de r�f�rence
 * Param�tre adjacence: Matrice d'adjacence du graphe
 * Param�tre ordre: Nombre de sommets
 * Param�tre s: Num�ro du sommet de r�f�rence
 * Param�tre l: Tableau dynamique allou� des longueurs minimales des sommets depuis s
 * Param�tre pred: Tableau dynamique allou� des pr�d�cesseurs des sommets
 *
 * PS: J'ai remplac� "int** adjacence" par "int adjacence[6][6]" car la fonction
 * n'avait pas acc�s aux valeurs de la matrice sinon et faisait planter le programme.
 */
void plusCourtChemin(int adjacence[4][4], int ordre, int s, int* l, int* pred) {
    // Variables locales
    int* marques; // tableau dynamique indiquant si les sommets sont marqu�s ou non
    int x, y; // num�ros de sommets interm�diaires
    t_file* f; // file d'attente de sommets � cr�er en s'inspirant des listes doublement chain�e avec un .h et un .c d�di�

    // Allouer le tableau marques
    marques = (int*)malloc(ordre*sizeof(int)); //c'etait marques

    if (marques == NULL) {
        printf("L'allocation m�moire de marques a �chou� !");
        exit(1);
    }

    // Initialiser les marquages et les longueurs minimales � 0
    for (x = 0; x < ordre; x++) {
        marques[x] = 0;
        l[x] = 0;
    }

    // Marquer le sommet s � 1
    marques[s] = 1;

    // Cr�er (allouer) la file f et enfiler s dans f
    f = initialiser();
    enfiler(f, s);

    while (f->premierDeLaFile != NULL) { // Tant que la file f n'est pas vide
        x = defiler(f);// D�filer le premier sommet x de la file f

        // Pour tous les sommets y adjacents � x et non marqu�s
        for (y = 0; y < ordre; y++)
            if (adjacence[x][y] == 1 && !marques[y]) {
                printf("je suis dedans!!\n");
                marques[y] = 1; // marquer le sommet y
                enfiler(f, y); // enfiler le sommet y dans f
                pred[y] = x; // x est le pr�d�cesseur de y
                l[y] = l[x] + 1; // // incr�menter la longueur de y
            }
    }
}

/* R�sum�: Fonction qui cr�e un graphe al�atoire (Modifier le nombre de sommets dans la fonction en dur
 *         Puis elle va ex�cuter la fonction de recherche du plus court chemin avec ce graphe al�atoire pr�c�demment cr�e.
 *
 * PS: On ne peut pas mettre de variable en taille de matrice en C....
 *     Sinon j'aurais mis en Param�tre le nombre de sommets....
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

    //Si le malloc �choue
    if (longueursMini == NULL || predecesseurs == NULL) {
        printf("L'allocation m�moire de longueursMini ET/OU predecesseurs a �chou�e !");
        exit(1);
    }

    plusCourtChemin(randomMat, nbsommets, 1, longueursMini, predecesseurs);

}

//Le programme principal
int main() {
    //Pour tester si le type t_file marche bien, d�commenter.
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

    //Si le malloc �choue
    if (longueursMini == NULL || predecesseurs == NULL) {
        printf("L'allocation m�moire de longueursMini ET/OU predecesseurs a �chou�e !");
        exit(1);
    }

    plusCourtChemin(mat, ordre, 1, longueursMini, predecesseurs);

    //Affichage des r�sultats
    for (int x = 0; x < ordre; x++) {
        printf("Sommet %d : longueur minimale = %d, predecesseur = %d\n", x, longueursMini[x], predecesseurs[x]);
    }

    //Lib�ration de la m�moire
    //free(longueursMini);
    //free(predecesseurs);
    

    

    return 0;
}
