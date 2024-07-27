#ifndef NODE_H
#define NODE_H

#include "utils.h"
#include "stdbool.h"
typedef struct Node Node;

typedef int Data;
typedef int CMP;
static inline CMP compare(Data a, Data b){
	return a-b;
}

static inline void dinit_data([[maybe_unused]] Data d){}


struct Node{
	Node* parent;
	Node* left;
	Node* right;
	char color;
	bool is_nil;
	Data data;
};


typedef struct {
	Node* NIL;
	Node* root;
} RBTree;

static inline void init_tree(RBTree* tree){
	tree->NIL=null_check(malloc(sizeof(Node)));
	Node* nil = tree->NIL;
	nil->parent=nil;
	nil->right=nil;
	nil->left=nil;
	nil->color='B';
	nil->is_nil=true;

	tree->root=nil;
}

static inline Node* make_node(RBTree* tree,Data d){
	Node* ans=null_check(malloc(sizeof(Node)));

	ans->data=d;
	ans->parent=tree->NIL;
	ans->right=tree->NIL;
	ans->left=tree->NIL;
	ans->color='R';
	ans->is_nil=false;

	return ans;
}


static inline void free_node(Node* node){
	if(node->is_nil){
		return;
	}
	free_node(node->right);
	free_node(node->left);
	dinit_data(node->data);
	free(node);
}

static inline void dinit_tree(RBTree* tree){
	free_node(tree->root);
	free(tree->NIL);
}

#endif //NODE_H