#include <bits/stdc++.h>
using namespace std;

int n;
int a[1005];
int d[1005];
int pre[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		d[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (a[j] < a[i] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
				pre[i] = j;
			}
		}
	}
	int maxI = 1;
	int maxD = d[1];
	for (int i = 2; i <= n; i++) {
		if (maxD < d[i]) {
			maxI = i;
			maxD = d[i];
		}
	}
	vector<int> ans;
	int cur = maxI;
	while (cur) {
		ans.push_back(a[cur]);
		cur = pre[cur];
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (auto c : ans) cout << c << ' ';
}