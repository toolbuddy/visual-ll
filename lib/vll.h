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

typedef struct visual_ll_tree{
    int type;
    float sort;
    struct visual_ll_tree *left;       // point to left child
    struct visual_ll_tree *right;      // point to right child
    struct visual_ll_tree *parent;     // point to parent node
} vll_tree;

#endif