#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for (auto i = a ; i <= b ;i++)
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
int t,n;
// F5 to run code
void ie() {
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    if (fopen("test.inp", "r")) {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
}
void source(){
    
    string s;
    while(gl(s)){
        string luu="";
        int sum = 0;
        for (char c : s) {
            if ((c>='0'&&c<='9')||(c=='-')) {
                luu += c;
            } else if (!luu.empty()) {
                sum += stoi(luu); 
                luu = "";
            }
        }

        if (!luu.empty()) {
            sum +=stoi(luu);  
        }
        cout<<sum<<endl;
    }
    
}
int main(){
    ie();
    source();
}