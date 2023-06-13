#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
int a[4'005]; //long long 
int b[4'005];
int c[4'005];
int d[4'005];
vector<int> sumsAB;
vector<int> sumsCD;
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
			int cnt = ub - lb;
			ans += cnt;
		
	}
	cout << ans;
}