#include<iostream>
struct node {
    struct node * n;
    int v;
};
typedef struct node * Stack;
Stack CreateStack(Stack r){
    if(r==NULL){
        r= new struct node;
        r->n=NULL
        return r;
    }
    return r;
}