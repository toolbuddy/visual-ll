#ifndef LL_GRAPH
#define LL_GRAPH
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
    operation on visual-ll graph
*/
vll_graph *init_graph();

int get_edges(vll_graph *node);

int add_link(vll_graph *arrow_tail, vll_graph *arrow_head);

vll_graph *create_node();

int append_graph(vll_graph *graph,vll_graph *node);

void free_vll_graph(vll_graph *first_node);

void print_gv_vll_graph(vll_graph *first_node, FILE *fp);

#endif