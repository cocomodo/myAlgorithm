#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end());
	for (auto c : v)
		cout << c.first << ' ' << c.second << '\n';
}