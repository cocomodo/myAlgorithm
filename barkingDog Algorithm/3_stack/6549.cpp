#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int main(void)
{
    ios::sync_with_stdio(0); // C++의 표준 입력과 출력의 동기화를 끄는 함수 호출
    cin.tie(0);              // cin과 cout의 묶음을 풀어주는 함수 호출
    while (true)
    {
        int n;
        cin >> n;   // 히스토그램의 크기를 입력 받음
        if (n == 0) // 입력이 0인 경우 루프를 종료
            break;
        stack<pair<int, int>> S; // 높이와 인덱스를 저장하는 스택 선언
        long long ans = 0;       // 최대 넓이를 저장하는 변수 초기화
        for (int i = 0; i < n; i++)
        {
            int h;
            cin >> h;    // 히스토그램의 각 막대의 높이를 입력 받음
            int idx = i; // 현재 인덱스로 초기화
            while (!S.empty() && S.top().X >= h)
            {
                // 스택의 top에 있는 막대 높이가 현재 높이보다 크거나 같으면
                // 스택의 top에 있는 막대로부터 최대 넓이를 계산하고 갱신
                ans = max(ans, 1LL * (i - S.top().Y) * S.top().X);
                idx = S.top().Y; // 현재 인덱스를 스택의 top에 있는 막대의 인덱스로 갱신
                S.pop();         // 스택에서 top에 있는 막대를 제거
            }
            S.push({h, idx}); // 현재 막대를 스택에 추가하고 인덱스를 저장
        }
        while (!S.empty())
        {
            // 스택에 남아있는 막대들로부터 최대 넓이를 계산하고 갱신
            ans = max(ans, 1LL * (n - S.top().Y) * S.top().X);
            S.pop(); // 스택에서 막대를 제거
        }
        cout << ans << '\n'; // 최대 넓이 출력
    }
}

/*
스택에는 (높이, 해당 높이가 최초로 등장한 위치)가 저장된다. 기본적으로 스택은
높이에 대한 monotone stack으로 관리된다. 스택에서 pop이 발생할 때 마다 현재
스택의 top을 가지고 만들 수 있는 직사각형의 넓이를 계산할 수 있다.
long long으로의 형변환을 편하게 처리하기 위해 1LL을 매번 곱했고, 그냥 스택
자체를 pair<long long, long long>으로 선언해도 크게 상관 없다.
*/