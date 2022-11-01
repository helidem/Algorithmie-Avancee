/*******************************************************
Nom ......... : monArbre.c
Role ........ : Le programme principal de ce TP
Auteur ...... : Youcef MEDILEH (N°Etu: 22004750)
Version ..... : V2 du 31/10/22
********************************************************/

#include <stdio.h> //Pour NULL
#include <stdlib.h> //Pour les malloc et free
#include <assert.h> //Pour les asserts
#include "arbre.h"

//Le programme principal
int main(){
    // test des fonctions de base de création de noeuds
    noeud node = nouvNoeud('T');
    insererFG(nouvNoeud('A'), &node,1);
    insererFG(nouvNoeud('B'), &node,2);
    insererFD(nouvNoeud('E'), &node,1);
    insererFD(nouvNoeud('L'), &node,2);

    //prefixe
    printf("Prefixe : \n");
    parcoursPrefixe(&node);
    // postfixe
    printf("Postfixe : \n");
    parcoursPostfixe(&node);
    // infixe
    printf("Infixe : \n");
    parcoursInfixe(&node);

}