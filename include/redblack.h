#ifndef REDBLACK_H
#define REDBLACK_H

#include "node.h"
#include "node_ops.h"

void init_tree(RBTree* tree);//Y
void dinit_tree(RBTree* tree);//Y

Node* search_node(Node* node,Data d); //Y
Node* insert_node(RBTree* tree,Data d); //Y
Node* delete_node(RBTree* tree,Node* node);


#endif // REDBLACK_H
