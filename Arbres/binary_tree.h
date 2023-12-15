#ifndef BINARY_TREE
#define BINARY_TREE

#include "item.h"
#include "queue_link.h"


struct binary_tree {
  item label; /* label of the root */
  struct binary_tree *left; /* NULL if no left subtrees */
  struct binary_tree *right; /* NULL if no right subtree */
};
typedef struct binary_tree *link;

/********************************************************************/
/*  In the sequel, "tree" always stands for "(rooted) binary tree"  */
/********************************************************************/

/** "Creates" an empty tree and returns its address */
/** WARNING ! Does not require calls to functions allocating memory */
link empty_tree();

/* Constructs a binary tree from a label and two binary trees */
/* (allocates memory and returns the allocated block's address) */
link cons_binary_tree(item, const link, const link);

/* Frees all memory allocated to a tree and its subtrees */
/** WARNING ! The input parameter is a pointer to a link ! */
void delete_binary_tree(link *);

/** Returns the left subtree of a tree */
/* (N.B. Requires that the tree be non-empty) */
link left(const link);

/** Returns the right subtree of a tree */
/* (N.B. Requires that the tree be non-empty) */
link right(const link);

/** Returns the label of the root of a tree */
/* (N.B. Requires that the tree be non-empty) */
item get_binary_tree_root(const link);

/** Tests a tree for emptyness */
int is_empty_binary_tree(const link);

/** Computes recursively and returns the size of a tree */
int size_binary_tree(const link);

/** Displays information attached to the root */
void print_label(const link);

/** Prints a tree (rotated by -\pi/2) */
void show_binary_tree(const link, int);

/** Traverses recursively a tree according to inorder */
void traverse_inorder_binary_tree(link, void (*)(link));

/** Traverses recursively a tree according to preorder */
void traverse_preorder_binary_tree(link, void (*)(link));

/** Traverses recursively a tree according to postorder */
void traverse_postorder_binary_tree(link, void (*)(link));

/** Traverses iteratively a tree according to level-order (using a queue) */
void traverse_level_binary_tree(link h, void (*visit)(link));


#endif
