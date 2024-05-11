#include <bits/stdc++.h>
using namespace std;
void Task() {
    ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
    if (fopen("test.inp", "r")) {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
}
int chuyendoidiem(char qbai) {
    if (qbai == '2') return 2;
    if (qbai == '3') return 3; 
    if (qbai == '4') return 4;
    if (qbai == '5') return 5;
    if (qbai == '6') return 6;
    if (qbai == '7') return 7;
    if (qbai == '8') return 8;
    if (qbai == '9') return 9;
    if (qbai == '1') return 10;
    if (qbai == 'J') return 11;
    if (qbai == 'Q') return 12;
    if (qbai == 'K') return 13;
    if (qbai == 'A') return 1;
    return 0; 
}

bool isSanh(vector<int> bai) {
    for (int i = 1; i < bai.size(); i++) {
        if (bai[i] != bai[i-1] + 1) {
            return false;
        }
    }
    return true;
}
int tinhdoi(int a[]) {
    int diem = 0;
    map<int, int> save;
    for (int i = 0; i < 13; i++) {
        save[a[i]]++;
    }
    for (auto& x : save) {
        if (x.second == 4) {
            diem += 3;
        } else if (x.second == 3) {
            diem += 2;
        } else if (x.second == 2) {
            diem += 1;
        }
    }
    return diem;
}
int main() {
    Task();
    int n, diem = 0;
    cin >> n;
    while (n--) {
        int a[13];
        string s;
        for (int i = 0; i < 13; i++) {
            cin >> s;
            a[i] = chuyendoidiem(s[0]);
        }
        int diem=0;
        diem+=tinhdoi(a);
        
        
        cout << diem << endl;
    }
}