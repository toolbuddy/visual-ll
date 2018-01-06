#include "../lib/ll_graph.h"
#include <time.h>

int main(int argc,char *argv[]){
    printf("Demo: visual-ll, visualization linked-list implementation\n");
    // DEMO 4: graph
    vll_graph *graph=init_graph();
    FILE *fp3;
    // check 
    if(argc<2){
        printf("[Error] Need to give the output file for 'vll_graph' graphviz.\n");
        exit(1);
    }
    else{
        fp3=fopen(argv[1],"w+");
    }
    // Giving an example of new node
    vll_graph *newnode=create_node(),*newnode2=create_node();
    newnode->type=99;
    newnode->sort=99;
    newnode2->type=50;
    newnode2->sort=50;
    append_graph(graph,newnode);
    append_graph(graph,newnode2);
    // Test add_link 
    add_link(newnode2,newnode);
    
    // plot 
    print_gv_vll_graph(graph,fp3);
    // clean
    free_vll_graph(graph);

    return 0;
}