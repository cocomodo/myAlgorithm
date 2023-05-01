#include <bits/stdc++.h>
using namespace std;

int n;
int t[20];
int p[20];
int d[20];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
		d[i] = p[i];
	}
	for(int i=1; i<=n; i++)
		for (int j = 1; j <= i; j++) {
			if (t[i] - 1 + i > n) {
				d[i] = 0;
				continue;
			}
			if (t[j] - 1 + j < i) d[i] = max(d[i], d[j] + p[i]);
		}

	/*for (int i = 1; i <= n; i++)
		cout << d[i] << ' ';*/
	cout << *max_element(d + 1, d + 1 + n);
}