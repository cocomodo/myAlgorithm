#include <bits/stdc++.h>  // STL 헤더파일 포함

using namespace std;
long long d[101][10];  // 계단 수 개수를 저장할 배열

int main() {
  ios::sync_with_stdio(0);  // cin, cout 속도 향상
  cin.tie(0);

  int n;
  cin >> n;  // 계단 수의 길이를 입력받음

  for (int i = 1; i <= 9; ++i) d[1][i] = 1;  // 1자리 계단 수 초기화

  // 계단 수 개수 구하기
  for (int i = 2; i <= n; ++i) {
    for (int k = 0; k <= 9; ++k) {
      if (k != 0) d[i][k] += d[i - 1][k - 1];  // 한자리 낮은 수 계단 수 개수 더하기
      if (k != 9) d[i][k] += d[i - 1][k + 1];  // 한자리 높은 수 계단 수 개수 더하기
      d[i][k] %= 1000000000;  // 1,000,000,000으로 나눈 나머지 구하기
    }
  }

  long long ans = 0;  // 계단 수 개수의 합 초기화
  for (int i = 0; i <= 9; ++i) {
    ans += d[n][i];  // n자리 수에서 각 숫자로 끝나는 계단 수 개수를 모두 더하기
  }
  ans %= 1000000000;  // 1,000,000,000으로 나눈 나머지 구하기

  cout << ans;  // 계단 수 개수의 합 출력

  return 0;
}
