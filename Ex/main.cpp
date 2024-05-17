#include <bits/stdc++.h>
using namespace std;
#define name "test"
#define fr(i,a,b) for (auto i = a ; i < b ;i++)
#define FR(i,a,b) for (auto i = a ; i < b ;i--)
#define fx(a) for (auto x:a)
#define w(n) while(n--)
#define gl(s) getline(cin,s)
#define c(n) cin>>n;
#define pb push_back
#define fi first
#define se second
#define ll long long
#define m 1000000007
#define e 0.000000001
long long t,n;
// F5 to run code
void Solve();
void Task() {
    clock_t begin = clock();
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    if (fopen(name ".inp", "r"))
    {
        freopen(name ".inp", "r", stdin);
        freopen(name ".out", "w", stdout);
    }
    Solve();
    cerr << "Time: " << (clock() - begin + 1.0) / CLOCKS_PER_SEC << "s";
}
//Node
struct Node{
    int data;
    Node* next;
};
//define con trỏ Node là node
typedef struct Node * node;
//tạo node mới
node crnode(int x){
    node p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}
//dem phần tử
size_t Size(node head){
    size_t n = 0;
    while(head != NULL){
        n++;
        head=head->next;
    }
}
//chèn đầu
void insF(node &head, int x){
    node tmp=crnode(x);
    if(head==NULL){
        head=tmp;
    }else{
        tmp->next = head;
        head=tmp;
    }
}
//chèn cuối
void insL(node &head, int x){
    node tmp=crnode(x);
    if(head==NULL){
        head=tmp;
    }else{
        node p=head;
        while(p->next){
            p=p->next;
        }
        p->next=tmp;
    }
}
//chèn trước p
void insP(node &head, int x,int p){
    int n=Size(head);
    if(p<=0||p>=n+1){
        cout<<"Loi"<<endl;
        return;
    }
    if(n==1){
        insF(head,x);
    }
    else if(n==p+1){
        insL(head,x);
    }
    else{
        node ct=head;
        for(int i=1;i<p-1;i++){
            ct=ct->next;
        }
        node tmp=crnode(x);
        tmp->next=ct->next;
        ct->next=tmp;
    }
}
//xóa đầu
void DeleteF(node &head){
    if(head==NULL){
        return;
    }
    else{
        head=head->next;
    }
}
//Xóa cuối
void DeleteL(node &head){
    if(head==NULL){
        return;
    }else{
        node truoc=NULL,sau=head;
        while(sau->next){
            truoc=sau;
            sau=sau->next;
        }
        if(truoc==NULL){
            head=NULL;
        }
        else{
            truoc->next=NULL;
        }
    }
}
//xóa vị trí p
void DeleteP(node &head,int p){
    if(p<=0||p>Size(head)){
        return;
    }
    node truoc=NULL,sau=head;
    for(int i=0;i<p-1;i++){
        truoc=sau;
        sau=sau->next;
    }
    if(truoc==NULL){
        head=head->next;
    }else{
        truoc->next=sau->next;
    }
}
//in ra
void in(node head){
    while(head->next){
        cout<<head->data<<" ";
        head=head->next;
    }
}
void Solve(){
    //khoi tao node
    node head=NULL;

}
int main() {
    Task();
}
