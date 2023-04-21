#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int leng[4] = {x, y, h - y, w - x};
    sort(leng, leng + 4);

    cout << leng[0];
}