#ifndef VLL 
#define VLL 
/*
    Implementation the data structure
*/

// data structure - normal linked-list
typedef struct visual_linkedlist{
    int type;
    float sort;
    struct visual_linkedlist *next; // point to next one
    struct visual_linkedlist *prev; // point to previous one
} vll;

// binary tree
typedef struct visual_ll_tree{
    int type;
    float sort;
    struct visual_ll_tree *left;       // point to left child
    struct visual_ll_tree *right;      // point to right child
    struct visual_ll_tree *parent;     // point to parent node
} vll_tree;

// graph (directed/undirected)
typedef struct graph{
    int type;
    float sort;
    struct graph **edge;        // multiple edges, logic
    struct graph *arrow;     // concat all vertex, for operation
} vll_graph;

#endif