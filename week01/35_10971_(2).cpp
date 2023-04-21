#include <bits/stdc++.h>
using namespace std;

bool visited[10] = {};
int ans = 987654321, n, mapmap[10][10] = {};

void dfs(int init, int s, int c, int sum)
{
    if (c == n)
    {
        if (mapmap[s][init])
            ans = min(ans, sum + mapmap[s][init]);
        return;
    }
    for (int i = 0; i < n; i++)
        if (visited[i] == false && mapmap[s][i] != 0)
        {
            visited[i] = true;
            dfs(init, i, c + 1, sum + mapmap[s][i]);
            visited[i] = false;
        }
    return;
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mapmap[i][j];
    for (int i = 0; i < n; i++)
    {
        visited[i] = true;
        dfs(i, i, 1, 0);
        visited[i] = false;
    }
    cout << ans;
}