#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_tree.h" 



link parse_expr(const char *expr);
int eval_tree(link t);
void tree_to_expr(link t, char *prefix_expr, int *index);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <expression_arithmetique>\n", argv[0]);
        return 1;
    }

    const char *expr = argv[1];

    // Construire l'arbre syntaxique
    link t = parse_expr(expr);

    // Afficher l'arbre syntaxique
    printf("Arbre syntaxique de l'expression arithmetique prefixe :\n");
    show_binary_tree(t, 0);

    // Évaluer l'expression et afficher le résultat
    int result = eval_tree(t);
    printf("\nResultat de l'evaluation de l'expression : %d\n", result);

    // Récupérer l'expression préfixe correspondante à l'arbre syntaxique
    char prefix_expr[100]; // Assurez-vous d'allouer suffisamment d'espace
    int index = 0;
    tree_to_expr(t, prefix_expr, &index);
    prefix_expr[index] = '\0'; // Terminer la chaîne avec un caractère nul

    // Vérifier si l'expression préfixe est égale à l'expression initiale
    if (strcmp(expr, prefix_expr) == 0) {
        printf("\nLes expressions prefixes sont identiques : %s\n", prefix_expr);
    } else {
        printf("\nLes expressions prefixes ne sont pas identiques.\n");
    }

    // Libérer la mémoire allouée pour l'arbre syntaxique
    delete_binary_tree(&t);

    return 0;
}