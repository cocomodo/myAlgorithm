#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    while (n--)
    {
        int a;
        cin >> a;
        if (m > a)
            cout << a << " ";
    }
}