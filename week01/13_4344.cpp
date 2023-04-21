#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;
        int val[1000] = {};
        int total = 0;
        for (int i = 0; i < m; i++)
        {
            int p;
            cin >> p;
            val[i] = p;
            total += p;
        }
        int avgint = total / m;
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            if (avgint < val[i])
                cnt++;
        }
        double avgratio_double = ((double)cnt / (double)m) * 100;
        cout << fixed << setprecision(3);
        // double roundedNum = round(avgratio_double * pow(10, 3)) / pow(10, 3);
        // cout << roundedNum<<"\n";
        cout << avgratio_double << "%"
             << "\n";
    }
}