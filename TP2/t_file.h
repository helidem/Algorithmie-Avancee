/*******************************************************
Nom ......... : t_file.h
Role ........ : Prototypes des fonctions pour manipuler une file ainsi que la définition du type
Auteur ...... : Youcef MEDILEH (N°Etu: 22004750)
Version ..... : V2 du 30/10/22
********************************************************/

//Afin d'éviter une boucle infinie "d'inclusion"
#ifndef T_FILE_H_INCLUDED
#define T_FILE_H_INCLUDED

//Une élément de la file
typedef struct chose chose;
struct chose
{
    int chose; //L'élement, ici un int puisque la file va contenir des sommets
    chose *suivant; //Le prochain élément de la file
};

//La file
typedef struct t_file t_file;
struct t_file
{
    chose *premierDeLaFile; //Le premier de la file
};

/* Résumé: Enfile un élément dans la liste
 * Paramètre file: La file où l'on va insérer l'élément
 * Paramètre aEnfiler: L'élément a enfiler (Dans ce cas ici un sommet de type int)
 * Paramètre s: Numéro du sommet de référence
 */
void enfiler(t_file *file, int aEnfiler);

/* Résumé: Défile le premier élément de la file
 * Paramètre file: La file où l'on va défiler le premier élément
 */
int defiler(t_file *file);

/* Résumé: Affiche le contenu de la file
 * Paramètre file: La file que nous allons afficher 
 */
void afficher(t_file *file);

/* Résumé: Initialise une file
 * Retour: Retourne un pointeur sur une file bien initialisée
 */
t_file *initialiser();

/* Résumé: Teste les fonctions de la t_file, voir si le type marche correctement
 */
void testFile();

#endif // T_FILE_H_INCLUDED
