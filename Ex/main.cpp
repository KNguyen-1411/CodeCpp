#include <bits/stdc++.h>
using namespace std;
#define name "test"
#define fr(i,a,b) for (auto i = a ; i < b ;i++)
#define FR(i,a,b) for (auto i = a ; i < b ;i--)
#define fx(a) for (auto x:a)
#define w(n) while(n--)
#define gl(s) getline(cin,s)
#define c(n) cin>>n;
#define pb push_back
#define fi first
#define se second
#define ll long long
long long t,n;
// #define m 1000000007
// #define e 0.000000001
// F5 to run code
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
struct SinhVien{
    string msv;
    string hoten;
    string ten(string hoten){
        int i=hoten.length();
        for(;hoten[i]!=' ';i--);
        string ten=hoten.substr(i);
        return ten;
    }
    struct NgaySinh{
        int dd,mm,yy;
    };
    NgaySinh ns;
    int tuoi;
    size_t Tuoi(NgaySinh ns){
        return 2024-ns.yy;
    }
    float diem,diem1,diem2;
    SinhVien *next;
};
typedef struct SinhVien * sv;
sv crsv(string msv,string ht,int tuoi,float diem){
    sv p= new SinhVien;
    p->msv=msv;
    p->hoten=ht;
    p->tuoi=tuoi;
    p->diem=diem;
    p->next=NULL;
    return p;
}
size_t Size(auto head){
    size_t n = 0;
    while(head != NULL){
        n++;
        head=head->next;
    }
}
void Deletesv(SinhVien* &dssv, string msv) {
    sv p = dssv;
    sv truoc = nullptr,sau = dssv;
    if (p != nullptr && p->msv == msv) {
        dssv = p->next;
        delete p;
        return;
    }
    while (sau != nullptr) {
        if (sau->msv == msv) {
            truoc->next = sau->next;
            delete sau;
            return;
        }
        truoc = sau;
        sau = sau->next;
    }
    cout << "Không tìm thấy sinh viên có mã số " << msv << endl;
}
void inssv(sv &dssv){
    string a,b;
    int tuoi;
    float diem;
    cin>>a;
    cin.ignore();
    getline(cin,b);
    cin>>tuoi;
    cin>>diem;
    sv tmp=crsv(a,b,tuoi,diem);
    if(dssv==NULL){
        dssv=tmp;
    }else{
        tmp->next = dssv;
        dssv=tmp;
    }
}
//in ra
void printsv(sv head){
    const int WidthSTT = 5, Width = 30, WidthTuoi = 10, WidthDiem = 10;
    cout << endl;
    cout << left << setw(WidthSTT) << "| MSV";
    cout << left << setw(Width) << "| Ho Ten";
    cout << left << setw(WidthTuoi) << "| Tuoi";
    cout << left << setw(WidthDiem) << "| Diem    |" << endl;
    cout << setfill('-') << setw(WidthSTT + Width + WidthTuoi + WidthDiem + 2) << "" << setfill(' ') << endl;
    for (int i = 0; i < Size(head); ++i)
    {
        cout << "| " << left << setw(WidthSTT - 2) << head->msv;
        cout << "| " << left << setw(Width - 2) << head->hoten;
        cout << "| " << left << setw(WidthTuoi - 2) << head->tuoi;
        cout << "| " << left << setw(WidthDiem - 2) << head->diem << "|" << endl
             << endl;
        head = head->next;
    }
    // msv //hoten //Tuoi //diem
}
void nhap(sv &dssv){
    ifstream inputFile;
    inputFile.open("text .txt");
    if (inputFile.is_open()) {
        string line;
        getline(inputFile, line);
    } else {
        cout << "Không thể mở file." << endl;
    }
}
void thaotac(sv dssv){
    cout << "Danh sach thao tac:" << endl
         << "1 - In danh sach sv" << endl
         << "2 - Them" << endl
         << "3 - Sua" << endl
         << "4 - Xoa" << endl
         << "5 - Tim kiem" << endl
         << "6 - Sap xep" << endl
         << "7 - Sao luu" << endl
         << "8 - Thoat" << endl
         << "9 - Xoa man hinh" << endl
         << "Nhap lenh: " << endl;
    int n;
    cin>>n;
    switch (n)
    {
    case '1':
        printsv(dssv);
        break;
    case '2':
        inssv(dssv);
        break;
    case '3':
        break;
    case '4':
        break;
    case '5':
        break;
    case '6':
        break;
    case '7':
        break;
    case '8':
        break;
    case '9':
        break;
    default:
        thaotac(dssv);
        break;
    }
}
void Solve(){
    //khoi tao node
    sv dssv=NULL;

}
int main() {
    Task();
}
