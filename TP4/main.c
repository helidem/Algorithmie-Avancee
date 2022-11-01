/*************************************************************
Nom ........... : main.c
Role .......... : Le programme principal du TP4.
Auteur ...... : Youcef MEDILEH (N°Etu: 22004750)
Version ..... : V1 du 31/10/22
*************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "t_arete.h"

int main(){
    //================ TEST DE KRUSKAL ============================
        //====== AVEC UN GRAPHE A 3 SOMMETS ==========
   /* t_arete graphe[3];

    t_arete arete01;
    arete01.poids = 1;
    arete01.x = 0;
    arete01.y = 1;

    t_arete arete02;
    arete02.poids = 2;
    arete02.x = 0;
    arete02.y = 2;

    t_arete arete12;
    arete12.poids = 3;
    arete12.x = 1;
    arete12.y = 2;

    graphe[0] = arete01; graphe[1] = arete02; graphe[2] = arete12;

    kruskal(graphe, 3, 0, 3);*/

        //====== AVEC UN GRAPHE A 5 SOMMETS ==========

    t_arete graphe2[8];

    t_arete arete01;
    arete01.poids = 2;
    arete01.x = 0;
    arete01.y = 1;

    t_arete arete02;
    arete02.poids = 1;
    arete02.x = 0;
    arete02.y = 2;

    t_arete arete03;
    arete03.poids = 2;
    arete03.x = 0;
    arete03.y = 3;

    t_arete arete31;
    arete31.poids = 5;
    arete31.x = 3;
    arete31.y = 1;

    t_arete arete23;
    arete23.poids = 4;
    arete23.x = 2;
    arete23.y = 3;

    t_arete arete21;
    arete21.poids = 3;
    arete21.x = 2;
    arete21.y = 1;

    t_arete arete24;
    arete24.poids = 1;
    arete24.x = 2;
    arete24.y = 4;

    t_arete arete34;
    arete34.poids = 2;
    arete34.x = 3;
    arete34.y = 4;

    graphe2[0]=arete01;
    graphe2[1]=arete02;
    graphe2[2]=arete03;
    graphe2[3]=arete31;
    graphe2[4]=arete23;
    graphe2[5]=arete21;
    graphe2[6]=arete24;
    graphe2[7]=arete34;

    kruskal(graphe2, 5, 0, 8);


    //================ TEST DE PRIM ============================
    float mat[3][3] = { //Arbre 3 sommets
        {0,1,2},
        {1,0,3},
        {2,3,0}
    };

    float mat2[5][5] = { //Arbre 5 sommets
        {0,2,1,2,0},
        {2,0,3,5,0},
        {1,3,0,4,1},
        {2,5,4,0,2},
        {0,0,1,2,0}
    };

    //POUR ESSAYER L'UN DES DEUX ARBRES. POUR CELA MODIFIER LE PARAMETRE POIDSADJACENCE ET CHANGER LES VALEURS DE LA TAILLE DU TABLEAU
    //DANS LE PROTOTYPE ET LA DEFINITION DE LA FONCTION DANS T_ARETE.H et .C
    //prim(mat, 3);
    prim(mat2, 5);


   //ON VOIT QUE POUR LE MEME ARBRE, KRUSKAL ET PRIM DONNENT LE MEME ARBRE COUVRANT MINIMAL
   //L'ordre des arêtes est juste différents mais ce sont exactement les mêmes: L'arbre est identique.
}