#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int max = 0;
    int maxidx = 0;
    for (int i = 1; i <= 9; i++)
    {
        int a;
        cin >> a;
        if (a > max)
        {
            max = a;
            maxidx = i;
        }
    }
    cout << max << "\n"
         << maxidx;
}