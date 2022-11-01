/*******************************************************
Nom ......... : maListe.c
Role ........ : Programme principal de ce TP.
Auteur ...... : Youcef MEDILEH (N°Etu: 22004750)
Version ..... : V2 du 31/10/22
********************************************************/

#include <stdio.h>
#include "liste.h"

//Le programme principal
int main() {
    //Coordonnées d'un point
    point p;
	p.x = 1;
	p.y = 2;

	cellule *liste = NULL; //La liste
	cellule *newCel = NULL; //Nouvelle cellule en cas de création

	//Essai de la fonction NouvCel.
	liste = NouvCel(p);
	Afficher(liste); //La cellule possède bien les bonnes coordonnées entrées

	//Essai de la fonction InsererCellule.
	point p2; p2.x = 3; p2.y = 4;
	newCel = NouvCel(p2); //On crée la cellule
	Inserercellule(0, newCel, liste); //Puis on l'insère
	Afficher(liste); //On voit que le point s'est ajouté après le premier

	//Essai de la fonction SupprimerCellule.
	SupprimerCellule(1, liste); //On supprime l'élément inséré auparavant
	Afficher(liste); //Il n'y est plus !
}