#include <bits/stdc++.h>
using namespace std;
#define filename "test"
#define fr(i,a,b) for (auto i = a ; i < b ;i++)
#define fx(a) for (auto x:a)
#define pb push_back
#define ll long long
long long t,n;
//#define m 1000000007
//#define e 0.000000001
// F5 to run code
void Solve();
void Task(){
    #ifndef ONLINE_JUDGE
    clock_t begin = clock();
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(filename ".inp", "r"))
    {
        freopen(filename ".inp", "r", stdin);
        freopen(filename ".out", "w", stdout);
    }
    #endif
    Solve();
    #ifndef ONLINE_JUDGE
    cerr << "Time: " << (clock() - begin + 1.0) / CLOCKS_PER_SEC << "s";
    #endif
}
struct Node{
    int data;
    Node * next;
};
typedef Node * node;
node crnode(int n){
    node newnode= new Node;
    newnode->data=n;
    newnode->next=NULL;
    return newnode;
}
void insF(node &head,int n){
    node newnode=crnode(n);
    newnode->next=head;
    head=newnode;
}
void insL(node &head,int n){
    node newnode=crnode(n);
    if(head==NULL){
        head=newnode;
    }else{
        node p=head;
        while (p->next)
        {
            p=p->next;
        }
        p->next=newnode;
    }
}
int dem(node head){
    int c=0;
    while(head!=NULL){
        c++;
        head=head->next;
    }
    return c;
}
void duyet(node head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
void insP(node &head,int k,int n){
    node newnode=crnode(n);
    if(k<1||k>dem(head)+1){
        return;
    }else if(k==1){
        insF(head,n);
    }else if(dem(head)+1==k){
        insL(head,n);
    }
    else{
        node p=head;
        for(int i=1;i<=k-2;i++){
            p=p->next;
        }
        newnode->next=p->next;
        p->next=newnode;
    }
}
void deF(node &head){
    node temp=head;
    head=head->next;
    delete temp;
}
void deL(node &head) {
    node p = head;
    node tr = NULL;
    while (p->next) {
        tr = p;
        p = p->next;
    }
    tr->next = NULL;
    delete p;
}
void deP(node &head, int x) {
    node p = head;
    if (x == 1) {
        deF(head);
        return;
    }
    for (int i = 1; i <= x - 2; i++) {
        p = p->next;
    }
    node temp = p->next;
    p->next = temp->next;
    delete temp;
}
void deK(node &head, int k) {
    if (head != nullptr && head->data == k) {
        node temp = head;
        head = head->next;
        delete temp;
        return;
    }
    node p = head;
    while (p != nullptr && p->next != nullptr) {
        if (p->next->data == k) {
            node temp = p->next;
            p->next = temp->next;
            delete temp;
        } else {
            p = p->next;
        }
    }
}
void  Reverse(node &F){
    node prev = nullptr;
    node curr = F;
    node next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    F = prev;

    do{
        node kq=NULL;
        node p=F;
        while (p!=NULL)
        {
            insF(kq,p->data);
            p=p->next;
        }
    }
    while(0);
}
void deD(node head,int d){
    if(head==NULL){
        return;
    }
    while (head!=NULL&&head->data<d)
    {
        Node * p=head;
        head=head->next;
        delete p;
    }
    Node * tmp=head;
    while (tmp!=NULL&&tmp->next!=NULL)
    {
        if(tmp->next->data<d){
            Node * luu=tmp->next;
            tmp->next=luu->next;
            delete luu;
        }else{
            tmp=tmp->next;
        }
    }
}
void bubbleSort(node & head) {
    if (head == NULL || (head)->next == NULL) {
        return;
    }
    node last = NULL;
    bool co;
    do {
        co = false;
        node p = head;
        while (p->next != last) {
            if (p->data > p->next->data) {
                int temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
                co = true;
            }
            p = p->next;
        }
        last = p;
    } while (co);
}
void Solve() {
    int n;
    node head=NULL;
    while(cin>>n){
        if(n==1){
            int x;
            cin>>x;
            insF(head,x);
        }
        if(n==2){
            int x;
            cin>>x;
            insL(head,x);
        }
        if(n==3){
            int x,k;
            cin>>k>>x;
            insP(head,k,x);
        }
        if(n==4){
            deF(head);
        }
        if(n==5){
            deL(head);
        }
        if(n==6){
            int x; cin>>x;
            deP(head,x);
        }
        if(n==8){
            int k;
            cin>>k;
            deK(head,k);
        }
        if(n==7){
            duyet(head);
        }
    }   
}
int main() {
    Task();
}
