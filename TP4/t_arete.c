/*************************************************************
Nom ........... : t_arete.c
Role .......... : Définitions des fonctions qui ont étés prototypées dans t_arete.h. Fonctions servant à manipuler une arête.
Auteur ...... : Youcef MEDILEH (N°Etu: 22004750)
Version ..... : V1 du 31/10/22
*************************************************************/

#include "t_arete.h"
#include <stdlib.h> //Malloc
#include <stdbool.h> //Variable booléenne

#define INFINI 1000.0 //Un poids réel supérieur à la plus grande longueur totale

//POUR VOIR LA DOCUMENTATION SUR CETTE FONCTION VOIR T_ARETE.H
_Bool arbreTrie(t_arete arbre[], int n){
    //On parcourt l'arbre
    for(int i = 0; i < n-1; ++i){
        if(arbre[i].poids > arbre[i+1].poids) //Si le poids d'avant est supérieur à celui d'après...
            return false; //..Alors il n'est pas trié (On veut pas ordre croissant)
    }

    //Si on est là c'est qu'on est passé dans la condition, donc l'arbre est trié par ordre croissant
    return true; //On renvoit donc que oui, il est trié
}

//POUR VOIR LA DOCUMENTATION SUR CETTE FONCTION VOIR T_ARETE.H
void kruskal(t_arete graphe[], int ordre, int s, int n){
    int indiceA = 0; //Indice de l'arbre
    int indiceG = 0; //Indice du graphe
    int x, s1, s2; //Sommets intermédiaires
    t_arete u; //Arête reliant 2 sommets x1 et x2


    //On initialise: Pas besoin d'allouer, les tableaux ne sont pas dynamiques.
    //Je les initialises donc ici.
    t_arete arbre[ordre-1]; //Tableau d'arêtes de poids minimum que l'on va retourner
    int connexe[ordre]; //Tableau contenant les numéros des sommets connexes de l'arbre
                        //Je ne l'ai pas alloué de manière dynamique car dans les lignes d'après on voit qu'il a une taille fixe
                        //qui est la variable ordre.

    for(x=0; x<ordre; x++) //On met le nom de tout les sommets (Initialisation en détail de connexe)
        connexe[x] = x; //Sommet 0, 1, 2, 3...., N-1

    //On trie l'arbre par ordre croissant des poids de ses "n" arêtes
    while(!arbreTrie(graphe,n)){ //Tant qu'il n'est pas trié
        for(int i=0; i<n-1; ++i){ //On parcourt l'arbre
            if(graphe[i].poids > graphe[i+1].poids){ //Si l'arête précédente à un poids plus élevé que le suivant, on les échangent
                //On échange
                t_arete indexI = graphe[i];
                graphe[i] = graphe[i+1];
                graphe[i+1] = indexI;
            }
        }
    }

    //Tant qu'on a pas traité toutes les arêtes du graphe et de l'arbre
    while(indiceA<ordre-1 && indiceG<n){
        u = graphe[indiceG]; //u est l'arête numéro indiceG du graphe
        s1 = connexe[u.x]; s2 = connexe[u.y]; //Les sommets que relie u.

        //S'il s'agit d'un cycle (Entre s1 et s2)
        if(s1 == s2)
            indiceG++; //Alors on passe à la suite sans rien ajouter dans l'arbre.
        else{ //Si ce n'est pas un cycle et donc il s'agit d'une "arête simple"
            arbre[indiceA] = u; //Cette arête va dans l'arbre à l'indiceA
            indiceA++; indiceG++; //On incrémente les deux indices, on passe à la suite dans l'arbre et le graphe.

            //On va indiquer que s1 et s2 sont connexes.
            for(x=0;x<ordre;x++)
                if(connexe[x]==s1)
                    connexe[x]==s2;
        }
    }

    //Si le graphe est non connexe. (Si le nombre d'arêtes de l'arbree < nombre de sommets - 1
    if(indiceA<ordre-1)
        printf("Le graphe n'est pas connexe\n"); //On l'indique.

    //On retourne l'arbre couvrant de poids minimum
    printf("\n\n========= Resultat le l'algorithme de KRUSKAL: ========= \n");
    printf("L'arbre couvrant de poids minimal possede %d arete.\n", sizeof(arbre)/sizeof(*arbre));
    printf("Les differentes aretes de l'arbre de poids minimal:\n");

    for(int arete = 0; arete<(sizeof(arbre)/sizeof(*arbre)); ++arete){
        printf("Arete du sommet %d a %d - Valeur: %f\n", arbre[arete].x, arbre[arete].y, arbre[arete].poids);
    }
}

//POUR VOIR LA DOCUMENTATION SUR CETTE FONCTION VOIR T_ARETE.H
void prim(float adjacencePoids[5][5], int ordre){
    int indiceA = 0; //Indice pour l'arbre
    int s, x, y, ymin; //Sommets intermédiaires
    float min; //Distance minimale du prochain sommet à marquer

    //On initialise: Pas besoin d'allouer, les tableaux ne sont pas dynamiques.
    //Je les initialises donc ici.
    t_arete arbre[ordre-1];
    int connexe[ordre]; //Comme le montre la suite, connexe et marques ont une taille fixe égale à ordre.
    int marques[ordre];

    //On marque tous les sommets à 0.
    for(int i = 0; i<ordre; ++i)
        marques[i] = 0;

    s=rand()%ordre; //On prend un sommet au hasard
    marques[s]=1; //Comme on va s'occuper de ce sommet, on le marque

    //Tant que les arêtes de l'arbre ne sont pas toutes traitées
    while(indiceA<ordre-1){
        min = INFINI;

        for(x=0; x<ordre; ++x) //Pour tous les sommets
            if(marques[x]) //Qui sont marqués
                for(y=0; y<ordre; y++){
                    //Recherche du sommet de poids minimum "ymin" adjacent à x et qui n'est pas marqué
                    if(adjacencePoids[x][y] && !marques[y] && adjacencePoids[x][y]<min){
                        min = adjacencePoids[x][y]; //Le poids minimum
                        ymin = y; //Le sommet y de poids minimum

                        //On marque ce sommet, qui a le poids minimal
                        marques[ymin] = 1;

                        //On insère cette arête au poids minimum dans l'indiceA de l'arbre
                        t_arete *areteAInserer = malloc(sizeof(*areteAInserer));

                        //Si le malloc échoue
                        if(areteAInserer == NULL){
                            printf("Echec du malloc de l'arête à insérer");
                            exit(1);
                        }

                        //On l'insère !
                        areteAInserer->poids = min; //La valeur
                        areteAInserer->x = x; //Les sommets
                        areteAInserer->y = ymin;
                        arbre[indiceA] = *areteAInserer; //On insère

                        //On passe à l'arête suivante de l'arbre
                        indiceA++;
                    }
                }

    }

    //On affiche l'arbre couvrant de poids minimum
    printf("\n\n========= Resultat le l'algorithme PRIM: ========= \n");
    printf("L'arbre couvrant de poids minimal possede %d aretes.\n", sizeof(arbre)/sizeof(*arbre));
    printf("Les differentes aretes de l'arbre de poids minimal:\n");
    for(int arete = 0; arete<(sizeof(arbre)/sizeof(*arbre)); ++arete){
        printf("Arete du sommet %d a %d - Valeur: %f\n", arbre[arete].x, arbre[arete].y, arbre[arete].poids);
    }
}