#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"
#include "binary_tree.h"
#include "stack_link.h"


#define ALPHABET_SIZE 26 // Taille de l'alphabet latin

// Fonction pour générer une lettre aléatoire en majuscule
char generate_random_letter() {
    return 'A' + rand() % ALPHABET_SIZE;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <n> <m>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    srand(time(NULL));

    link tree_n = empty_tree();
    link tree_m = empty_tree();

    // Génération des deux chaînes de caractères
    printf("Chaine de longueur %d: ", n);
    for (int i = 0; i < n; i++) {
        char letter = generate_random_letter();
        printf("%c ", letter);
        tree_n = insert_BST(tree_n, letter);
    }
    printf("\n");

    printf("Chaine de longueur %d: ", m);
    for (int i = 0; i < m; i++) {
        char letter = generate_random_letter();
        printf("%c ", letter);
        tree_m = insert_BST(tree_m, letter);
    }
    printf("\n");

    // Suppression de la valeur de rang floor(n/2) de l'ABR de taille n
    int rank_to_delete = n / 2;
    if (rank_to_delete >= 0 && rank_to_delete < n) {
        char value_to_delete = select_BST(tree_n, rank_to_delete)->label;
        tree_n = delete_node_BST(tree_n, value_to_delete);
    } else {
        printf("Invalid rank to delete.\n");
    }

    // Fusion des deux ABR
    link merged_tree = join_BST(tree_n, tree_m);

    // Affichage des étiquettes de l'ABR fusionné dans l'ordre alphabétique
    printf("Etiquettes de l'ABR fusionne en ordre alphabetique:\n");
    traverse_inorder_binary_tree(merged_tree, print_label);
    printf("\n");

    // Rééquilibrage de l'ABR fusionné
    merged_tree = balance_BST(merged_tree);

    // Libération de la mémoire
    delete_binary_tree(&tree_n);
    delete_binary_tree(&tree_m);
    delete_binary_tree(&merged_tree);

    return EXIT_SUCCESS;
}
