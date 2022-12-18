/*************************************************************
Nom ........... : t_arete.h
Role .......... : Prototypes des fonctions pour manipuler une arête ainsi que la définition du type
Auteur ........ : Jordan LAIRES (N°Etu: 51802252)
Version ....... : V1 du 4/11/20
*************************************************************/

//Afin d'éviter une boucle infinie "d'inclusion"
#ifndef T_ARETE_H_INCLUDED
#define T_ARETE_H_INCLUDED

#include <stdbool.h>

//Le type arête
typedef struct t_arete t_arete;
struct t_arete{
    int x;
    int y;
    float poids; //Valeur de l'arête
};

/* Applique l'algorithme de Kruskal
 * Paramètre arbre: L'arbre sur lequel on va appliquer l'algorithme
 * Paramètre ordre: Ordre de l'arbre (Nombre de sommets)
 * Paramètre s: Le sommet de référence pour appliquer l'algorithme
 * Paramètre n: Nombre d'arêtes du graphe
 *
 * COMME UNE FONCTION NE PEUT RETOURNER UN TABLEAU, LA FONCTION NE RETOURNE PAS L'ARBRE COUVRANT MINIMAL MAIS VA AFFICHER L'ARBRE
 */
void kruskal(t_arete arbre[], int ordre, int s, int n);

/* Fonction qui trouve l'arbre courant de poids minimum mais au contraire de la fonction kruskal, l'arbre est sous forme de matrice d'adjacence.
 * Paramètre adjacencePoids: L'arbre sous la forme d'une matrice d'adjacence sur lequel on va appliquer l'algorithme "prim"
 * Paramètre ordre: Ordre de l'arbre (Nombre de sommets)
 *
 * COMME UNE FONCTION NE PEUT RETOURNER UN TABLEAU, LA FONCTION NE RETOURNE PAS L'ARBRE COUVRANT MINIMAL MAIS VA AFFICHER L'ARBRE.
 */
void prim (float adjacencePoids[5][5], int ordre);

/* Renvoie si oui ou non, un arbre est trié par ordre croissant en fonction des valeurs de ses arêtes
 * Paramètre arbre: L'arbre pour lequel on va vérifier s'il est trié ou non
 * Paramètre n: Nombre d'arêtes
 * Retour: La réponse sous forme d'expression booléenne (vrai ou faux)
 */
_Bool arbreTrie(t_arete arbre[], int n);

#endif // T_ARETE_H_INCLUDED