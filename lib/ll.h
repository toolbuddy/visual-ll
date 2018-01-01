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
    operation on visual-ll
*/

// create
vll *create();

// push
int push(vll *header, vll *obj);

// push sort (by field: `sort`)
int push_sort(vll *header, vll *obj);

// pop from header
vll *pop(vll *header);

// pop last
vll *pop_last(vll *header);

// free header
void free_vll(vll *header);

// length
int length(vll *header);

// print all
void print(vll *header);

// print with visualization support (output an graphviz dot files)
void print_gv(vll *header, FILE *fp);