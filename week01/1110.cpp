#include <bits/stdc++.h>
using namespace std;

int m;
int cnt = 0;
int cycle(int n)
{
    if (n == 0)
    {
        cout << 1;
        return 0;
    }
    int y = (n % 10) * 10 + ((n / 10 + n % 10)) % 10;
    cnt++;
    if (m == y)
    {
        cout << cnt << "\n";
        return 0;
    }
    cycle(y);
    return 0;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    m = n;
    cycle(n);
}