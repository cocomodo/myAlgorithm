#include <bits/stdc++.h>
using namespace std;

int fac(int n)
{
    if (n == 0)
        return 1;
    return fac(n - 1) * n;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int ans = 0;
    ans = fac(n);
    cout << ans;
}