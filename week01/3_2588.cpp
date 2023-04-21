#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    int bb = b;
    int c, d, e, f;
    c = a * (bb % 10);
    bb = bb / 10;
    d = a * (bb % 10);
    bb = bb / 10;
    e = a * (bb % 10);
    f = a * b;
    cout << c << "\n";
    cout << d << "\n";
    cout << e << "\n";
    cout << f << "\n";
}