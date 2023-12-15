#ifndef _BST_H
#define _BST_H

#include "binary_tree.h"

/** Searches a BST for a label and returns a pointer to a node with this label */
/* Returns NULL if there is no node with this label */
link search_BST(link h, item v);

/** Inserts a node with a given label in a BST */
/* and returns a link to the updated BST */
link insert_BST(link h, item v);

/** Selects the kth label of a BST */
/* and returns a pointer to the corresponding node */
/* Returns NULL if the BST does not contain k labels */
link select_BST(link h, int k);

/*************     ROTATIONS        *************/

/** Applies a right rotation the root of a BST */
link rotate_right(link h);

/** Applies a left rotation to the root of a BST */
link rotate_left(link h);

/** Inserts a node with a given label at the root of BST */
/* and returns the updated BST */
link insert_BST_root(link h, item v);

/** Partitions a BST with respect to the node of rank k */
/* and returns the updated BST */
link partition_BST(link h, int k);

/** Deletes the first node of label v in a BST */
/* and returns the updated BST */
link delete_node_BST(link h, item v);

/** Puts a BST into perfect balance, by recursively */
/* putting the median node at the root */
link balance_BST(link h);

#endif
