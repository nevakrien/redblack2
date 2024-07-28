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

//GPT
void test_specific_pattern() {
    RBTree tree;
    init_tree(&tree);

    // Specific insertions to create the desired tree structure
    insert_node(&tree, 20);   // Root (B)
    insert_node(&tree, 10);   // Left child (R)
    insert_node(&tree, 30);   // Right child (R)
    insert_node(&tree, 5);    // Left-Left child (B)
    insert_node(&tree, 15);   // Left-Right child (B)
    insert_node(&tree, 25);   // Right-Left child (B)
    insert_node(&tree, 35);   // Right-Right child (B)
    insert_node(&tree, 3);    // Left-Left-Left child (R) -> Will delete to trigger fixup
    insert_node(&tree, 7);    // Left-Left-Right child (R)
    insert_node(&tree, 12);   // Left-Right-Left child (R)
    insert_node(&tree, 17);   // Left-Right-Right child (R)

    // Delete node 3 (red leaf) to trigger the scenario
    Node* del_node = search_node(tree.root, 3);
    if (!del_node->is_nil) {
        delete_node(&tree, del_node);
    }

    // Validate tree structure and properties
    scan_node(tree.root, false, 0);

    dinit_tree(&tree);
}

void test_massive_random_oscillating() {
    printf("testing massive random oscillating patterns\n");
    RBTree tree;
    int num_waves = 100;
    int max_elements_per_wave = 10;
    int total_elements = num_waves * max_elements_per_wave;
    int elements[total_elements];
    int element_count = 0;

    for(int j=0;j<10;j++){

	    init_tree(&tree);

	    for (int wave = 0; wave < num_waves; wave++) {
	        // Randomly determine the number of elements for this wave
	        int num_elements = rand() % max_elements_per_wave;

	        // Insert random elements into the tree
	        for (int k = 0; k < num_elements; k++) {
	            int sentinel = 2 * (rand() % KEY_SIZE);
	            elements[element_count++] = sentinel;
	            insert_node(&tree, sentinel);
	        }

	        // Shuffle the elements array to get a random order
	        shuffle_array(elements, element_count);

	        // Randomly determine how many elements to delete this wave
	        int num_deletions = rand() % (element_count + 1);

	        // Remove elements in random order
	        for (int k = 0; k < num_deletions; k++) {
	            int sentinel = elements[k];
	            Node* del_node = search_node(tree.root, sentinel);
	            if (!del_node->is_nil) {
	                delete_node(&tree, del_node);
	                elements[k] = elements[--element_count]; // Remove from array
	            }
	            scan_node(tree.root, false, 0); // Optional, for debugging
	        }

	        // Validate tree structure and properties
	        scan_node(tree.root, false, 0);
	    }

	    // Final wave: Delete all remaining elements
	    for (int k = 0; k < element_count; k++) {
	        int sentinel = elements[k];
	        Node* del_node = search_node(tree.root, sentinel);
	        if (!del_node->is_nil) {
	            delete_node(&tree, del_node);
	        }
	    }

	    // Ensure tree is empty after all deletions
	    assert(tree.root->is_nil);

	    dinit_tree(&tree);
	}
}



int main(){
	// srand(37);
	srand(23);
	test_specific_pattern();
	test_delete();

	test_basic_insert();
	test_massive_insert();
	test_random_delete();

	test_massive_random_oscillating();
	printf("ALL TESTS PASSED!!!!\n");
}