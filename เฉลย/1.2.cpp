#include <iostream>
#include <fstream>
using namespace std;
struct node{
    int value;
    struct node *next;
};
struct node *insert(struct node *list,int value){
    if(list==NULL){
        list = new struct node;
        list->value = value;
        list->next = NULL;
    }else{
        if(list->value > value){
            struct node *p;
            p= new struct node ;
            p->value=value;
            p->next=list;
            return p;
        }
        list->next = insert(list->next,value);
    }
    return list;
}
struct node *insertMAXMIN(struct node *list,int value){
    if(list==NULL){
        list = new struct node;
        list->value = value;
        list->next = NULL;
    }else{
        
        if(list->value < value){
            struct node *p;
            p= new struct node ;
            p->value=value;
            p->next=list;
            return p;
        }
        list->next = insertMAXMIN(list->next,value);
    }
    return list;
}

int menu(){
    int x;
    cout<<"===========MENU==========\n"
        <<"  1) Read file\n"
        <<"  2) Print Min to Max\n"
        <<"  3) Print Max to Min\n"
        <<"  4) Save file Min to Max\n  5) Save file Max to min\n"
        <<"  6) Exit\n"
        <<"Please choose > ";
    cin>>x;
    return x;
}

void Prinminmax(struct node *list){
    if(list==NULL){
        return;
    }
    cout<<list->value<<" ";
    Prinminmax(list->next);
}

void Prinmaxmin(struct node *list){
    if(list==NULL){
        return;
    }
    Prinmaxmin(list->next);
    cout<<list->value<<" ";
    
}

int main(){
    struct node * head=NULL,*p,*MAX=NULL;
    int x;
    int v;
    do{
        ifstream B;
        ofstream out;
        x=menu();
        switch(x){
            case 1:
                B.open("d.txt");
                while(B>>v){
                    head= insert(head,v);
                    MAX = insertMAXMIN(MAX,v);
                }
                B.close();
                cout<<"Readed\n";
                break;
            case 2:
                cout<<"List max-min: ";
                Prinminmax(head);
                cout<<endl;
                break;
            case 3:
                cout<<"List max-min: ";
                Prinmaxmin(head);
                cout<<endl;
                break;
            case 4:
                p=head;
                out.open("data.txt");
                while(p !=NULL){
                    out<<p->value <<" ";
                    p = p->next;
                }
                out.close();
                break;
            case 5:
                p=MAX;
                out.open("data.txt");
                while(p !=NULL){
                    out<<p->value <<" ";
                    p = p->next;
                }
                out.close();
                break;
        }
    }while(x!=6);
}