#include <bits/stdc++.h>
using namespace std;

int a[1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        a[i] = p;
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        cout << a[i] << "\n";
}