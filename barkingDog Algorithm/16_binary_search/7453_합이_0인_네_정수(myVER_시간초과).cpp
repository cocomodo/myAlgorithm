#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
ll a[4'005];
ll b[4'005];
ll c[4'005];
ll d[4'005];
vector<ll> sums;
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
			ll cnt = ub - lb;
			ans += cnt;
		}
	}
	cout << ans;
}
/*
A( -45 , -41, -36, -36, 26, -32)
B(22 -27, 53, 30, -38, -54)
C(42,56 , -37, -75, -10, -6)
D(-16, 30 , 77, -46, 62, 45)
*/
/*
a+b=-d-c;
a+b는 2중 for문으로 계산해서 vector에 넣고, 백터의 원소들 중에서 -d-c
와 같은 것을 찾자. 
*/