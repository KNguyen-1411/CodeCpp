#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a, b;
    cin >> a >> b;
    if ((a % b == 0) || (b % a == 0))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}
