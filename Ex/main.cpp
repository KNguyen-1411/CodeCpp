#include <bits/stdc++.h>
using namespace std;
#define name "test"
#define fr(i, a, b) for (auto i = a; i < b; i++)
#define FR(i, a, b) for (auto i = a; i < b; i--)
#define fx(a) for (auto x : a)
#define w(n) while (n--)
#define gl(s) getline(cin, s)
#define c(n) cin >> n;
#define pb push_back
#define fi first
#define se second
#define ll long long
// #define m 1000000007
// #define e 0.000000001
long long t, n;
// F5 to run code
void Solve();
void Task(){
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
int binarySearch(int a[],int n,int x){
    int left = 0;
    int right = n-1;
    while(left<=right){
        int mid = (left+right)/2;
        if(a[mid]==x){
            return mid;
        }
        else if(a[mid]<x){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return -1;
}
double DetMatrix(double matrix[][100], int n) {
    if (n == 1) {
        return matrix[0][0];
    }
    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }
    double det = 0;
    for (int i = 0; i < n; i++) {
        double subMatrix[100][100];
        for (int j = 1; j < n; j++) {
            for (int k = 0; k < i; k++) {
                subMatrix[j - 1][k] = matrix[j][k];
            }
            for (int k = i + 1; k < n; k++) {
                subMatrix[j - 1][k - 1] = matrix[j][k];
            }
        }
        det += (i % 2 == 0 ? 1 : -1) * matrix[0][i] * DetMatrix(subMatrix, n - 1);
    }
    return det;
}
int ss(string s1,string s2) {
    string kq;
    for (size_t i = 0; i < s1.length(); i++) {
        kq += (s1[i] != s2[i]) ? '1' : '0';
    }
    return bitset<64>(kq).count();
}
void ssx(){
    int n,t;
    cin>>t>>n;
    vector<string>luus(n);
    fr(i,0,n) cin>>luus[i];
    fr(i,0,n){
        int ma=0;
        fr(j,0,n){
            if(i!=j){
                int a=ss(luus[i],luus[j]);
                ma=max(ma,a);
            }
        }
        cout<<ma<<endl;
    }
}
class Node{
public:
    int data;
    Node* next;
    Node(int n){
        this->data=data;
        this->next=NULL;
    }
};
void Solve(){
    
}
int main(){
    Task(); 
}
