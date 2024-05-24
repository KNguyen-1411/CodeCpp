#include <bits/stdc++.h>
using namespace std;
#define filename "test"
#define fr(i, a, b) for (auto i = a; i < b; i++)
#define fx(a) for (auto x : a)
#define pb push_back
#define ll long long
long long t, n;
// #define m 1000000007
// #define e 0.000000001
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
struct Node {
    int id;     // Mã hàng
    int count;  // Số lượng
    int price;  // Đơn giá
    Node *next;
};
typedef Node * node;
node cr(int id, int count, int price){
    node p = new Node;
    p -> id = id;
    p -> count = count;
    p -> price = price;
    p -> next = NULL;
    return p;
}
void add(node &head,int id, int count, int price){
    node tmp = cr(id, count, price);
    if(head==NULL){
        head=tmp;
    }else{
        node p=head;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=tmp;
    }
}
void update(node &head,int id,int count){
    node p=head;
    while (p!=NULL){
        if(p->id==id){
            p->count+=count;
        }
        p=p->next;
    }
}
node get_count(node head,int count){
    while (head!=NULL)
    {
        if(head->count>=count){
            return head;
        }
        head=head->next;
    }
    return NULL;
}
node get_price(node head,int price){
    node luu=NULL;
    while (head!=NULL)
    {
        if(head->price>=price){
            luu=head;
        }
        head=head->next;
    }
    return luu;
}
void duyet(node head){
    while (head!=NULL)
    {
        cout<<head->id<<" "<<head->count<<" "<<head->price<<endl;
        head=head->next;
    }
}
void Solve(){
    node head=NULL;
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        if(s=="ADD"){
            int id,count,price;
            cin>>id>>count>>price;
            add(head,id,count,price);
        }else if(s=="GET_COUNT"){
            int count;
            cin>>count;
            node p=get_count(head,count);
            if(p!=NULL){
                cout<<p->id<<endl;
            }else{
                cout<<"None"<<endl;
            }
        }else if(s=="GET_PRICE"){
            int price;
            cin>>price;
            node p=get_price(head,price);
            if(p!=NULL){
                cout<<p->id<<endl;
            }else{
                cout<<"None"<<endl;
            }
        }else if(s=="UPDATE"){
            int id,count;
            cin>>id>>count;
            update(head,id,count);
        }
    }    
    duyet(head);
}
int main(){
    Task();
}
