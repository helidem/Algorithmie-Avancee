/**
 * @author Youcef MEDILEH
 * @file graphe.c
 * @date 2022-10-31
 * @brief Ce fichier contient l'implémentation de la structure de données graphe.
 * @version 2.0
 */

#include <stdio.h>
#include <stdlib.h>


/**
 * @brief Parcours en profondeur d'un graphe
 * @param adjacence Matrice d'adjacence du graphe
 * @param ordre Nombre de sommets
 * @param s Numero du sommet de reference
 */
void marquerVoisins(int** adjacence, int ordre, int s) {
    // Variables locales
    int* marques; // tableau dynamique indiquant si les sommets sont marques ou non
    int x, y; // numeros de sommets intermediaires
    // Allouer le tableau marques de taille « ordre »
    marques = (int*)malloc(ordre * sizeof(int));

    // Initialiser les marquages a 0
    for (x = 0; x < ordre; x++)
        marques[x] = 0;
    // Marquer le sommet s a 1
    marques[s] = 1;
    // Pour tous les sommets x marques
    // Marquer les sommets non marques y adjacents a x
    for (x = 0; x < ordre; x++)
        if (marques[x])
            for (y = 0; y < ordre; y++)
                if (adjacence[x][y] && !marques[y])
                    marques[y] = 1;

    //Comme on ne peut pas retourner de tableau (Par exemple retourner le tableau "marques")
    //Au lieu de créer une fonction qui affiche les sommets marqués, je le fais à la fin de la fonction.
    //Vérification si tous les sommets sont marqués
    for(int sommets = 0; sommets<ordre; sommets++){
        printf("Sommet %d: Marque:%d\n", sommets+1, marques[sommets]);
    }
}

/**
 * @brief Charge la matrice d'adjacence d'un graphe depuis le stdin
 * @param adjacence Matrice d'adjacence du graphe
 * @param ordre Nombre de sommets
 */
void chargeGraphe(int** adjacence, int ordre) {
    // Variables locales
    int x, y; // numeros de sommets intermediaires
    // Pour tous les sommets x
    for (x = 0; x < ordre; x++)
        // Pour tous les sommets y
        for (y = 0; y < ordre; y++)
            // Lire la valeur de l'arc (x, y)
            scanf_s("%d", &adjacence[x][y]);
}

/**
 * @brief Fonction qui affiche le chemin de visite (ou chemin parcouru)
 * @param adjacence Matrice d'adjacence du graphe
 * @param sommet Numero du sommet de reference
 * @param ordre Nombre de sommets
 */
void afficheCheminVisite(int** adjacence, int sommet, int ordre) {
    // Variables locales
    int i, j;
    // Affichage du chemin de visite sans retour (ou symetrie)
    printf("Chemin de visite : ");
    for (i = 0; i < ordre; i++) {
        for (j = i+1; j < ordre; j++) {
            if (adjacence[i][j] == 1 && i == sommet) {
                printf("%d -> %d ", i, j);
                break;
            } // if
        } // j
        sommet++;
    } // i
    printf("\n");
}

int main(int argc, char* argv[]) {
    // Variables locales
    int ordre; // ordre du graphe
    int** adjacence; // matrice d'adjacence du graphe
    int x, y; // numeros de sommets intermediaires
    // Lire l'ordre du graphe
    scanf_s("%d", &ordre);
    // Allouer la matrice d'adjacence
    adjacence = (int**)malloc(ordre * sizeof(int*));
    for (x = 0; x < ordre; x++)
        adjacence[x] = (int*)malloc(ordre * sizeof(int));
    // Charger la matrice d'adjacence
    chargeGraphe(adjacence, ordre);

    // afficher la matrice d'adjacence
    for (x = 0; x < ordre; x++) {
        for (y = 0; y < ordre; y++) {
            printf("%d ", adjacence[x][y]);
        }
        printf("\n");
    }

     // Parcourir le graphe a partir de chaque sommet
    for(int sommetReference; sommetReference<6; sommetReference++){
        printf("Pour %d comme sommet de reference:\n", sommetReference);
        marquerVoisins(adjacence, ordre, sommetReference);
        printf("\n");
        // afficher le chemin de visite
        afficheCheminVisite(adjacence, sommetReference, ordre);
    }  
    
     // Liberer la matrice d'adjacence
    for (x = 0; x < ordre; x++)
        free(adjacence[x]);
    free(adjacence);
    return 0;
}