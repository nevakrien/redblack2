#include "redblack.h"
#include "utils.h"
#include "debug.h"

static void insert_fixup(RBTree* tree,Node* node){
	while(node->parent->color=='R'){
		Node* p = node->parent;
		Node* g = p->parent;
		Node* u = (p==g->right)? g->left : g->right;

		//check if we can recolor
		if(u->color=='R'){
			u->color='B';
			p->color='B';
			if(g->parent->is_nil){
				return;
			}
			g->color='R';
			node=g;
			continue;
		}

		//RR
		if(g->right==p && p->right==node){
		case_rr:
			left_rotate(tree,g);
			g->color='R';
			p->color='B';
			break;
		}

		//RL
		if(g->right==p && p->left==node){
			right_rotate(tree,p);
			p=node;
			//node=old p
			goto case_rr;
		}

		//LL
		if(g->left==p && p->left==node){
		case_ll:
			right_rotate(tree,g);
			g->color='R';
			p->color='B';
			break;
		}

		//LR
		if(g->left==p && p->right==node){
			left_rotate(tree,p);
			p=node;
			//node=old p
			goto case_ll;
		}
	}

	tree->root->color='B';
}

Node* insert_node(RBTree* tree,Data d){
	Node* node = make_node(tree,d);
	if(tree->root->is_nil){
		tree->root=node;
		node->color='B';
		return node;
	}

	Node* cur = tree->root;
	


	while(1){
		CMP c = compare(node->data,cur->data);
		if(c>=0){
			if(cur->right->is_nil){
				cur->right=node;
				node->parent=cur;
				break;
			}
			cur=cur->right;
		}
		else{
			if(cur->left->is_nil){
				cur->left=node;
				node->parent=cur;
				break;
			}
			cur=cur->left;
		}
	}

	insert_fixup(tree,node);
	return node;
}