#include "ll_graph.h"

vll_graph *init_graph(){
    vll_graph *node1=(vll_graph*)malloc(sizeof(vll_graph));
    vll_graph *node2=(vll_graph*)malloc(sizeof(vll_graph));
    vll_graph *node3=(vll_graph*)malloc(sizeof(vll_graph));
    vll_graph *node4=(vll_graph*)malloc(sizeof(vll_graph));

    // init value
    node1->type=1;node1->sort=1;
    node2->type=2;node2->sort=2;
    node3->type=3;node3->sort=3;
    node4->type=4;node4->sort=4;

    // build maintain link
    node1->arrow = node2;
    node2->arrow = node3;
    node3->arrow = node4;
    node4->arrow = NULL;

    // build connection
    node1->edge=(vll_graph**)malloc(4*sizeof(vll_graph*));
    node1->edge[0]=node3;
    node1->edge[1]=node2;
    node1->edge[2]=node4;
    node1->edge[3]=node1;

    node2->edge=(vll_graph**)malloc(2*sizeof(vll_graph*));
    node2->edge[0]=node3;
    node2->edge[1]=node4;

    node3->edge=(vll_graph**)malloc(sizeof(vll_graph*));
    node3->edge[0]=node1;

    node4->edge=(vll_graph**)malloc(sizeof(vll_graph*));
    node4->edge[0]=NULL;

    return node1;
}

void free_vll_graph(vll_graph *first_node){
    vll_graph *trav,*del;
    trav=first_node;
    while(trav!=NULL){
        int c=0;
        while(1){
            if(trav->edge[c]!=NULL){
                trav->edge[c]=NULL;
            }
            else 
                break;
            c++;
        }
        del=trav;
        trav=trav->arrow;
        del->arrow=NULL;
        free(del);
    }
}

void print_gv_vll_graph(vll_graph *first_node, FILE *fp){
    vll_graph *trav;
    trav=first_node;
    fprintf(fp,"digraph G {\n");
    while(trav!=NULL){
        // print all edges
        // printf("Node%d, %d \n",trav->type,get_edges(trav));
        int c=0;
        while(1){
            if(trav->edge[c]!=NULL){
                printf("Node%d -> Node%d\n",trav->type,trav->edge[c]->type);
                fprintf(fp,"\t%d -> %d\n",trav->type,trav->edge[c]->type);
            }
            else 
                break;
            c++;
        }
        trav=trav->arrow;
    }
    fprintf(fp,"}\n");
}