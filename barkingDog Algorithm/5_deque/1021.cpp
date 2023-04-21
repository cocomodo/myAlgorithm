#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m; // n: 덱의 크기, m: 뽑아내려는 수의 개수
    deque<int> DQ; // int형 덱 DQ 생성
    for (int i = 1; i <= n; i++)
        DQ.push_back(i); // 덱에 1부터 n까지의 수를 넣음
    int ans = 0;         // 결과값을 저장할 변수 ans 초기화

    while (m--)
    { // 뽑아내려는 수의 개수만큼 반복
        int t;
        cin >> t;                                             // 뽑아내려는 수를 입력받음
        int idx = find(DQ.begin(), DQ.end(), t) - DQ.begin(); // idx : t가 있는 위치
        // 입력받은 수가 덱에서 몇 번째에 위치하는지를 찾아서 idx에 저장
        // find 함수는 해당 요소를 찾으면 해당 요소를 가리키는 iterator를 반환하므로,
        // DQ.begin()에서 해당 iterator를 빼주고 DQ.begin()의 위치를 더해주어
        // 해당 요소의 인덱스를 얻어냄

        while (DQ.front() != t)
        {
            // 덱의 맨 앞 요소가 뽑아내려는 수가 될 때까지 반복
            if (idx < DQ.size() - idx)
            {
                // 만약 뽑아내려는 수의 인덱스가 덱의 크기의 절반보다 작다면
                DQ.push_back(DQ.front());
                // 덱의 맨 앞 요소를 덱의 뒤로 이동
                DQ.pop_front();
                // 덱의 맨 앞 요소를 삭제하여 이동한 것으로 처리
            }
            else
            {
                // 뽑아내려는 수의 인덱스가 덱의 크기의 절반보다 크다면
                DQ.push_front(DQ.back());
                // 덱의 맨 뒤 요소를 덱의 앞으로 이동
                DQ.pop_back();
                // 덱의 맨 뒤 요소를 삭제하여 이동한 것으로 처리
            }
            ans++; // 이동 횟수 증가
        }
        DQ.pop_front();
        // 뽑아낸 수를 덱에서 제거하여 덱을 업데이트
    }
    cout << ans; // 결과값 출력
}

/*
21번째 줄에서, 지금은 idx가 항상 DQ.size()보다 작아서 문제가 없지만
DQ.size()는 unsigned int(or unsigned long long)이기
때문에 만약 idx가 DQ.size()보다 컸다면 overflow가 발생해
의도한대로 동작하지 않을 수 있음을 인지해야 함. 그래서 size()로
받아온 값에 대해서는 안전하게 (int)DQ.size() 로 항상 형변환을
하는 것도 괜찮음.
*/