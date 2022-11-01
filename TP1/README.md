# Code TP1
Ce dossier contient le code du TP1. Il est composé de 1 fichier :
* `graphe.c` : Ce fichier contient l'implémentation de la structure de données graphe.

Pour compiler ce code, il suffit de taper la commande suivante dans le terminal :
Sur linux : `gcc -o graphe graphe.c`
Sur windows : `gcc -o graphe.exe graphe.c`

Pour exécuter ce code, il suffit de taper la commande suivante dans le terminal :
Sur linux : `./graphe < in.txt`
Sur windows : `graphe.exe < in.txt`

Pour le `in.txt`, il est composé de cette manière :
* le premier nombre est le nombre de sommets du graphe
* les autres nombres (ordre*ordre) sont les valeurs de la matrice d'adjacence du graphe. Les nombres sont séparés par des espaces.
