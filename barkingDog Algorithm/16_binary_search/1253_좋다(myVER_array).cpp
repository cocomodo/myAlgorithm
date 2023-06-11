#include <bits/stdc++.h>
using namespace std;

int n;
int cnt;
int a[2'005];

void solve(int i) {
	for (int j = 0; j < n; j++) {
		if (j == i) continue;
		int x = a[i] - a[j];
		int idx = lower_bound(a, a+n, x) - a;
		while (idx < n && a[idx] == x) {
			if (idx != i && idx != j) {
				cnt++;
				return;
			}
			idx++;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n);
	for (int i = 0; i < n; i++) solve(i);
	cout << cnt;
}