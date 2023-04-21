#include <bits/stdc++.h>
using namespace std;

bool isprime(int a)
{
    if (a == 1)
        return 0;
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
            return 0;
    }
    return 1;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int cnt = 0;
    while (n--)
    {
        int a;
        cin >> a;
        cnt += isprime(a);
    }
    cout << cnt;
}