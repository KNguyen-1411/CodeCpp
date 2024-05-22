#include <bits/stdc++.h>
using namespace std;
#define name "test"
#define fr(i, a, b) for (auto i = a; i < b; i++)
#define fx(a) for (auto x : a)
#define pb push_back
#define ll long long
long long t, n;
// #define m 1000000007
// #define e 0.000000001
void Solve();
void Task()
{
    clock_t begin = clock();
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(name ".inp", "r"))
    {
        freopen(name ".inp", "r", stdin);
        freopen(name ".out", "w", stdout);
    }
    Solve();
    cerr << "Time: " << (clock() - begin + 1.0) / CLOCKS_PER_SEC << "s";
}
struct Lop
{
    int maLop;
    string tenHocPhan;
    int hocPhi;
    Lop *next;
};
typedef Lop * lop;
lop cr(int m,string s,int h){
    lop node =new Lop;
    node->maLop=m;
    node->tenHocPhan=s;
    node->hocPhi=h;
    node->next=nullptr;
    return node;
}
int dem(lop F){
    int c=0;
    while (F!=nullptr)
    {
        c++;
        F=F->next;
    }
    return c;
}
// 1. Ham  tim  Lop co vi tri p trong  danh  sach
lop timLop(lop F, int p) {
    int n = dem(F);
    if (p < 1 || p > n || F == nullptr) {
        return nullptr;
    } else {
        lop tmp = F;
        for (int i = 1; i < p; i++) {
            tmp = tmp->next;
        }
        return tmp;
    }
}
// 2. Ham  chen  phan tu vao  cuoi  danh  sach
void  insertLast(lop &F, int maLop , string  tenHocPhan ,int  hocPhi){
    lop node=cr(maLop,tenHocPhan,hocPhi);
    if(F==nullptr){
        F=node;
    }else{
        lop p=F;
        while (p->next)
        {
            p=p->next;
        }
        p->next=node;
    }
}
// 3. Ham  xoa  cac  Lop co hoc  phi  cao  hon p
void  deleteGp(lop &F, int p){
    if(F==nullptr){
        return;
    }
    if(F->hocPhi>p){
        F=F->next;
    }else{
        lop tmp=F;
        while (tmp->next)
        {
            if(tmp->next->hocPhi>p){
                lop de=tmp->next;
                tmp->next=de->next;
            }else{
                tmp=tmp->next;
            }
        }
    }
}
// 4. Ham  sap  xep  danh  sach  Lop
void chen(lop& F, lop newNode) {
    if (F == nullptr || newNode->hocPhi < (F)->hocPhi) {
        newNode->next = F;
        F = newNode;
    } else if (newNode->hocPhi == (F)->hocPhi) {
        if (newNode->maLop < (F)->maLop) {
            newNode->next = F;
            F = newNode;
        } else {
            lop current = F;
            while (current->next != nullptr && (newNode->hocPhi > current->next->hocPhi || (newNode->hocPhi == current->next->hocPhi && newNode->maLop >= current->next->maLop)))
                current = current->next;
            newNode->next = current->next;
            current->next = newNode;
        }
    } else {
        lop current = F;
        while (current->next != nullptr && newNode->hocPhi > current->next->hocPhi)
            current = current->next;
        newNode->next = current->next;
        current->next = newNode;
    }
}
void  Sort(lop &F){
    if(F==nullptr||F->next==nullptr){
        return;
    }
    lop kq=nullptr;
    lop p=F;
    while (p != nullptr) {
        lop next = p->next;
        chen(kq, p);
        p = next;
    }
    F = kq;
}
// 5. Ham  dao  nguoc  danh  sach  Lop
void  Reverse(lop &F){
    lop prev = nullptr;
    lop curr = F;
    lop next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    F = prev;
}
// 6. Ham  tinh  hoc  phi
long  long  sum(Lop *F){
    ll s=0;
    while (F!=nullptr)
    {
        s+=F->hocPhi;
        F=F->next;
    }   
    return s;
}
void duyet(lop tmp){
    cout<<"begin"<<endl;
    while (tmp!=nullptr)
    {
        cout<<tmp->maLop<<" "<<tmp->tenHocPhan<<" "<<tmp->hocPhi<<endl;
        tmp=tmp->next;
    }
    cout<<"end"<<endl;
}
void Solve()
{
    lop F=nullptr;
    int n,x,y;
    string s;
    while(cin>>n){
        if(n==1){
            cin>>x;
            lop tmp=timLop(F,x);
            if(tmp==nullptr){
                cout<<"NOT FOUND"<<endl;
            }else{
                cout<<tmp->maLop<<" "<<tmp->tenHocPhan<<" "<<tmp->hocPhi<<endl;
            }
        }else if(n==2){
            cin>>x>>s>>y;
            insertLast(F,x,s,y);
        }else if(n==3){
            cin>>x;
            deleteGp(F,x);
        }else if(n==4){
            Sort(F);
        }else if(n==5){
            Reverse(F);
        }else if(n==6){
            cout<<sum(F)<<endl;
        }else{
            break;
        }
    }
    // duyet(F);
}
int main()
{
    Task();
}
