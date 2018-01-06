#include "../lib/ll_tree.h"

vll_tree *binary_tree;

int main(int argc,char *argv[]){
    printf("Demo: visual-ll, visualization linked-list implementation\n");
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
    if(argc<2){
        printf("[Error] Need to give the output file for 'vll_tree' graphviz.\n");
        exit(1);
    }
    else{
        fp2=fopen(argv[1],"w+");
    }
    print_vll_tree(binary_tree,fp2);
    free_vll_tree(binary_tree);
    return 0;
}