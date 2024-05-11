#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for (auto i = a ; i < b ;i++)
#define FR(i,a,b) for (auto i = a ; i < b ;i--)
#define fx(a) for (auto x:a)
#define w(n) while(n--)
#define gl(s) getline(cin,s)
#define c(n) cin>>n;
#define cY cout<<"Yes"<<endl
#define cN cout<<"No"<<endl
#define pb push_back
#define fi first
#define se second
#define ll long long
#define m 1000000007
#define e 0.000000001
long long t,n;
// F5 to run code

void ie() {
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    if (fopen("test.inp", "r")) {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
}
struct  Node {
    int  maLop;
    string  tenHocPhan;
    int  hocPhi;
    Node *next;
};
void insertLast(Node *&F, int maLop , string  tenHocPhan ,int  hocPhi)
{
	Node *new_node = new Node;
	new_node->maLop = maLop;
	new_node->tenHocPhan = tenHocPhan;
	new_node->hocPhi = hocPhi;
	new_node->next = NULL;
	if (F == NULL)
	{
		F = new_node;
	}
	else
	{
		Node *current = F;
		while (current->next)
		{
			current = current->next;
		}
		current->next = new_node;
	}
    n++;
}
Node* timLop(Node* F, int p) {
    Node* current = F;
    int p = 1;
    while (current != nullptr && p != p) {
        current = current->next;
        p++;
    }
    if (current == nullptr) {
        return nullptr; 
    }
    return current;
}
void deleteGp(Node*& F, int p) {
    Node* current = F;
    Node* previous = nullptr;

    while (current != nullptr) {
        if (current->hocPhi > p) {
            Node* temp = current;

            if (previous == nullptr) {
                F = current->next;
            } else {
                previous->next = current->next;
            }

            current = current->next;
            delete temp;
        } else {
            previous = current;
            current = current->next;
        }
    }
}
void Reverse(Node*& F) {
    Node* prev = nullptr;
    Node* current = F;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    F = prev;
}
int sum(Node* F) {
    int total = 0;
    Node* current = F;

    while (current != nullptr) {
        total += current->hocPhi;
        current = current->next;
    }

    return total;
}
void source() {
    Node *lophp = NULL;
    int t;
    while(cin>>t){
        if(t==1){
            int k;
			cin>>k;
			timLop(lophp,k);
        }else if (t==2){
			int z,l;
			string ten;
			cin>>z;
			cin.ignore();
			getline(cin,ten);
			cin>>l;
			insertLast(lophp,z,ten,l);
        }else if (t==3){
			int l;
			cin>>l;
			deleteGp(lophp,l);
        }else if (t==4){
			
        }else if (t==5){
			Reverse(lophp);
        }else if (t==6){
			cout<<sum(lophp)<<endl;
        }
        else 
            return;
    }
}
int main(){
    ie();
    source();
}