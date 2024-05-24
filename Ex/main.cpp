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
struct node {
    int i, c, p;
};

bool kt(node a, node b) {
    if(a.p == b.p) {
        return a.i < b.i;
    }
    return a.p > b.p;
}

void Solve() {
    int n;
    cin >> n;
    node a[n];
    long long sumhang = 0, sumgt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i].i >> a[i].c >> a[i].p;
        sumhang += a[i].c;
        sumgt += a[i].p * a[i].c;
    }
    sort(a, a + n, kt);
    cout << sumhang << endl << sumgt << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i].i;
        if (i != n - 1) cout << " ";
    }
}
int main(){
    Task();
}
