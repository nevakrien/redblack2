#include "redblack.h"
#include "debug.h"
#include <stdio.h>

#define KEY_SIZE 13

void massive_insert(RBTree* tree,int cap){
	for(int i=0;i<cap;i++){
		insert_node(tree,rand()%KEY_SIZE);
	}
}

void test_massive_insert(){
	RBTree tree;
	for(int i=0;i<1000;i++){
		init_tree(&tree);
		massive_insert(&tree,1000);
		scan_node(tree.root,false,0);
		dinit_tree(&tree);
	}
}

void test_basic_insert(){
	RBTree tree;
	init_tree(&tree);

	insert_node(&tree,1);
	insert_node(&tree,0);
	insert_node(&tree,6);
	insert_node(&tree,2);
	insert_node(&tree,3);

	scan_node(tree.root,false,0);
	
	massive_insert(&tree,100);
	// check_and_pretty_print_node(tree.root,0);
	scan_node(tree.root,false,0);


	dinit_tree(&tree);
}

int main(){
	// srand(37);
	srand(23);
	test_basic_insert();
	test_massive_insert();

	
}