#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[15];

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int ans = 0;
  cin >> n >> k;
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = n-1; i >= 0; i--){
    ans += k / a[i]; //어차피 a[i]>k인 경우는 이 갑싱 0이기 때문에 정답에는 영향을 미치지 않는다.
    k %= a[i];
  }
  cout << ans;
}