#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
ll a[4'005]; //long long 
ll b[4'005];
ll c[4'005];
ll d[4'005];
vector<ll> sumsAB;
vector<ll> sumsCD;
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
			sumsAB.push_back(a[i] + b[j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sumsCD.push_back(c[i] + d[j]);
		}
	}

	sort(sumsAB.begin(), sumsAB.end());
	sort(sumsCD.begin(), sumsCD.end());
	for(int i=0; i<n*n;i++){
			auto ub = upper_bound(sumsAB.begin(), sumsAB.end(), -sumsCD[i]);
			auto lb = lower_bound(sumsAB.begin(), sumsAB.end(), -sumsCD[i]);
			ll cnt = ub - lb;
			ans += cnt;
		
	}
	cout << ans;
}
// 결과: 메모리 329960 KB , 시간 4100 ms;
