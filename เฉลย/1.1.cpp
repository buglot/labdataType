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

int menu(){
    int x;
    cout<<"===========MENU==========\n"
        <<"  1) Insert\n"
        <<"  2) Print Min to Max\n"
        <<"  3) Print Max to Min\n"
        <<"  4) Save file\n"
        <<"  5) Exit\n"
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
    struct node * link_list=NULL;
    int run=1;
    int value;
    struct node * walk;
    while(run){
        int menuchoose  = menu();
        ofstream A;
        switch(menuchoose){
            case 1:
                cout<<"Insert : ";
                cin>>value;
                link_list = insert(link_list,value);
                cout<<"Success!\n";
                break;
            case 2:
                cout<<"List max-min: ";
                Prinminmax(link_list);
                cout<<endl;
                break;
            case 3:
                cout<<"List max-min: ";
                Prinmaxmin(link_list);
                cout<<endl;
                break;
            case 4:
                walk=link_list;
                A.open("data.txt");
                while(walk !=NULL){
                    A<<walk->value <<" ";
                    walk = walk->next;
                }
                A.close();
                break;
            case 5:
                run = 0;
                break;
            default:
                cout<<"no have choice\n";
        }
    }
}