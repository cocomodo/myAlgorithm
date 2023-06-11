#include <bits/stdc++.h>
using namespace std;

int n;
int a[100'005];
int ans = 2 * 1e8 + 1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	int st = 0;
	int en = n - 1;
	while (st < en) {
		int mid = (st + en) / 2;
		int sum = a[st] + a[en];
		if (abs(ans) > abs(sum)) {
			ans = sum;
		}
		if (sum > 0)
			en--;
		else
			st++;
	}
	cout << ans;
}