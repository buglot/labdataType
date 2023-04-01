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
Stack top(Stack r){
    return r->n;
}
int pop(Stack r){
    if(r->n==NULL){
        return NULL;
    }
    Stack p = r->n;
    r->n=r->n->n;
    int a = p->n->v;
    delete(p);
    return a;
}