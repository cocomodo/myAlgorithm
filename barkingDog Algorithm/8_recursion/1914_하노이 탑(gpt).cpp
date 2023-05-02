#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void move(int n, int start, int end) {
    if (n == 1) {
        cout << start << ' ' << end << '\n';
        return;
    }
    move(n - 1, start, 6 - start - end); // 1번 기둥에 있는 n-1개의 원판을 3번 기둥으로 옮긴다.
    cout << start << ' ' << end << '\n'; // n번 원판을 2번 기둥에서 3번 기둥으로 옮긴다.
    move(n - 1, 6 - start - end, end); // 3번 기둥에 있는 n-1개의 원판을 2번 기둥으로 옮긴다.
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    ll cnt = 1;
    for (int i = 0; i < n; i++) {
        cnt *= 2;
    }
    cnt--;
    cout << cnt << '\n';
    if (n <= 20) {
        move(n, 1, 3);
    }
    return 0;
}
