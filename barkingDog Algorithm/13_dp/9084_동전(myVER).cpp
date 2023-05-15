#include <bits/stdc++.h>
using namespace std;

int t;
int a[25];
int d[10'005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		
		int m;
		cin >> m; //만들어야 할 금액, 동전 1 문제에서 k에 해당
		d[0] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = a[i]; j <= m; j++) {
				d[j] += d[j - a[i]];
			}
		}
		cout << d[m] << '\n';

		fill(d + 1, d + 1 + m, 0);
	}
}