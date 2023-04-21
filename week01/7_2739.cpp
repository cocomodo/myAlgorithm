#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < 9; i++)
    {
        cout << n << " * " << (i + 1) << " = " << n * (i + 1);
        cout << "\n";
    }
}