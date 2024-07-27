#ifndef REDBLACK_H
#define REDBLACK_H

#include "node.h"
#include "node_ops.h"

void init_tree(RBTree* tree);
void dinit_tree(RBTree* tree);

Node* search_node(Node* node,Data d);
Node* insert_node(RBTree* tree,Data d);
Node* delete_node(RBTree* tree,Node* node);


#endif // REDBLACK_H
