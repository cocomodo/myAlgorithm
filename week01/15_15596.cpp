#include <bits/stdc++.h>
using namespace std;

long long sum(std::vector<int> &a)
{

    long long ans = 0;
    for (auto c : a)
        ans += c;
    return ans;
}

vector<int> a = {1, 2, 3, 4, 5};
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << sum(a);
}