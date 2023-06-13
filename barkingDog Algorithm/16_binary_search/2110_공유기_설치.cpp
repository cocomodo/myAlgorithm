#include <bits/stdc++.h>
using namespace std;

int n, c;
int x[200002];

bool solve(int len){
  int idx = 0, cnt = 0;
    while(idx != n) {
      idx = lower_bound(x + idx, x + n, x[idx] + len) - x;
      cnt++;/*이게 결국 idx = 0일때, 판단을 한 뒤 다음 idx로 옮기고 cnt++을 해주었는데, 이 과정이 결국 a[0]에 공유기를 하나 설치 하는것과 똑같다. 
			  */
    }
  return cnt >= c;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> c;
  for(int i = 0; i < n; i++) cin >> x[i];
  sort(x, x + n);

  int st = 1, en = 1000000000;
  int mid;
  while(st < en) {
    mid = (st + en + 1)/2;
    if(solve(mid)) st = mid;
    else en = mid - 1;
  }
  cout << st;
}