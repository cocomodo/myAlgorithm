#include <bits/stdc++.h>
using namespace std;

int hansu(int n)
{
    int cnt = 0;
    if (n < 100)
    {
        return n;
    }
    else
    {
        cnt = 99;
        for (int i = 100; i <= n; i++)
        {
            int a = i / 100;
            int b = (i / 10) % 10;
            int c = i % 10;

            if (2 * b == a + c)
                cnt++;
        }
    }
    return cnt;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = hansu(n);
    cout << ans;
}