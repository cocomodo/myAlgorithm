#include <bits/stdc++.h>
using namespace std;

// 전역 변수 선언
int n, m;
int arr[10];    // m개의 수열을 저장할 배열
bool isused[10];    // 수를 사용했는지 저장할 배열

// 재귀 함수 정의
void func(int k) {
    // m개의 수열을 모두 선택한 경우
    if (k == m) {
        // 배열에 저장된 수열 출력
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';    // 줄바꿈
        return;    // 함수 종료
    }
    // 1부터 n까지의 수 중 사용하지 않은 수를 선택
    for (int i = 1; i <= n; i++) {
        if (!isused[i]) {
            arr[k] = i;    // 수열에 추가
            isused[i] = 1;    // 수를 사용한 것으로 표시
            func(k + 1);    // 다음 자리 수 선택
            isused[i] = 0;    // 재귀 종료 후, 사용하지 않은 것으로 표시
        }
    }
}

// main 함수 정의
int main() {
    ios::sync_with_stdio(0);    // 입출력 속도 향상
    cin.tie(0);

    // 입력 받기
    cin >> n >> m;

    // 함수 호출
    func(0);

    return 0;
}