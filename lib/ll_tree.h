#ifndef LL_TREE
#define LL_TREE
/*
    Implementation of visualization linked-list
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "vll.h"

/* 
    operation on visual-ll binary tree
*/
// create
vll_tree *create_vll_tree();

// push (small one -> left, big one -> right)
int push_vll_tree(vll_tree *header, vll_tree *obj);

// pop out the root, choose the biggest one as root
vll_tree *pop_vll_tree(vll_tree *header); 

// pop smallest
vll_tree *pop_vll_tree_smallest(vll_tree *header);

// free header
void free_vll_tree(vll_tree *header);

// length, get total size of entire tree
int length_vll_tree(vll_tree *header);

// print all
void print_vll_tree(vll_tree *header, FILE *fp);

// print with visualization support (output an graphviz dot files)
void print_gv_vll_tree(vll_tree *header, FILE *fp);

#endif