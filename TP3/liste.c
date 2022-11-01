/*******************************************************
Nom ......... : liste.c
Role ........ : Fichier définissant les fonctions pour ce TP
Auteur ...... : Youcef MEDILEH (N°Etu: 22004750)
Version ..... : V2 du 31/10/22
********************************************************/

#include <stdio.h> //pour NULL
#include <stdbool.h> //pour "false", "true" et le type booléen (_bool)
#include <assert.h> //pour assert()
#include <stdlib.h> //pour malloc() et free()

#include "liste.h"

//Variable globale
int NB_CELLULES = 0; //Nombre de cellules crées (Dans la liste)

// ===================== DEFINITION DES FONCTIONS =======================
//Voir documentations des fonctions dans liste.h

cellule *NouvCel(point p){
    cellule *newCel = NULL;
	newCel = (cellule *)malloc(sizeof(p)); //Allocation de la mémoire

	//Malloc réussi
	if(newCel != NULL){
		newCel->pt = p; //Assignation du point
		newCel->avant = NULL; //Cette cellule n'est attachée à aucune autre cellule
		newCel->suivante = NULL;

		NB_CELLULES++; //Une cellule en plus

		return newCel;
	}else{
		printf("Erreur fatale: Malloc échoué\n");
		exit(0);
	}
}

void Inserercellule(int pl, cellule *cel, cellule *liste){
    assert(pl>=0); //Vérification de la valeur entrée (Ne doit pas être négative!)

    int pointeur = 0; //Pointeur qui sert à se positionner dans la liste pour insérer la cellule
    _Bool inseree = false; //La cellule a-t-elle été inserée ?

    cellule *pos = liste;
    cellule *prochaine_pos;

    //Tant que nous nous ne sommes pas à la fin de la liste et que la cellule n'a pas encore été insérée
    while((pos != NULL) && !inseree){
        prochaine_pos = pos->suivante; //On avance dans la liste

        if(pointeur == pl){ //Si nous sommes arrivés à l'endroit où l'on veut insérer la cellule
            cel->avant = pos; //On décale la cellule à cette place
            pos->suivante = cel;

            if(prochaine_pos != NULL){ //Si nous sommes arrivés à la fin de la liste
                prochaine_pos->avant = cel; //On décale la cellule
                cel->suivante = prochaine_pos;
            }

            inseree = true; //La cellule a bien été inserée, on peut sortir du while
        }

        pointeur++; //On se décale sur la liste
        pos = prochaine_pos; //On passe à la position suivante (On avance dans la liste)
    }
}

void SupprimerCellule(int pl, cellule *liste){
    assert(pl>0); //Vérification de la valeur de pl (Doit être positive)

    int pointeur = 0;
    _Bool supprimee = false; //Supprimée ?

    cellule *pos = liste;
    cellule *prochaine_pos;
    cellule *precedente_pos;

    //Tant que nous nous ne sommes pas arrivés à la fin de la liste et que la cellule n'a pas encore été supprimée
    while((pos != NULL) && !supprimee){
        prochaine_pos = pos->suivante; //On avance

        if(pointeur == pl){
            precedente_pos = pos->avant;
            precedente_pos->suivante = prochaine_pos;

            if(prochaine_pos != NULL) //Si fin de la liste
                prochaine_pos->avant = precedente_pos;

            free(pos); //On libère l'espace mémoire
            supprimee = true; //La cellule a été supprimé, on peut sortir de la boucles
        }

        pointeur++; //On avance
        pos = prochaine_pos;
    }
}

void Afficher(cellule *liste){
    cellule *pos = liste;
    cellule *prochaine_pos;

    point p;

    //Histoire d'esthétisme....
    printf("========== Affichage de la liste ==========\n");

    //Tant que nous nous ne sommes pas arrivés à la fin de la liste
    while(pos != NULL){
        p = pos->pt; //On se prépare à afficher le point de cette cellule

        printf("(%d,%d)\n", p.x, p.y); //On l'affiche de cette façon (<x>,<y>)

        //On passe à la cellule suivante
        prochaine_pos = pos->suivante;
        pos = prochaine_pos;
    }

    //A la fin, on saute deux lignes histoire de bien séparer le reste
    printf("\n\n");
}