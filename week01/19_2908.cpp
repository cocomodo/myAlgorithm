#include <bits/stdc++.h>
using namespace std;

int reverse(int num)
{
    int x, y, z;
    z = num % 10;
    num /= 10;
    y = num % 10;
    num /= 10;
    x = num % 10;

    return z * 100 + y * 10 + x;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    int rA = reverse(a);
    int rB = reverse(b);
    cout << max(rA, rB);
}