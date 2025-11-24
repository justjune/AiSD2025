#include "L039_112.h"
#include "tree.h"
#include <stddef.h>
#include <stdio.h>

void traverse_tree(tree* l)
{
    if (l != NULL) {
        traverse_tree(l->left);
        printf("%d\n", l->item);
        traverse_tree(l->right);
    }
}