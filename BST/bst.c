#include <stdlib.h>
#include <stdio.h>
#include "bst.h"
#include "stack_link.h"
#include "binary_tree.h"

/** Searches a BST for a label and returns a pointer to a node with this label */
/* Returns NULL if there is no node with this label */
link search_BST(link h, item v) {
  if (h == NULL) return NULL;
  item t = get_binary_tree_root(h);
  if eq(v, t) return h;
  if less(v, t) return search_BST(h->left, v);
    else return search_BST(h->right, v);
  }

/** Inserts a node with a given label in a BST */
/* and returns a link to the updated BST */
link insert_BST(link h, item v) {
  if (h == NULL) return cons_binary_tree(v, NULL, NULL);
  if less(v, get_binary_tree_root(h)) {
    h->left = insert_BST(h->left, v);
  }
  else {
    h->right = insert_BST(h->right, v);
  }
  return h;
}

/********************************************************************/
/***           TD n°5 (Exercice 1, questions b and c)             ***/
/********************************************************************/
/** Prints all values of array a in decreasing order of priority */
/** Complexity: if the array is already sorted, the insertion procedure */
/* requires 1 + 2 + ... + (n-1) comparisons of labels */
/* The total cost is O(n^2) as the traversal is O(n) */
void print_sorted_BST(item *a, int n) {
  link root = NULL;
    int i;
    for (i = 0; i < n; i++) {
        root = insert_BST(root, a[i]); // Construct BST from the array
    }
    
    while (!is_empty_binary_tree(root)) {
        link max = select_BST(root, size_binary_tree(root) - 1); // Get max element
        printf("%d ", get_binary_tree_root(max)); // Print max element
        root = delete_node_BST(root, get_binary_tree_root(max)); // Delete max element
    }
}

/** Selects the kth label of a BST */
/* and returns a pointer to the corresponding node */
/* Returns NULL if the BST does not contain k labels */
link select_BST(link h, int k) {
  int t = size_binary_tree(h->left);
  if (h == NULL) return NULL;
  if (t > k) return select_BST(h->left, k);
  if (t < k) return select_BST(h->right, k-t-1);
  return h;
}

/*************     ROTATIONS        *************/

/** Applies a right rotation the root of a BST */
link rotate_right(link h) {
  link x;
  if (NULL == h) return NULL;
  x = h->left;
  h->left = x->right;
  x->right = h;
  return x;
}

/** Applies a left rotation to the root of a BST */
link rotate_left(link h) {
  link x;
  if (NULL == h) return NULL;
  x = h->right;
  h->right = x->left;
  x->left = h;
  return x;
}

/** Inserts a node with a given label at the root of BST */
/* and returns the updated BST */
link insert_BST_root(link h, item v) {
  if (h == NULL) return cons_binary_tree(v, NULL, NULL);
  if (less(v, get_binary_tree_root(h))) {
    h->left = insert_BST_root(h->left, v);
    h = rotate_right(h);
  }
  else {
    h->right = insert_BST_root(h->right, v);
    h = rotate_left(h);
  }
  return h;
}

/** Partitions a BST with respect to the node of rank k */
/* and returns the updated BST */
link partition_BST(link h, int k) {
  int t = size_binary_tree(h->left);
  if (is_empty_binary_tree(h)) return h;
  if (t > k) {
    h->left = partition_BST(h->left, k);
    h = rotate_right(h);
  }
  if (t < k) {
    h->right = partition_BST(h->right, k-t-1);
    h = rotate_left(h);
  }
  return h;
}

/*****************************************************/
/***               TD n°5  Exercice 3              ***/
/*****************************************************/
/** Deletes the first node of label v in a BST */
/* and returns the updated BST */
link delete_node_BST(link h, item v) {
  if (h == NULL) return h;
    
    if (less(v, get_binary_tree_root(h))) {
        h->left = delete_node_BST(h->left, v);
    } else if (less(get_binary_tree_root(h), v)) {
        h->right = delete_node_BST(h->right, v);
    } else {
        if (h->left == NULL) {
            link temp = h->right;
            free(h);
            return temp;
        } else if (h->right == NULL) {
            link temp = h->left;
            free(h);
            return temp;
        }
        link temp = h->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        h->label = get_binary_tree_root(temp);
        h->right = delete_node_BST(h->right, get_binary_tree_root(temp));
    }
    return h;
}

/*****************************************************/
/***            TP n°5 question d                  ***/
/*****************************************************/
/** Puts a BST into perfect balance, by recursively */
/* putting the median node at the root */
link balance_BST(link h) {
    if (h == NULL) return NULL;

    int size = size_binary_tree(h);
    item *sortedArray = (item *)malloc(size * sizeof(item));
    int index = 0;

    // Store BST values in sorted array using an inorder traversal
    if (h != NULL) {
        struct stack *stack = init_stack(size); // Initialize a stack for iterative traversal
        link current = h;

        while (current != NULL || !is_empty_stack(stack)) {
            while (current != NULL) {
                push_stack(stack, current);
                current = left(current);
            }

            current = pop_stack(stack);
            sortedArray[index++] = get_binary_tree_root(current);
            current = right(current);
        }

        delete_stack(&stack); // Free stack memory
    }

    // Rebuild balanced BST from the sorted array
    free(h); // Free memory of the original BST

    int start = 0, end = size - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        h = insert_BST(h, sortedArray[mid]);

        if (mid > 0) {
            link prev = select_BST(h, mid - 1);
            prev->right = NULL;
        }

        if (mid < size - 1) {
            link next = select_BST(h, mid + 1);
            next->left = NULL;
        }

        if (mid == 0 && mid == size - 1) break;

        if (mid == 0) {
            start = mid + 1;
        } else if (mid == size - 1) {
            end = mid - 1;
        } else {
            start = 0;
            end = size - 1;
        }
    }

    free(sortedArray);
    return h;
}

