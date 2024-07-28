#include "redblack.h"
#include "debug.h"
#include <stdio.h>

#define KEY_SIZE 301

//we are using evens so we can check if odds are there
void massive_insert(RBTree* tree,int cap){
	for(int i=0;i<cap;i++){
		insert_node(tree,2*(rand()%KEY_SIZE));
	}
}

void test_massive_insert(){
	RBTree tree;
	for(int i=0;i<1000;i++){
		init_tree(&tree);
		
		for(int k=0;k<10;k++){
			int sentinal = 2*(rand()%KEY_SIZE);
			insert_node(&tree,sentinal);
			massive_insert(&tree,100);
			assert(!(search_node(tree.root,sentinal)->is_nil));
		}
		
		int odd = 1+2*(rand()%KEY_SIZE);
		assert(search_node(tree.root,odd)->is_nil);

		scan_node(tree.root,false,0);
		dinit_tree(&tree);
	}
}

void test_delete(){
	RBTree tree;
	for(int i=0;i<10;i++){
		init_tree(&tree);
		
		for(int k=0;k<100;k++){
			int sentinal = 1+2*(rand()%KEY_SIZE);
			insert_node(&tree,sentinal);
			massive_insert(&tree,2);

			Node* del_node=search_node(tree.root,sentinal);
			assert(!(del_node->is_nil));
			// printf("[%d][%d]sentinal(%d) inserted\n",i,k,sentinal);
			fflush(stdout);

			scan_node(tree.root,false,0);

			// Node* g=del_node->parent->parent;
			// if(k==2){//2
			// 	printf("Before:\n");
			// 	check_and_pretty_print_node(tree.root,0);
			// 	for(int l=0;l<10;l++){putchar('\n');}
			// }

			delete_node(&tree,del_node);
			assert(search_node(tree.root,sentinal)->is_nil);
			// printf("[%d][%d]sentinal(%d) removed\n",i,k,sentinal);
			
			// if(k==2){
			// 	printf("After:\n");
			// 	check_and_pretty_print_node(tree.root,0);
			// }

			// fflush(stdout);

			scan_node(tree.root,false,0);
		}

		scan_node(tree.root,false,0);
		dinit_tree(&tree);
	}
}

void shuffle_array(int *array, int n) {
    if (n > 1) {
        for (int i = 0; i < n - 1; i++) {
            int j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

void test_random_delete() {
    printf("testing random delete\n");
    RBTree tree;
    int num_elements = 100;
    int elements[num_elements];

    for(int i=0;i<100;i++){
    	init_tree(&tree);
	    // Insert random elements into the tree
	    for (int k = 0; k < num_elements; k++) {
	        int sentinal = 1 + 2 * (rand() % KEY_SIZE);
	        elements[k] = sentinal;
	        insert_node(&tree, sentinal);
	        // printf("[%d] Inserted: %d\n", k,sentinal);
	        scan_node(tree.root,false,0);
	    }

	    // Shuffle the elements array to get a random order
	    shuffle_array(elements, num_elements);

	    // Remove elements in random order
	    for (int k = 0; k < num_elements; k++) {
	        int sentinal = elements[k];
	        Node* del_node = search_node(tree.root, sentinal);
	        assert(!(del_node->is_nil));
	        // Node* g = del_node->parent->parent;//successor(del_node)->parent->parent;
	        // if(k==15){
			// 	check_and_pretty_print_node(g,0);
	        // }

	        delete_node(&tree, del_node);
	        // printf("[%d] Removed: %d\n",k, sentinal);
	        
	        // if(k==15){
			// 	check_and_pretty_print_node(g,0);
	        // }
	        scan_node(tree.root,false,0);
	    }

	    assert(tree.root->is_nil);

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
	
	massive_insert(&tree,20);
	// check_and_pretty_print_node(tree.root,0);
	scan_node(tree.root,false,0);


	dinit_tree(&tree);
}

int main(){
	// srand(37);
	srand(23);
	test_delete();

	test_basic_insert();
	test_massive_insert();
	test_random_delete();
	printf("ALL TESTS PASSED!!!!\n");
}