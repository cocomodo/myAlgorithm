#include <bits/stdc++.h>
using namespace std;

int n, d, k, c;
int a[30001 * 2];
int chk[3001];
int ans;
int mxans;

void eat(int sushi) { //먹는 과정
  if (chk[sushi] == 0) {
    ans++;
    mxans = max(mxans, ans);
  }
  chk[sushi]++;
}

void overeat(int sushi) { //뱉는 과정
  chk[sushi]--;
  if (chk[sushi] == 0) ans--;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> d >> k >> c;
  chk[c]++;
  ans = 1;
  mxans = 1;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[n + i] = a[i];
  }

  for (int i = 0; i < n * 2; ++i) {
    if (i >= k) {
       overeat(a[i - k]);
    }
    eat(a[i]);
  }
  cout << mxans;

  return 0;
}