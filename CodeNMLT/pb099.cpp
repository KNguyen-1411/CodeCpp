#include <bits/stdc++.h>
using namespace std;
int A(long long m, long long n)
{
    if (m == 0)
    {
        return n + 1;
    }
    else if ((m > 0) && (n == 0))
    {
        return A(m - 1, 1);
    }
    else
    {
        return A(m - 1, A(m, n - 1));
    }
}
int main()
{
    long long m, n;
    cin >> m >> n;
    cout << A(m, n);
    return 0;
}