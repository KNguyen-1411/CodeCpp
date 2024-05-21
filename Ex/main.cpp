#include <bits/stdc++.h>
using namespace std;
#define namebt "test"
#define fr(i, a, b) for (auto i = a; i < b; i++)
#define fx(a) for (auto &x : a)
#define pb push_back
#define ll long long
long long t, n;
// #define m 1000000007
// #define e 0.000000001
void Solve();
void Task()
{
    clock_t begin = clock();
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen(namebt ".inp", "r"))
    {
        freopen(namebt ".inp", "r", stdin);
        freopen(namebt ".out", "w", stdout);
    }
    Solve();
    cerr << "Time: " << (clock() - begin + 1.0) / CLOCKS_PER_SEC << "s";
}
struct Node
{
    int data;
    struct Node *next;
};
typedef Node *node;
node cr(int n)
{
    node head = new Node;
    head->data = n;
    head->next = NULL;
    return head;
}
size_t dem(node head)
{
    size_t c = 0;
    while (head != NULL)
    {
        c++;
        head = head->next;
    }
    return c;
}
void insL(node &head, int n)
{
    node newnode = cr(n);
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        node p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = newnode;
    }
}
void insP(node &head, int n, int p)
{
    node newnode = cr(n);
    size_t k=dem(head);
    if (p < 1)
    {
        return;
    }
    else if (p == 1)
    {
        newnode->next = head;
        head = newnode;
    }
    else if (p > k)
    {
        insL(head, n);
    }
    else
    {
        node x = head;
        for (int i = 1; i <= p - 2; i++)
        {
            x = x->next;
        }
        newnode->next = x->next;
        x->next = newnode;
    }
}
void deF(node &head)
{
    node temp = head;
    head = head->next;
    delete temp;
}
void deP(node &head, int x)
{
    node p = head;
    if (x == 1)
    {
        deF(head);
        return;
    }
    for (int i = 1; i <= x - 2; i++)
    {
        p = p->next;
    }
    node temp = p->next;
    p->next = temp->next;
}
float Average(node head)
{
    float sum = 0, cnt = dem(head);
    while (head != NULL)
    {
        sum += (float)head->data;
        head = head->next;
    }
    return sum / (float)cnt;
}
void duyet(node head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
void Solve()
{
    node head = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        insL(head, data);
    }
    char temp;
    while (cin >> temp)
    {
        if (temp == 'i')
        {
            int x, p;
            cin >> x >> p;
            insP(head, x, p);
        }
        else if (temp == 'd')
        {
            int p;
            cin >> p;
            deP(head, p);
        }
        else if (temp == 'a')
        {
            cout << fixed << setprecision(4) << (float)Average(head) << '\n';
        }
        else
        {
            break;
        }
    }
}
int main()
{
    Task();
}
