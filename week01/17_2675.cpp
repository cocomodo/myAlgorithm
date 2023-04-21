#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--)
    {
        int m;
        string s;
        cin >> m >> s;

        for (auto c : s)
        {
            for (int i = 0; i < m; i++)
                cout << c;
        }
        cout << "\n";
    }
}