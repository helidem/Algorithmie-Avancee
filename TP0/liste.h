/*******************************************************
Nom ......... : liste.h
Role ........ : Fichier définissant les types point et cellule et
                contient les prototypes des foncions pour ce TP
Auteur ...... : Youcef MEDILEH (N°Etu: 22004750)
Version ..... : V2 du 31/10/22
********************************************************/

#ifndef LISTE_H_INCLUDED
#define LISTE_H_INCLUDED

// ===================== DEFINITION DES TYPES POINT ET CELLULE =======================
typedef struct point{
	int x; //Coordonnées
	int y;
} point;

typedef struct cellule{
	struct point pt; //point

	struct cellule *avant; //cellule précédente
	struct cellule *suivante; //cellule suivante
} cellule;

// ===================== PROTOTYPE DES FONCTIONS =======================
/* Résumé: Fonction permettant de créer une nouvelle cellule
 * Retour: Un pointeur sur la nouvelle cellule crée
 * Paramètre p: Un point, qui sera dans cette nouvelle cellule
 */
cellule *NouvCel(point p);

/* Résumé: Fonction servant à insérer une cellule dans la liste
 * Paramètre pl: A quelle place l'insérer
 * Paramètre cel: Pointeur sur la cellule que l'on veut placer
 * Paramètre liste: Pointeur sur la cellule qui représente la liste (La première)
 */
void Inserercellule(int pl, cellule *cel, cellule *liste);

/* Résumé: Fonction servant à supprimer une cellule de la liste
 * Paramètre pl: A quelle place l'insérer
 * Paramètre liste: Pointeur sur la cellule qui représente la liste (La première)
 */
void SupprimerCellule(int pl, cellule *liste);

/* Résumé: Fonction servant à afficher le contenu d'une liste
 * Paramètre liste: Pointeur sur la cellule qui représente la liste (La première)
 */
void Afficher(cellule *liste);

#endif // LISTE_H_INCLUDED