#ifndef DEBUG_H
#define DEBUG_H

#include "node.h"
#include "stdbool.h"
#include <stdio.h>

// static inline void verify_binary(Node* node){
// 	if(!node->left->is_nil){
// 		ASSERT(compare(node->data,node->left->data)>=0);
// 		verify_binary(node->left);
// 	}
// 	if(!node->right->is_nil){
// 		ASSERT(compare(node->right->data,node->data)>=0);
// 		verify_binary(node->right);
// 	}
// 	// printf("checked\n");
// }

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_RESET "\x1b[0m"

static void print_with_color_and_indent(const char* text, const char* color, int indent) {
    for (int i = 0; i < indent; ++i) {
    	printf("        ");
    }
    printf("%s%s%s", color, text, ANSI_COLOR_RESET);
}

static void print_with_indent(const char* text, int indent) {
    for (int i = 0; i < indent; ++i) {
        printf("        ");
    }
    printf(text);
}


static int scan_node(Node* node,bool print,int indent){
	#define PRINT(text) \
		if(print){\
			print_with_indent(text,indent);\
		}\
	
	if(node->is_nil){
		ASSERT(node->color=='B');
		PRINT("NIL\n");
		return 1;
	}

	if(node->parent->is_nil){
		ASSERT(node->color=='B');
	}

	int blacks=0;

	char* color;

	if(node->color=='R'){
		color="RED";
		// PRINT("RED");
		ASSERT('B'==node->right->color && 'B'==node->left->color);
	}
	else{
		color="BLACK";
		// PRINT("BLACK");
		blacks++;
	}

	

	if(!node->right->is_nil){
		ASSERT(node == node->right->parent);
		CMP c=compare(node->right->data,node->data);
		ASSERT(c>=0);
	}

	if(!node->left->is_nil){
		ASSERT(node == node->left->parent);
		CMP c=compare(node->left->data,node->data);
		ASSERT(c<=0);
	}

	int left = scan_node(node->left,print,indent+1);
	PRINT(color)
	if(print){printf("[%d]\n",node->data);}
	int right = scan_node(node->right,print,indent+1);

	ASSERT(left==right);

	return blacks+left;

	#undef PRINT
}

//GPT


static int check_and_pretty_print_node(Node* node, int indent) {
    if (node->is_nil) {
        if (node->color != 'B') {
            print_with_color_and_indent("NIL\n", ANSI_COLOR_RED, indent);
        } else {
            print_with_indent("NIL\n", indent);
        }
        return 1;
    }

    if (node->parent->is_nil && node->color != 'B') {
        print_with_color_and_indent("ROOT NOT BLACK\n", ANSI_COLOR_RED, indent);
    }

    int blacks = 0;
    bool failed = false;
    const char* color;

    if (node->color == 'R') {
        color = "RED";
        if (node->right->color != 'B' || node->left->color != 'B') {
            failed = true;
        }
    } else {
        color = "BLACK";
        blacks++;
    }

    if (!node->right->is_nil && node != node->right->parent) {
        failed = true;
    }

    if (!node->left->is_nil && node != node->left->parent) {
        failed = true;
    }

	int right = check_and_pretty_print_node(node->right, indent + 1);	    

    if (failed) {
        print_with_color_and_indent(color, ANSI_COLOR_RED, indent);
    } else {
        print_with_indent(color, indent);
    }
    printf("[%d]\n", node->data);

    int left = check_and_pretty_print_node(node->left, indent + 1);

    

    if (left != right) {
        failed = true;
    }

    return blacks + left;
}

#endif // DEBUG_H
