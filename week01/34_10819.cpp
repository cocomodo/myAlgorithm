#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int max_value = -1;
    do
    {
        int sum = 0;
        for (int i = 1; i < n; ++i)
        {
            sum += abs(v[i] - v[i - 1]);
        }
        max_value = max(max_value, sum);
    } while (next_permutation(v.begin(), v.end()));
    cout << max_value << "\n";
}