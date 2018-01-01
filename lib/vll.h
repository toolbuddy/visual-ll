/*
    Implementation the data structure
*/

// data structure 
typedef struct visual_linkedlist{
    int type;
    float sort;
    struct visual_linkedlist *next; // point to next one
    struct visual_linkedlist *prev; // point to previous one
} vll;