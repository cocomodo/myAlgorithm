#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cnt = 0;
    string s;
    getline(cin, s);
    for (auto c : s)
    {
        if (c == ' ')
        {
            cnt++;
        }
    }
    auto it = rbegin(s);

    if (s[0] == ' ' && *it == ' ')
        cout << cnt - 1;
    else if (s[0] != ' ' && *it != ' ')
        cout << cnt + 1;
    else
        cout << cnt;
}