#include <bits/stdc++.h>
using namespace std;

pair<int, int> p[100'005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i].second >> p[i].first;
	sort(p, p + n);
	for (int i = 0; i < n; i++)
		cout << p[i].second << ' ' << p[i].first << '\n';
}