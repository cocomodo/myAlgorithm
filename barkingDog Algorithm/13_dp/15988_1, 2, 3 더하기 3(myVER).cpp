#include <bits/stdc++.h>
using namespace std;

int n;
long long d[1'000'005];
long long mod = 1'000'000'009;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	for (int i = 4; i <= 1'000'000; i++) {
		d[i] = (d[i - 3] + d[i - 2] + d[i - 1]) % mod;
	}

	while (n--) {
		int t;
		cin >> t;
		cout << d[t] << '\n';
	}
}