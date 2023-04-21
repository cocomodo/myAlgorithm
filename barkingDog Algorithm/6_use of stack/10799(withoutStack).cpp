#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    ll ans = 0;
    int cnt = 0; // 막대의 개수를 저장할 변수

    cin >> s;
    int sz = s.length();
    for (int i = 0; i < sz; i++) {
        if (s[i] == '(')
            cnt++; // 막대의 시작일 경우 cnt 증가
        else { // s[i] == ')'인 경우
            cnt--; // 막대의 끝일 경우 cnt 감소
            if (s[i - 1] == '(')
                ans += cnt; // 레이저일 경우 막대의 개수만큼 ans에 추가
            else
                ans++; // 막대의 끝일 경우 막대 1개가 절단된 것과 동일한 상황이므로 ans에 1 추가
        }
    }

    cout << ans << "\n";
    return 0;
}
