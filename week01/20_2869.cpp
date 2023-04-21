#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    double a, b, v;
    cin >> a >> b >> v;
    if (a == v)
        cout << 1;
    else
    {
        double cnt = ceil((v - a) / (a - b));
        cout << int(cnt + 1);
    }
}