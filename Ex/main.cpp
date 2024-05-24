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
struct hp{
    string mhp;
    string ten;
    int st;
};
void Solve(){
    int n;
    cin>>n;
    cin.ignore();
    hp luu[n];

    //nhap
    string a,b;
    int x;
    for(int i=0;i<n;i++){
        getline(cin,a,',');
        getline(cin,b,',');
        cin>>x;
    }
}
int main(){
    Task();
}
