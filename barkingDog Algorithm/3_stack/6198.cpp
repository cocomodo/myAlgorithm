#include <bits/stdc++.h> // 필요한 헤더 파일들을 include

using namespace std;

#define ll long long // long long 자료형을 단축어로 사용

stack<int> s; // 건물의 높이 정보를 저장할 스택
int n;        // 건물의 개수
ll ans;       // 보이는 건물의 개수를 저장할 변수

int main()
{
    ios_base::sync_with_stdio(0); // 입출력 속도 향상
    cin.tie(0);                   // 입출력 속도 향상

    cin >> n; // 건물의 개수 입력

    ll h;
    while (n--)
    {
        cin >> h; // 건물의 높이 정보 입력
        while (!s.empty() && s.top() <= h)
            s.pop();     // 스택에서 현재 건물보다 낮은 건물들을 pop
        ans += s.size(); // 스택의 크기를 더하여 보이는 건물의 개수 누적
        s.push(h);       // 현재 건물의 높이 정보를 스택에 저장
    }

    cout << ans; // 보이는 건물의 개수 출력

    return 0;
}