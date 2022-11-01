/*******************************************************
Nom ......... : arbre.c
Role ........ : FIchier définissant les fonctions de ce TP
Auteur ...... : Youcef MEDILEH (N°Etu: 22004750)
Version ..... : V2 du 31/10/22
********************************************************/
#include <stdio.h> //Pour NULL
#include <assert.h> //Pour assert()
#include <stdlib.h> //Pour malloc() et free()

#include "arbre.h"

//Compteur nombre de noeuds crées pour les numéroter automatiquement
int NB_NOEUDS = 0;

// ===================== DEFINITION DES FONCTIONS =======================
//La documentation de ces fonctions sont présentes dans le fichier arbre.h

noeud nouvNoeud(char carac){
    //Allocation de l'espace pour le noeud
	noeud *pnewNoeud = NULL;
	pnewNoeud = (noeud *) malloc(sizeof(noeud));

	//Malloc réussi
	if(pnewNoeud != NULL){
        //On assigne le nouvel espace crée pour le nouveau noeud
        noeud newNoeud; //Nouveau noeud;
        pnewNoeud = &newNoeud; //Le pointeur vers celui-ci

		if(NB_NOEUDS==0) newNoeud.pere = NULL; //Si c'est le premier noeud, il n'a évidemment pas de père (C'est la racine)

		newNoeud.num = ++NB_NOEUDS; //Incrémentation du numéro du noeud
		newNoeud.valeur = carac; //On met la valeur demandée

		//Initialisation de ses enfants à NULL
		newNoeud.filsGauche = NULL;
		newNoeud.filsDroit = NULL;

		return newNoeud;
	}else{
		printf("Erreur fatale: Malloc échoué\n");
		exit(0);
	}
}

noeud *rechercheNoeud(noeud *racine, int num_noeud){
    //Si le deuxième paramètre est incorrect (Négatif ou supérieur au nombres de noeuds crées)
    if(num_noeud>NB_NOEUDS || num_noeud < 1){
        printf("Numero du noeud a rechercher incorrect!");
        return NULL;
    }

    noeud *tmpNoeud = NULL;

    if(racine == NULL) //Si le noeud est null.... (Erreur de programmation lors de l'appel de la fonction dans le main)
        return NULL;
    if(racine->num == num_noeud) //Si on est arrivé au noeud que l'on recherchait
        return racine;

    tmpNoeud = rechercheNoeud(racine->filsGauche, num_noeud);

    if(tmpNoeud != NULL)
        return(tmpNoeud);

    return(rechercheNoeud(tmpNoeud->filsDroit, num_noeud));
}

void insererFG(noeud n, noeud *racine, int num_noeud_pere){
    noeud *pere = rechercheNoeud(racine, num_noeud_pere); //On récupère le père

    if(pere == NULL){ //Si le numéro entré en paramètre est incorrect
        printf("Père inexistant !");
        return; //On quitte la fonction, cela ne sert à rien d'aller plus loin
    }else if(pere->filsGauche != NULL){ //S'il a déjà un fils gauche, on l'insère en tant que fils gauche du fils gauche
        insererFG(n, racine, pere->filsGauche->num);
    }else{ //S'il n'a pas de fils gauche....
        pere->filsGauche = &n; //...On l'insère !
        pere->filsGauche->pere = pere; //On lui affecte son père (Noeud "au dessus")
    }
}

void insererFD(noeud n, noeud *racine, int num_noeud_pere){
    noeud *pere = rechercheNoeud(racine, num_noeud_pere); //On récupère le père

    if(pere == NULL){ //Si le numéro entré en paramètre est incorrect
        printf("Père inexistant !");
        return; //On quitte la fonction, cela ne sert à rien d'aller plus loin
    }else if(pere->filsDroit != NULL){ //S'il a déjà un fils gauche, on l'insère en tant que fils gauche du fils gauche
        insererFD(n, racine, pere->filsDroit->num);
    }else{ //S'il n'a pas de fils gauche....
        pere->filsDroit = &n; //...On l'insère !
        pere->filsDroit->pere = pere; //Et on lui affecte bien son père
    }
}

void parcoursPrefixe(noeud *racine){
    if(racine != NULL){
        printf("noeud numero: %d || Valeur: %c\n", racine->num, racine->valeur);
        parcoursPrefixe(racine->filsGauche);
        parcoursPrefixe(racine->filsDroit);
    }
}


void parcoursInfixe(noeud *racine){
    assert(racine != NULL); //Si l'arbre n'est pas vide, on peut continuer

    //S'il s'agit du premier affichage
    if(racine->valeur == 1)
        printf("=== Affichage de l'arbre ===\n"); //Histoire d'esthétisme

    //Si le noeud a un fils gauche
    if(racine->filsGauche){
        parcoursInfixe(racine->filsGauche);
    }

    //On affiche chaque noeud sous la forme "Noeud numéro: <Num> || Valeur: <Val>
    printf("noeud numero: %d || Valeur: %c\n", racine->num, racine->valeur);

    //...s'il a un fils droit

    if(racine->filsDroit){
        parcoursInfixe(racine->filsDroit);
    }

}

void parcoursPostfixe(noeud *racine){
    assert(racine != NULL); //Si l'arbre n'est pas vide, on peut continuer

    //S'il s'agit du premier affichage
    if(racine->valeur == 1)
        printf("=== Affichage de l'arbre ===\n"); //Histoire d'esthétisme

    //Si le noeud a un fils gauche
    if(racine->filsGauche){
        parcoursPostfixe(racine->filsGauche);
    }

    //...s'il a un fils droit
    if(racine->filsDroit){
        parcoursPostfixe(racine->filsDroit);
    }

    //On affiche chaque noeud sous la forme "Noeud numéro: <Num> || Valeur: <Val>
    printf("noeud numero: %d || Valeur: %c\n", racine->num, racine->valeur);

}