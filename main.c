#include "lib/ll.h"
#include "lib/ll_tree.h"
#include "lib/ll_graph.h"
#include <time.h>

vll *header;
vll_tree *binary_tree;

int main(int argc,char *argv[]){
    printf("Demo: visual-ll, visualization linked-list implementation\n");
    // init
    header=create();
    for(int i=0;i<10;i++){
        vll *newone = create();
        newone->type=i;
        push(header,newone);
    }
    printf("Length: %d\n",length(header));

    // DEMO 1
    print(header);
    // DEMO 2
    FILE *fp;
    // check 
    if(argc<2){
        printf("[Error] Need to give the output file for graphviz.\n");
        exit(1);
    }
    else{
        fp=fopen(argv[1],"w+");
    }
    print_gv(header,fp);

    // DEMO 3: binary tree
    binary_tree=create_vll_tree();
    binary_tree->type=50;
    binary_tree->sort=(float)50;
    srand(time(NULL));
    for(int i=0;i<10;i++){
        vll_tree *newone=create_vll_tree();
        newone->type=(rand()%100)+1;
        newone->sort=(float)(newone->type);
        //printf("%d\t",newone->type);
        push_vll_tree(binary_tree,newone);
    }
    printf("Total binary tree size: %d\n",length_vll_tree(binary_tree));
    FILE *fp2;
    // check 
    if(argc<3){
        printf("[Error] Need to give the output file for 'vll_tree' graphviz.\n");
        exit(1);
    }
    else{
        fp2=fopen(argv[2],"w+");
    }
    print_vll_tree(binary_tree,fp2);

    // DEMO 4: graph
    vll_graph *graph=init_graph();
    FILE *fp3;
    // check 
    if(argc<4){
        printf("[Error] Need to give the output file for 'vll_graph' graphviz.\n");
        exit(1);
    }
    else{
        fp3=fopen(argv[3],"w+");
    }
    // plot 
    print_gv_vll_graph(graph,fp3);
    // clean
    free_vll_graph(graph);
    free_vll_tree(binary_tree);
    free_vll(header);
    return 0;
}