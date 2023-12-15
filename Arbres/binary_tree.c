#include "binary_tree.h"
#include "queue_link.h"
#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include <ctype.h>
#include <string.h>

//TD/TP3


/** Returns the left subtree of a tree */
/* (N.B. Requires that the tree be non-empty) */
link left(const link pt) {
  return pt->left;
}

/** Returns the right subtree of a tree */
link right(const link pt) {
    return pt->right;
}

/** Prints the label of a node with the appropriate shift */
void print_node_shift(item s, int shift) {
  int i;
  for (i = 0; i < shift; i++) printf("  ");
  display(s);
}
/** Prints a tree (rotated by -\pi/2) */
void show_binary_tree(const link tree, int shift) {
  if (NULL == tree) return;
  show_binary_tree(tree->right, shift + 1);
  print_node_shift(get_binary_tree_root(tree), shift);
  show_binary_tree(tree->left, shift + 1);
}

int size_binary_tree(link root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + size_binary_tree(root->left) + size_binary_tree(root->right);
    }
}

int height_binary_tree(link root) {
    if (root == NULL) {
        return -1;
    } else {
        int left_height = height_binary_tree(root->left);
        int right_height = height_binary_tree(root->right);
        return 1 + (left_height > right_height ? left_height : right_height);
    }
}

item max_binary_tree(link root) {
    if (root == NULL) {
        return -1; 
    } else if (root->left == NULL && root->right == NULL) {
        return root->label; 
    } else {
        item left_max = max_binary_tree(root->left);
        item right_max = max_binary_tree(root->right);
        item max_child = (less(left_max, right_max)) ? right_max : left_max;
        return (less(root->label, max_child)) ? max_child : root->label;
    }
}

int count_leaves_binary_tree(link root) {
    if (root == NULL) {
        return 0;
    } else if (root->left == NULL && root->right == NULL) {
        return 1;
    } else {
        return count_leaves_binary_tree(root->left) + count_leaves_binary_tree(root->right);
    }
}

/** Returns the label of the root of a tree */
item get_binary_tree_root(const link pt) {
    return pt->label;
}

/** Tests a tree for emptiness */
int is_empty_binary_tree(const link pt) {
    return (pt == NULL);
}

/** Displays information attached to the root */
void print_label(const link pt) {
    display(get_binary_tree_root(pt));
}

/** Traverses recursively a tree according to inorder */
void traverse_inorder_binary_tree(link pt, void (*visit)(link)) {
    if (pt != NULL) {
        traverse_inorder_binary_tree(pt->left, visit);
        visit(pt);
        traverse_inorder_binary_tree(pt->right, visit);
    }
}

/** Traverses recursively a tree according to preorder */
void traverse_preorder_binary_tree(link pt, void (*visit)(link)) {
    if (pt != NULL) {
        visit(pt);
        traverse_preorder_binary_tree(pt->left, visit);
        traverse_preorder_binary_tree(pt->right, visit);
    }
}

/** Traverses recursively a tree according to postorder */
void traverse_postorder_binary_tree(link pt, void (*visit)(link)) {
    if (pt != NULL) {
        traverse_postorder_binary_tree(pt->left, visit);
        traverse_postorder_binary_tree(pt->right, visit);
        visit(pt);
    }
}

/** Traverses iteratively a tree according to level-order (using a queue) */
void traverse_level_binary_tree(link pt, void (*visit)(link)) {
    if (pt == NULL) {
        return;
    }
    
    struct queue *q = init_queue();
    enqueue(q, pt);
    
    while (!is_empty_queue(q)) {
        link current = dequeue(q);
        visit(current);
        
        if (left(current) != NULL) {
            enqueue(q, left(current));
        }
        if (right(current) != NULL) {
            enqueue(q, right(current));
        }
    }
    
    delete_queue(&q);
}

link cons_binary_tree(item label, const link left, const link right) {
    link new_tree = (link)malloc(sizeof(struct binary_tree));
    if (new_tree == NULL) {
        fprintf(stderr, "Memory allocation failed for binary tree node\n");
        return NULL;
    }

    new_tree->label = label;
    new_tree->left = left;
    new_tree->right = right;

    return new_tree;
}

void delete_binary_tree(link *root) {
    if (*root == NULL) {
        return; 
    }
    
    delete_binary_tree(&((*root)->left)); 
    delete_binary_tree(&((*root)->right)); 

    free(*root); 
    *root = NULL; 
}

//TD/TP4

link parse_expr(const char *expr) {
    if (expr == NULL || *expr == '\0') {
        return NULL;
    }

    char operator;
    int value;

    int num_scanned = sscanf(expr, " %c", &operator);

    if (num_scanned == 1 && (operator == '+' || operator == '*')) {
        sscanf(expr + 2, "%d", &value);
        return cons_binary_tree(operator, cons_binary_tree(value, NULL, NULL), cons_binary_tree(value, NULL, NULL));
    } else {
        int left_offset = 0;
        while (expr[left_offset] != ' ' && expr[left_offset] != '\0') {
            left_offset++;
        }
        return cons_binary_tree(operator, parse_expr(expr + left_offset + 1), parse_expr(expr + left_offset + 1));
    }
}



int eval_tree(link t) {
    if (t == NULL) {
        return 0;
    }

    int left_val = eval_tree(left(t));
    int right_val = eval_tree(right(t));

    char op = get_binary_tree_root(t);

    if (op == '+') {
        return left_val + right_val;
    } else if (op == '*') {
        return left_val * right_val;
    }

    return get_binary_tree_root(t); 
}


void tree_to_expr(const link tree, char *result, int *index) {
    if (is_empty_binary_tree(tree)) {
        return;
    }

    result[*index] = get_binary_tree_root(tree);
    (*index)++;

    tree_to_expr(left(tree), result, index);
    tree_to_expr(right(tree), result, index);
}

int is_operator(char c) {
    return (c == '+' || c == '*');
}

int evaluate(int operand1, int operand2, char op) {
    if (op == '+') {
        return operand1 + operand2;
    } else if (op == '*') {
        return operand1 * operand2;
    }
    return 0;
}

int eval_expr(const char *expr) {
    if (expr == NULL || *expr == '\0') {
        return 0;
    }

    struct queue *operand_queue = init_queue();

    int i = 0;
    while (expr[i] != '\0') {
        if (isdigit(expr[i])) {
            int num = 0;
            while (isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            link new_node = cons_binary_tree(num, NULL, NULL); // Create a tree node for the integer
            enqueue(operand_queue, new_node); // Enqueue the integer node
        } else if (is_operator(expr[i])) {
            char op = expr[i];
            i++;

            link operand1 = dequeue(operand_queue);
            link operand2 = dequeue(operand_queue);

            if (operand1 == NULL || operand2 == NULL) {
                printf("Invalid expression\n");
                return -1;
            }

            int result = evaluate(get_binary_tree_root(operand1), get_binary_tree_root(operand2), op);
            link new_node = cons_binary_tree(result, operand1, operand2); 
            enqueue(operand_queue, new_node); 
        } else {
            i++; 
        }
    }

    link final_result_node = dequeue(operand_queue); 
    int final_result = get_binary_tree_root(final_result_node);

    delete_binary_tree(&final_result_node);
    delete_queue(&operand_queue);

    return final_result;
}



