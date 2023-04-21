#include <bits/stdc++.h> // C++ 표준 라이브러리 헤더 파일들을 포함

using namespace std; // 표준 네임스페이스(std) 사용

#define X first  // first 매크로를 X로 정의
#define Y second // second 매크로를 Y로 정의

int main(void)
{
    ios::sync_with_stdio(0); // C++ 입출력 동기화를 끄기
    cin.tie(0);              // cin과 cout의 묶음을 풀기
    int n;                   // 높이의 개수를 저장하는 변수 n
    cin >> n;                // n을 입력 받음
    stack<pair<int, int>> S; // 높이와 높이 개수를 pair로 묶어 저장하는 스택 S
    long long ans = 0;       // 결과를 저장하는 변수 ans, long long 자료형으로 선언하여 범위를 확보함
    while (n--)
    {                // n번 반복하는 while 루프
        int h;       // 현재 높이를 저장하는 변수 h
        cin >> h;    // h를 입력 받음
        int cnt = 1; // 현재 높이와 동일한 높이의 개수를 저장하는 변수 cnt, 초기값은 1로 설정
        while (!S.empty() && S.top().X <= h)
        {                     // 스택이 비어있지 않고, 스택 top에 있는 높이가 현재 높이보다 작거나 같은 경우
            ans += S.top().Y; // 스택 top에 있는 높이의 개수를 ans에 더함
            if (S.top().X == h)
                cnt += S.top().Y; // 스택 top에 있는 높이가 현재 높이와 동일한 경우, cnt에 스택 top에 있는 높이의 개수를 더함
            S.pop();              // 스택 top을 pop함
        }
        if (!S.empty())
            ans++;        // 스택이 비어있지 않은 경우, ans에 1을 더함
        S.push({h, cnt}); // 현재 높이 h와 cnt를 pair로 묶어서 스택에 push함
    }
    cout << ans; // 결과인 ans를 출력함
}
