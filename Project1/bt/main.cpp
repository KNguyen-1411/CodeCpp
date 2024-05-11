#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
typedef long long ll;
void Task() {
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
}
void Solve() {
    int a,b,n;
    cin>>a>>b>>n;
    if(n==1){
        if(a==b){
            cout<<a+b+1+(a-1)<<endl;
        }else{
            if(a%b==0){
                cout<<a+b+1+(min(a,b)-1)<<endl;
            }else{
                cout<<a+b+1+(min(a,b)-1)<<endl;
            }
        }
    }
}
int main() {
    Task();
    Solve();
}
