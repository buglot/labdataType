#include <iostream>
using namespace std;
struct node {
    int v;
    struct node * l;
    struct node * r;
};

typedef struct node * tree;
tree inserttree(tree a,int v){
    if(a==NULL){
        a=new struct node;
        a->l=NULL;
        a->r=NULL;
        a->v=v;
    }else{
        if(a->v>v){
            a->l=inserttree(a->l,v);
        }else{
            a->r=inserttree(a->r,v);
        }
    }
    return a;
}

tree deleteTree(){
    //กุลืม
}
void printInorder(tree a){
    if(a==NULL){
        return;
    }
    printInorder(a->l);
    cout << a->v << " ";
    printInorder(a->r);
}
void printpreorder(tree a){
    if(a==NULL){
        return;
    }
    cout << a->v << " ";
    printInorder(a->l);
    
    printInorder(a->r);
}
void printPostorder(tree node)
{
    if (node == NULL)
        return;
 
    // first recur on left subtree
    printPostorder(node->l);
 
    // then recur on right subtree
    printPostorder(node->r);
 
    // now deal with the node
    cout << node->v << " ";
}