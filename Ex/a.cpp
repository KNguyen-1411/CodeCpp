#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
using namespace std;
struct DiemThi {
    string masv;
    string mamh;
    float diem;
};

float calculateAvg(vector<DiemThi> diemList, string masv) {
    float sum = 0;
    int count = 0;
    for (DiemThi diem : diemList) {
        if (diem.masv == masv) {
            sum += diem.diem;
            count++;
        }
    }
    if (count == 0) return 0.0;
    return sum / count;
}

bool ktdiem(DiemThi a, DiemThi b) {
    return a.diem > b.diem;
}

void display(vector<DiemThi> diemList) {
    vector<DiemThi> s = diemList;
    sort(s.begin(), s.end(), ktdiem);
    for (DiemThi diem : s) {
        cout << diem.masv << ", " << diem.mamh << ", " ;
        if(diem.diem==(int)diem.diem){
            cout << fixed << setprecision(0) << diem.diem << endl;
        }else{
            cout << fixed << setprecision(1) << diem.diem << endl;
        }
    }
}

void sfind(vector<DiemThi> diemList, string mamh) {
    vector<DiemThi> foundList;
    for (DiemThi diem : diemList) {
        if (diem.mamh == mamh) {
            foundList.push_back(diem);
        }
    }
    if (foundList.empty()) {
        cout << "Not found" << endl;
    } else {
        display(foundList);
    }
}

int main() {
    if (fopen("test.inp", "r")) {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
    int n;
    cin >> n;
    cin.ignore();
    vector<DiemThi> diemlist(n);
    for (int i = 0; i < n; i++) {
        getline(cin, diemlist[i].masv);
        getline(cin, diemlist[i].mamh);
        cin >> diemlist[i].diem;
        cin.ignore();
    }
    string command;
    while (cin >> command) {
        if (command == "display") {
            display(diemlist);
        } else if (command == "avg") {
            string masv;
            cin >> masv;
            float avg = calculateAvg(diemlist, masv);
            if(avg==(int)avg){
            cout << fixed << setprecision(0) << avg << endl;
            }else{
                cout << fixed << setprecision(1) << avg << endl;
            }
        } else if (command == "find") {
            string mamh;
            cin >> mamh;
            sfind(diemlist, mamh);
        } else {
            break;
        }
    }
    return 0;
}