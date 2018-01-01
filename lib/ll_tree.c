#include "ll_tree.h"

// create
vll_tree *create_vll_tree(){
    vll_tree *newone = (vll_tree*)malloc(sizeof(vll_tree));
    newone->left=NULL;
    newone->right=NULL;
    newone->parent=NULL;
    return newone;
}

// push (small one -> left, big one -> right)
int push_vll_tree(vll_tree *header, vll_tree *obj){
    // compare incoming
    vll_tree *trav;
    trav=header;
    if(obj->sort == trav->sort){
        // Change root
        obj->left=trav->left;
        obj->parent=trav->parent;
        trav->parent=obj;
        obj->right=trav;
        trav->left=NULL;
        return 0;
    }
    else if(obj->sort > trav->sort){
        // larger, goes right
        if(trav->right!=NULL)
            push_vll_tree(trav->right,obj);
        else{
            // insert 
            trav->right=obj;
            obj->parent=trav;
            return 0;
        }
    }
    else{
        // smaller, goes left
        if(trav->left!=NULL)
            push_vll_tree(trav->left,obj);
        else{
            // insert 
            trav->left=obj;
            obj->parent=trav;
            return 0;
        }
    }
}

// pop out the root, choose the biggest one as root
vll_tree *pop_vll_tree(vll_tree *header){

}

// pop smallest
vll_tree *pop_vll_tree_smallest(vll_tree *header){

}

// free header
void free_vll_tree(vll_tree *header){

}

// length, get total size of entire tree
int length_vll_tree(vll_tree *header){
    int left=0,right=0;
    if(header->left!=NULL)
        left+=length_vll_tree(header->left);
    if(header->right!=NULL)
        right+=length_vll_tree(header->right);
    return 1+left+right;
}

// print all
void print_vll_tree(vll_tree *header, FILE *fp){
    fprintf(fp,"digraph G{\n");
    print_gv_vll_tree(header,fp);
    fprintf(fp,"}\n");
}

// print with visualization support (output an graphviz dot files)
void print_gv_vll_tree(vll_tree *header, FILE *fp){
    if(header->left!=NULL){
        fprintf(fp,"\t%d -> %d [label=left];\n",header->type,header->left->type);
        // fprintf(fp,"\t%d -> %d\n",header->left->type,header->left->parent->type);
        print_gv_vll_tree(header->left,fp);
    }
    if(header->right!=NULL){
        fprintf(fp,"\t%d -> %d [label=right];\n",header->type,header->right->type);
        //fprintf(fp,"\t%d -> %d\n",header->right->type,header->right->parent->type);
        print_gv_vll_tree(header->right,fp);
    }
    return ;
}