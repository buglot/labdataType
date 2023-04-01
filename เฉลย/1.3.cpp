#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;
struct node{
    struct node * next;
    int v;
};
typedef struct node * List;

List insert (List head,int v){
    if(head==NULL){
        head= new  struct node ;
        head->next= NULL;
        head->v=v;
    }else{
        if(head->v>v){
            List p =new struct node;
            p->next=head;
            p->v=v;
            return p;
        }
        head->next=insert(head->next,v);
    }
    return head;
}
List DeleteList(List h,int x){
    if(h==NULL){
        cout<<"None!\n";
        return h;
    }else{
        if(h->v==x){
            List temp = new struct node;
            temp = h;
            h = h->next;
            delete(temp);
            cout<<"delete "<<x <<"secess!\n";
            return h;
        }
        h->next=DeleteList(h->next,x);
    }
}
void Printd(List h){
    if(h==NULL){
        return;
    }
    cout<<h->v<<" ";
    Printd(h->next);
}
void menu(){
    cout<<"===========MENU=========="<<endl 
    <<"1) random 0-1,000,000"<<endl
    <<"2) Delete list"<<endl
    <<"3) Print Min to Max"<<endl
    <<"4) Print Max to Min"<<endl
    <<"5) Save file"<<endl
    <<"6) Exit"<<endl
    <<"Please choose > ";
}

int main(){
    List mylist=NULL;
    int x,v;
    do{
       
        menu();
        cin>>x;
        switch(x){
            case 1:
                
                for(int i=0;i<1000;i++){
                    int endWith=1000000;
                    int start = 0;
                    //srand(time(NULL)); ถ้าใช้ ภาษา c++ ตัวเก่ารุ่นใหม่มันดี
                    mylist=insert(mylist,rand() % (endWith-start +1) + start);
                    //ถ้าสุ่ม 0>= x <= 100 rand() %(100+1) + 0 
                    //ถ้าสุ่ม 20>= x <100 rand() %(99-20+1) + 20;

                }
                cout<<"Random Secess!\n";
                break;
            case 2:
                cout<<"select delete : ";
                cin>>v;
                mylist = DeleteList(mylist,v);
                break;
            case 3:
                cout<<"list:";
                Printd(mylist);
                cout<<"\n";
            case 4:
            case 5://ทำเอง
            case 6:
                break;
        }
    }while(x!=6);

}