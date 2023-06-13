#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
int a[4'005];
int b[4'005];
int c[4'005];
int d[4'005];
vector<int> sums;
ll ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sums.push_back(a[i] + b[j]);
		}
	}
	sort(sums.begin(), sums.end());
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			auto ub = upper_bound(sums.begin(), sums.end(), -c[i] - d[j]);
			auto lb = lower_bound(sums.begin(), sums.end(), -c[i] - d[j]);
			int cnt = ub - lb;
			ans += cnt;
		}
	}
	cout << ans;
}
/*
기존에 
ll a[4'005];
ll b[4'005];
ll c[4'005];
ll d[4'005];
vector<ll> sums;
ll ans;
...
ll cnt=ub-lb; 로 작성한 코드를 제출했을때, 시간초과가 발생했다.
캐시 힛 레이트를 높여서 시간을 단축시키는 아이디어에 대해서 듣게되었고
type설정을 크게하면 메모리 페이지를 넘어가는 경우들이 발생하면서
캐시에서 찾지 못하고 메모리에서 다시 찾는 경우들이 발생할 수 있을것 같다는
생각이 들어서 코드를 이렇게 수정하고 시간내로 통과하였다. 
*/
