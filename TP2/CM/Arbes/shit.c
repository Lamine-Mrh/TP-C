#include <stdio.h>
#include <stdlib.h>

typedef int item;

struct binary_tree
{
    item label;
    struct binary_tree* right_node;
    struct binary_tree* left_node;
};



typedef struct binary_tree *link;


void traverse_inorder_binary_tree(link h, void(*visit)(link)){
    if (h==NULL) return;
    traverse_inorder_binary_tree(h->left_node, visit);
    (*visit)(h);
    traverse_inorder_binary_tree(h->right_node, visit);
}

void traverse_preorder_binary_tree(link h, void(*visit)(link)){
    if (h==NULL) return;
    (*visit)(h);
    traverse_preorder_binary_tree(h->left_node, visit);
    traverse_preorder_binary_tree(h->right_node, visit);
}

void traverse_outorder_binary_tree(link h, void(*visit)(link)){
    if (h==NULL) return;
    traverse_outorder_binary_tree(h->left_node, visit);
    traverse_outorder_binary_tree(h->right_node, visit);
    (*visit)(h);
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
