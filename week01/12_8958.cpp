#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int total = 0;
    while (n--)
    {
        total = 0;
        string s;
        cin >> s;
        int x = 1;
        for (auto c : s)
        {
            if (c == 'O')
            {
                total += x;
                x++;
            }
            else
                x = 1;
        }
        cout << total << "\n";
    }
}