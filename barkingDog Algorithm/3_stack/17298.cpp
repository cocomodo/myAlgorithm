#include <bits/stdc++.h> // 필요한 헤더 파일들을 include

using namespace std;

int a[1'000'000];   // 입력으로 주어진 수열을 저장할 배열
int ans[1'000'000]; // 오큰수를 저장할 배열

int main(void)
{
    ios::sync_with_stdio(0); // 입출력 속도 향상
    cin.tie(0);              // 입출력 속도 향상

    int n;
    cin >> n; // 수열의 길이 입력

    for (int i = 0; i < n; i++)
        cin >> a[i]; // 수열 입력

    stack<int> s; // 스택을 이용하여 오큰수를 찾음
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= a[i])
            s.pop(); // 스택에서 현재 수보다 작거나 같은 수들을 pop
        if (s.empty())
            ans[i] = -1; // 스택이 비어있으면 오큰수가 없으므로 -1 저장
        else
            ans[i] = s.top(); // 스택의 top에 있는 수가 오큰수이므로 저장
        s.push(a[i]);         // 현재 수를 스택에 push
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << ' '; // 오큰수 출력

    return 0;
}
