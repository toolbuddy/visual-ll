#include "ll.h"

// create
vll *create(){
    vll *newone = (vll*)malloc(sizeof(vll));
    newone->next=NULL;
    newone->prev=NULL;
    return newone;
}

// push
int push(vll *header, vll *obj){
    vll *trav;
    trav=header;
    while(trav->next!=NULL){
        trav=trav->next;
    }
    trav->next=obj;
    obj->prev=trav;
}

// push sort (by field: `sort`)
int push_sort(vll *header, vll *obj){
    // TODO
}

// pop from header
vll *pop(vll *header){
    vll *output;
    output=header->next;
    output->prev=NULL;
    // concat new header->next
    header->next=output->next;
    output->next=NULL;
    return output;
}

// pop last
vll *pop_last(vll *header){
    vll *trav;
    trav=header;
    while(trav->next!=NULL){
        trav=trav->next;
    }
    // cut
    trav->prev=NULL;
    return trav;
}

// free header
void free_vll(vll *header){
    int count=0;
    vll *del;
    del=header;
    while(header!=NULL){
        del=header;
        header=header->next;
        // header->prev=NULL;
        // free
        free(del);
        count++;
    }
    printf("Successfully free. Remove %d elements (include header).\n\n",count);
}

// length
int length(vll *header){
    int count=0;
    vll *trav;
    trav=header;
    while(trav->next!=NULL){
        trav=trav->next;
        count++;
    }
    return count;
}

// print all
void print(vll *header){
    vll *trav;
    trav=header;
    printf("Normal print all element: \n");
    while(trav->next!=NULL){
        trav=trav->next;
        printf("Element type: %d\n",trav->type);
    }
    printf("\n");
}

// print with visualization support (output an graphviz dot files)
void print_gv(vll *header, FILE *fp){
    vll *trav,*curr;
    trav=header;
    printf("Using visualizable graphviz output.\n");
    // write
    fprintf(fp,"digraph G {\n");
    while(trav->next!=NULL){
        trav=trav->next;
        if(trav->next!=NULL){
            fprintf(fp,"\t%d -> %d\n",trav->type,trav->next->type);
            fprintf(fp,"\t%d -> %d\n",trav->next->type,trav->next->prev->type);
        }
    }
    // write end 
    fprintf(fp,"}\n");
    printf("Successfully create visualizable graphviz output.\n\n");
}