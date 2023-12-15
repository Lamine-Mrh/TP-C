#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"
#include "binary_tree.h"
#include "stack_link.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <n>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int n = atoi(argv[1]);
    if (n <= 0) {
        printf("Please provide a positive integer.\n");
        return EXIT_FAILURE;
    }

    srand(time(NULL));

    // Initialisation du tableau avec des entiers aléatoires entre 0 et 9
    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < n; i++) {
        array[i] = rand() % 10; // Valeurs entre 0 et 9
    }

    // Construction de l'ABR en insérant les valeurs du tableau
    link root = empty_tree();
    for (int i = 0; i < n; i++) {
        root = insert_BST(root, array[i]);
    }

    // Affichage de l'ABR construit
    printf("Arbre binaire de recherche construit :\n");
    show_binary_tree(root, 0);
    printf("\n");

    // Affichage des étiquettes de l'ABR dans l'ordre croissant
    printf("Etiquettes de l'ABR dans l'ordre croissant :\n");
    traverse_inorder_binary_tree(root, print_label);
    printf("\n");

    // Suppression de la valeur de rang n/2
    int index_to_remove = n / 2;
    if (index_to_remove >= 0 && index_to_remove < n) {
        int value_to_remove = array[index_to_remove];
        root = delete_node_BST(root, value_to_remove);

        printf("ABR apres suppression de la valeur de rang %d :\n", index_to_remove);
        show_binary_tree(root, 0);
        printf("\n");
    } else {
        printf("Index to remove is out of bounds.\n");
    }

    // Libération de la mémoire allouée
    free(array);
    delete_binary_tree(&root);

    return EXIT_SUCCESS;
}
