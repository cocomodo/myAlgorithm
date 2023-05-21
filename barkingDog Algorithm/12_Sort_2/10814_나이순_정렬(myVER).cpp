#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); 
	int n;
	cin >> n;
	vector<pair<int, string>> v;
	for (int i = 0; i < n; i++) {
		int a = 0;
		string st;
		cin >> a >> st;
		v.push_back({ a,st });
	}
	stable_sort(v.begin(), v.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
		return a.first < b.first;
		});
	for (auto c : v) {
		cout << c.first << ' ' << c.second << '\n';
	}
}