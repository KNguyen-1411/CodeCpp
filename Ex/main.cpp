#include <bits/stdc++.h>
using namespace std;
#define name "test"
#define fr(i,a,b) for (auto i = a ; i < b ;i++)
#define fx(a) for (auto x:a)
#define pb push_back
#define ll long long
long long t,n;
//#define m 1000000007
//#define e 0.000000001
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
int ss(string a,string b,int t){
    int dem=0;
    for(int i=0;i<t;i++){
        if(a[i]!=b[i]) dem++;
    }
    return dem;
}
void kt(vector<string> luus,int n,int t){
    for(int i=0;i<n;i++){
        int maxx=0;
        string s=luus[i];
        for(int j=0;j<n;j++){
            if(i!=j){
                int a=ss(s,luus[j],t);
                if(maxx<a){
                    maxx=a;
                }
            }
        }
        cout<<maxx<<endl;
    }
}
void Solve() {
    
    // int n,t;
    // cin>>t>>n;
    // vector <string> luus;
    // for(int i=0;i<n;i++){
    //     string s;
    //     cin>>s;
    //     luus.push_back(s);
    // }
    // kt(luus,n,t);
    int n, t;
    cin >> t >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<int> maxDiffs(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int diff = 0;
            for (int k = 0; k < t; k++) {
                if (grid[i][k] != grid[j][k]) {
                    diff++;
                }
            }
            maxDiffs[i] = max(maxDiffs[i], diff);
            maxDiffs[j] = max(maxDiffs[j], diff);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << maxDiffs[i] << endl;
    }
}
int main() {
    Task();
}
