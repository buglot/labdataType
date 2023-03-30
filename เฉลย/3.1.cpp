#include<iostream>
using namespace std;
struct node{
    int value;
    struct node *next;
};
typedef struct node *n;
void menu(){
    cout<<"====================\n";
    cout<<"\tMENU\n";
    cout<<"====================\n";
    cout<<"1) Input Adjacency list\n";
    cout<<"2) Show indegree outdegree\n";
    cout<<"3) Show max indegree\n";
    cout<<"4) Show max outdegree\n";
    cout<<"5) Exit\n";
    cout<<"Please choose > ";
}
n insert(n head,int x){
    if(head==NULL){
        head=new struct node;
        head->next=NULL;
        head->value=x;
    }else{
        if(head->value>x){
            n g;
            g=new struct node;
            g->next=head;
            g->value=x;
            return g;
        }
        head->next=insert(head->next,x);
    }
    return head;
}
void show(n head){
    if(head==NULL){
        return;
    }
    cout<<head->value<<" ";
    show(head->next);
}
int count(n head,int x,int v){
    if(head==NULL){
        return v;
    }else{
        if(head->value==x){
            v++;
        }
        count(head->next,x,v);
    }
}
int countNode(n head,int x){
    if(head ==NULL){
        return x;
    }
    x++;
    countNode(head->next,x);
}
void show_io(n head[],int x){
    int k=0;
    for(int i=0;i<9;i++){
          k+=count(head[i],x,0);  
    }
    cout<<"Indegree = "<<k<<endl;
    cout<<"Outdegee = "<<countNode(head[x],0)<<endl<<endl;
}
int Maxs(int a[]){
    int f=a[0];
    for(int i=1;i<9;i++){
        if(a[i]>f){
            f=a[i];
        }
    }
    return f;
}
void show_max_in(n head[],int a[]){
    for(int i=0;i<9;i++){
        a[i]=0;
        for(int j=0;j<9;j++){
            a[i]=count(head[j],i,a[i]);
        }
    }
    int m=Maxs(a);
    for(int i=0;i<9;i++){
        if(m==a[i]){
            cout<<i<<" ";
        }
    }
}
void show_max_out(n head[],int b[]){
    for(int j=0;j<9;j++){
        b[j]=countNode(head[j],0);
    }
    int m=Maxs(b);
    for(int i=0;i<9;i++){
        if(m==b[i]){
            cout<<i<<" ";
        }
    }
}
int main(){
    int x,in[9],out[9];
    n adj[9];
    do{
        menu();
        cin>>x;
        cout<<endl;
        switch(x){
            case 1:
                cout<<"Input Adj list\n";
                for(int i=0;i<9;i++){
                    n g=NULL;
                    cout<<i<<" : ";
                    while(1){
                        int s;
                        cin>>s;
                        if(s==-1){
                            break;
                        }
                        g=insert(g,s);
                    }
                    adj[i]=g;
                }
                cout<<"Show adj list\n";
                for(int i=0;i<9;i++){
                    cout<<i<<" : ";
                    show(adj[i]);
                    cout<<endl;
                }
                cout<<endl;
                break;
            case 2:
                cout<<"Input graph # :";
                int s;
                cin>>s;
                show_io(adj,s);
                break;
            case 3:
                cout<<"Max indegree\n";
                show_max_in(adj,in);
                cout<<endl;
                break;
            case 4:
                cout<<"Max outdegree\n";
                show_max_out(adj,out);
                cout<<endl;
                break;
            case 5:
                break;
            default:
                cout<<"No choice\n";
        }
    }while(x!=5);

}