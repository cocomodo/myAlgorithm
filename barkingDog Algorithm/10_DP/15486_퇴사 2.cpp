#include <bits/stdc++.h>
using namespace std;

int n;
int t[1'500'005];
int p[1'500'005];
int d[1'500'005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> t[i] >> p[i];
	for (int i = n; i >= 1; i--) {
		if (i + t[i] - 1 <= n) d[i] = max(d[i + t[i]] + p[i], d[i + 1]);
		else d[i] = d[i + 1];
	}
	/*for (int i = 1; i <= n; i++)
		cout << d[i] << ' ';*/
	cout << *max_element(d + 1, d + 1 + n);
}