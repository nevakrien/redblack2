#ifndef NODE_OPS_H
#define NODE_OPS_H

#include "node.h"
#include "utils.h"

[[maybe_unused]]
static Node* search_node(Node* node,Data d){
	if(node->is_nil){
		return node;
	}

	CMP c = compare(d,node->data);
	if(c==0){
		return node;
	}
	if(c<0){
		return search_node(node->left,d);
	}
	else{
		return search_node(node->right,d);
	}
}

static inline Node* min_node( Node* node) {
    while (node->left->is_nil) {
        node = node->left;
    }
    return node;
}

static inline Node* max_node(Node* node) {
    while (node->right->is_nil) {
        node = node->right;
    }
    return node;
}

#include "debug.h"
static inline void left_rotate(RBTree* tree, Node* x) {
    ASSERT(!x->right->is_nil);
    Node* y = x->right;
    x->right = y->left;
    if (!y->left->is_nil) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent->is_nil) {
        tree->root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

static inline void right_rotate(RBTree* tree,Node* y) {
    ASSERT(!y->left->is_nil);
    Node* x = y->left;
    y->left = x->right;
    if (! x->right->is_nil) {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if (y->parent->is_nil) {
        tree->root = x;
    } else if (y == y->parent->right) {
        y->parent->right = x;
    } else {
        y->parent->left = x;
    }
    x->right = y;
    y->parent = x;
}

static inline Node* successor(Node* node) {
    if (!node->right->is_nil) {
        return min_node(node->right);
    }
    Node* y = node->parent;
    while (!y->is_nil && node == y->right) {
        node = y;
        y = y->parent;
    }
    return y;
}

static inline Node* predecessor(Node* node) {
    if (!node->left->is_nil) {
        return max_node(node->left);
    }
    Node* y = node->parent;
    while (!y->is_nil && node == y->left) {
        node = y;
        y = y->parent;
    }
    return y;
}

#endif // NODE_OPS_H
