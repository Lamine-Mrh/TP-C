#include <stdlib.h>
#include <stdio.h>
#include "bst.h"
#include "stack_link.h"
#include "binary_tree.h"
#include "item.h"

/*****************************************************/
/***               TD n°5  Exercice 3              ***/
/*****************************************************/
/** Deletes the first node of label v in a BST */
/* and returns the updated BST */
link delete_node_BST(link h, item v) {
  link x;
  item u;
  if (NULL == h) return h;
  u = h->label;
  if (less(v, u))
    h->left = delete_node_BST(h->left, v);
  if (less(u, v))
    h->right = delete_node_BST(h->right, v);
  if (eq(v, u)) {
    x = h;
    if (NULL == h->right) {
      h = h->left;
    }
    else {
      h->right = partition_BST(h->right, 0);
      h->right->left = h->left;
      h = h->right;
    }
    free(x);
  }
  return h;
}
