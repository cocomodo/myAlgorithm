#include <bits/stdc++.h>
using namespace std;

int a[1'000'005];
int n, m;

int binary(int target)
{
    int st = 0;
    int en = a[n - 1];
    int answer = 0;
    while (st <= en)
    {
        int mid = (st + en) / 2;
        long long total = 0;
        for (int i = 0; i < n; i++)
            if (a[i] > mid)
                total += a[i] - mid;
        if (total >= m)
        {
            answer = mid;
            st = mid + 1;
        }
        else
            en = mid - 1;
    }
    return answer;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);

    cout << binary(m) << "\n";
}