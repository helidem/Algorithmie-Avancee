/*******************************************************
Nom ......... : arbre.h
Role ........ : Fichier définissant le type noeud et
                contient les prototypes des fonctions de ce TP
Auteur ...... : Youcef MEDILEH (N°Etu: 22004750)
Version ..... : V2 du 31/10/22
********************************************************/

#ifndef ARBRE_H_INCLUDED //Afin d'éviter une "boucle infinie d'inclusion"
#define ARBRE_H_INCLUDED

// ===================== DEFINITION DU TYPE NOEUD =======================
//Un noeud
typedef struct noeud{
	char valeur; //Coordonnées
	int num; //Numéro de création
	struct noeud *filsGauche;
	struct noeud *filsDroit;
	struct noeud *pere; //Le père du noeud (Pour pouvoir remonter dans la fonction parcoursPrefixe)
} noeud;

// ===================== PROTOTYPES DES FONCTIONS =======================

/* Résumé: Fonction créant un nouveau noeud
 * Retourne: Le noeud crée
 * Paramètre carac: La valeur que contiendra le nouveau noeud
 */
noeud nouvNoeud(char carac);

/* Résumé: Fonction recherchant un noeud avec le numéro entré en paramètre
 * Retourne: Le noeud trouvé correspondant à ce que recherchait la fonction
 * Paramètre racine: L'arbre, le premier noeud, la racine
 * Paramètre num_noeud: Le numéro du noeud recherché
 */
noeud *rechercheNoeud(noeud *racine, int num_noeud);

/* Résumé: Fonction ajoutant un noeud en tant que fils gauche du noeud entré en paramètre
 * Paramètre n: Le noeud que l'on va insérer
 * Paramètre racine: L'arbre, le premier noeud, la racine
 * Paramètre num_noeud_pere: Le numéro du noeud du père pour lequel on va insérer un nouveau fils gauche
 */
void insererFG(noeud n, noeud *racine, int num_noeud_pere);


/* Résumé: Fonction ajoutant un noeud en tant que fils droit du noeud entré en paramètre
 * Paramètre n: Le noeud que l'on va insérer
 * Paramètre racine: L'arbre, le premier noeud, la racine
 * Paramètre num_noeud_pere: Le numéro du noeud du père pour lequel on va insérer un nouveau fils droit
*/
void insererFD(noeud n, noeud *racine, int num_noeud_pere);

/* Résumé: Fonction affichant l'arbre en faisant un parcours préfixe
 * Paramètre racine: L'arbre
 */
void parcoursPrefixe(noeud *racine);


/* Résumé: Fonction affichant l'arbre en faisant un parcours infixe
 * Paramètre racine: L'arbre
 */
void parcoursInfixe(noeud *racine);


/* Résumé: Fonction affichant l'arbre en faisant un parcours postfixe
 * Paramètre racine: L'arbre
 */
void parcoursPostfixe(noeud *racine);


#endif // ARBRE_H_INCLUDED