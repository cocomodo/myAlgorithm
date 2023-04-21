#include <bits/stdc++.h>
using namespace std;
int trees[1'000'005];
int main(void)
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> trees[i];
    }
    sort(trees, trees + n);

    int left = 0;
    int right = trees[n - 1];
    int answer = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        long long total = 0;
        for (int i = 0; i < n; i++)
        {
            if (trees[i] > mid)
            {
                total += (trees[i] - mid);
            }
        }
        if (total >= m)
        {
            answer = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    cout << answer << "\n";
}