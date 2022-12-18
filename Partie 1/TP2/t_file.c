/*******************************************************
Nom ......... : t_file.c
Role ........ : Définition des fonctions prototypées dans le header t_file
Auteur ...... : Youcef MEDILEH (N°Etu: 22004750)
Version ..... : V2 du 30/10/22
********************************************************/

#include <stdlib.h> //Malloc
#include <stdio.h>
#include "t_file.h"

//Voir la documentation des fonctions dans le fichier pour .h
void enfiler(t_file *file, int aEnfiler){
	//Création et initialisation de l'espace mémoire de l'élément que nous allons enfiler
    chose *ce_quon_va_enfiler = malloc(sizeof(chose));

    if (file == NULL || ce_quon_va_enfiler == NULL){
        printf("La file est vide ou échec de l'allocation mémoire !");
        exit(1);
    }

	//On crée l'élément en lui donnant ce qu'il doit enfiler (Le sommet "aEnfiler")
    ce_quon_va_enfiler->chose = aEnfiler;
    ce_quon_va_enfiler->suivant = NULL;

	//Si la file n'est pas vide
    if (file->premierDeLaFile != NULL){ 
        //On commence au début de la file (La fin en réalité)
        chose *position = file->premierDeLaFile;

        //Tant que nous ne sommes pas arrivés à la fin de la file
        while (position->suivant != NULL){
            position = position->suivant; //On parcourt
        }

        //Une fois que nous sommes arrivés à la fin de la file, on l'insère
        position->suivant = ce_quon_va_enfiler;
    }
    else{ //Si la file est vide, on l'insère dès le début.
        file->premierDeLaFile = ce_quon_va_enfiler;
    }
}

int defiler(t_file *file){
    if (file == NULL){
        printf("La file est inexistante !");
        exit(1);
    }
    int valeur;
    // On vérifie s'il y a quelque chose à défiler
    if (file->premierDeLaFile != NULL){
        chose *quelquechose = file->premierDeLaFile;
        valeur = quelquechose->chose;
        file->premierDeLaFile = quelquechose->suivant;
        free(quelquechose);
    }
    return valeur;
}

void afficher(t_file *file){
    //Si la file est "inexistante"
    if (file == NULL){
        printf("La file est à NULL!");
        exit(1);
    }

    //On commence par le premier de la file
    chose *qqch = file->premierDeLaFile;

    //S'il y a quelque chose à afficher
    while (qqch != NULL){
        printf("%d ", qqch->chose);
        qqch = qqch->suivant; //On passe au suivant
    }

    //Histoire de bien séparer
    printf("\n");
}

t_file *initialiser(){
	//Création et initialisation de l'espace mémoire de la file
    t_file *f = malloc(sizeof(t_file));

    if(f == NULL){
        printf("L'allocation mémoire pour la file a échoué !");
        exit(1);
    }

    //Initialisation du premier de la file à NULL
    f->premierDeLaFile = NULL;

    return f;
}

void testFile(){
    t_file *f = initialiser();

    //On enfile
    enfiler(f,1);
    enfiler(f,2);
    enfiler(f,3);

    //On regarde si 1,2,3 ont bien étés "enfilées"
    afficher(f);
    defiler(f); //On défile (FIFO, le 1 qui a été le premier devrait être défilé)

    //On vérifie bien si 1, le premier qui a été enfilé a été défilé
    afficher(f);

    enfiler(f, 4);
    afficher(f);

    defiler(f);
    afficher(f);
}