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
typedef struct Node{
    int data;
    struct Node *next;
}SList;
//Hàm chèn một phần tử x và cuối danh sách.
void InsertLast(SList *& F, int x){
    Node *newnode= new Node;
    newnode->data=x;
    newnode->next=nullptr;
    if(F==nullptr) {
        F=newnode;
        return;
    }
    Node *p=F;
    while (p->next)
    {
        p=p->next;
    }
    p->next=newnode;
}
//Hàm chèn một phần tử x vào vị trí trước vị trí p trong danh sách.
void InsertBeforeP(SList *& F, int x, int p);

//Hàm xóa một phần tử ở vị trí p.
void Delete(SList *&F, int p);
//Hàm tính giá trị trung bình của các phần tử trong danh sách.
float Average(SList *F);
void Solve() {
    
}
int main() {
    Task();
}
