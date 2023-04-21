#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int m = 1;
    while (n--)
    {
        for (int i = 0; i < m; i++)
            cout << "*";
        m++;
        cout << "\n";
    }
}