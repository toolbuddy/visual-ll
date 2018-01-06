#include "../lib/ll.h"

vll *header;

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

    free_vll(header);
    
    return 0;
}