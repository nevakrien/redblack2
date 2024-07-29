#include "redblack.h"
#include "utils.h"
#include <string.h>

static void insert_fixup(RBTree* tree,Node* node){
	while(node->parent->color=='R'){
		Node* p = node->parent;
		Node* g = p->parent;
		Node* u = (p==g->right)? g->left : g->right;

		//check if we can recolor
		if(u->color=='R'){
			u->color='B';
			p->color='B';
			if(unlikely(g->parent->is_nil)){
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
	if(unlikely(tree->root->is_nil)){
		tree->root=node;
		node->color='B';
		return node;
	}

	Node* cur = tree->root;
	


	while(1){
		CMP c = compare(node->data,cur->data);
		if(c>0){
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

static void replace_for_parent(RBTree* tree,Node* node,Node* t){
	if(unlikely(node->parent->is_nil)){
		tree->root=t;
	}
	else if (node->parent->right==node){
		node->parent->right=t;
	}
	else if (node->parent->left==node){
		node->parent->left=t;
	}
	else{
		UNREACHABLE();
	}
}

static inline Node* get_sibling(Node* node){
	Node* p=node->parent;
	if(p->right==node){
			return p->left;
	}
	else if(p->left==node){
		return p->right;
	}
	else{
		UNREACHABLE();
	}
}

static void delete_fixup(RBTree* tree,Node* node){
	Node* p;
	Node* s;

	while(node->color=='B' && !unlikely(node->parent->is_nil)){
		p=node->parent;
		s=get_sibling(node);
		ASSERT(!s->is_nil); //node is black (no kids) so sibling must contain black level 2
		// if(s->is_nil){
		// 	node=node->parent;
		// 	continue;
		// }
		if(s->color=='R'){
			//!printf("red sibling\n");
			p->color='R';
			s->color='B';
			if(s==p->left){
				right_rotate(tree,p);
			}
			else{
				left_rotate(tree,p);
			}
			s=get_sibling(node);
			//this case never loops because:
			//now S is black. IF we triger the BB case then
			//we will do node=node->parent and since parent is red
			//that would break the loop
		}
		ASSERT(s->color=='B');
		//the likely here is a hack 
		//for forcing the compiler to optimize for this worse case
		//since the only way this loop is anything more than 2 operations is here
		//it may be the compiler figures this out. if it does remove the likely
		if(likely(s->left->color=='B' && s->right->color=='B')){

			//!printf("black sibling no children\n");
			//now we know both children are black 
			s->color='R';
			node=node->parent;
			continue;
			//this is the only case that actually loops
			//as you can see its fairly specific
		}

		//loop wil now terminate

		//!printf("black sibling with red child:\n");
		//siblings children are either nil or red

		if(s==p->right && s->right->color=='R'){
			//this has a BUG
			s->right->color='B';
			s->color=p->color;
			p->color='B';
			left_rotate(tree,p);
			ASSERT(p->parent==s);
			return;
		}

		if(s==p->left && s->left->color=='R'){
			//this has a BUG
			s->left->color='B';
			s->color=p->color;
			p->color='B';
			right_rotate(tree,p);
			ASSERT(p->parent==s);
			
			return;
		}

		//!printf("complex case\n");
		//siblings kid is oposite side to us

		if(s==p->right && s->left->color=='R'){
			s->left->color=p->color;
			
			right_rotate(tree,s);
			left_rotate(tree,p);
			p->color='B';
			return;
		}

		if(s==p->left && s->right->color=='R'){
			s->right->color=p->color;
			left_rotate(tree,s);
			right_rotate(tree,p);
			p->color='B';
			return;
		}
		
		UNREACHABLE();
	}
	node->color='B';
}

void delete_node(RBTree* tree,Node* node){
	ASSERT(!node->is_nil);


	if(likely((!node->right->is_nil) && (!node->left->is_nil))){
		
		Node* s = successor(node);
		//!printf("2 kids (suc is %d)\n",s->data);

		memcpy(&(node->data), &(s->data), sizeof(Data));
		node=s;
	}

	ASSERT(node->right->is_nil || node->left->is_nil);


	Node* child = node->left->is_nil ? node->right : node->left;
	if(!child->is_nil){
		//!printf("1 kid (%d)\n",child->data);
		//since the other child is nil our child MUST be red thus we are black
		ASSERT('R'==child->color && 'B'==node->color);

		child->parent=node->parent;
		replace_for_parent(tree,node,child);
		child->color='B';
	}
	else{
		if(node->color=='R' || node->parent->is_nil){
			//!printf("red node or root\n");
			replace_for_parent(tree,node,node->left);//node at left is nil
			
		}
		else{
			//!printf("black node\n");
			// node->is_nil=true;
			delete_fixup(tree,node);
			replace_for_parent(tree,node,node->left);//node at left is nil
		}
	}
	free(node);
}