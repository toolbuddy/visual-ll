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

    //printf("Test node edges number: %d\n",get_edges(node1));

    node2->edge=(vll_graph**)malloc(2*sizeof(vll_graph*));
    node2->edge[0]=node3;
    node2->edge[1]=node4;

    node3->edge=(vll_graph**)malloc(sizeof(vll_graph*));
    node3->edge[0]=node1;

    node4->edge=(vll_graph**)malloc(sizeof(vll_graph*));
    node4->edge[0]=NULL;

    return node1;
}

vll_graph *create_node(){
    // create node
    vll_graph *newnode=(vll_graph*)malloc(sizeof(vll_graph));
    newnode->arrow=NULL;
    newnode->edge=(vll_graph**)malloc(sizeof(vll_graph*));
    newnode->edge[0]=NULL;

    return newnode;
}

int append_graph(vll_graph *graph,vll_graph *node){
    // append into graph
    vll_graph *trav;
    trav=graph;
    while(trav->arrow!=NULL){
        trav=trav->arrow;
    }
    trav->arrow=node;
}

int add_link(vll_graph *arrow_tail, vll_graph *arrow_head){
    // from arrow_tail to head
    // check tail's edges
    int edges=0;
    edges=get_edges(arrow_tail);
    // resize 
    arrow_tail->edge=(vll_graph**)realloc(arrow_tail->edge,(edges+1)*sizeof(vll_graph*));
    // assign
    arrow_tail->edge[edges]=arrow_head;
}

int get_edges(vll_graph *node){
    int c=0;
    while(1){
        if(node->edge[c]!=NULL){
            c++;
        }
        else 
            break;
    }
    return c;
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
            else{
                fprintf(fp,"\t%d\n",trav->type);
                break;
            }
            c++;
        }
        trav=trav->arrow;
    }
    fprintf(fp,"}\n");
}