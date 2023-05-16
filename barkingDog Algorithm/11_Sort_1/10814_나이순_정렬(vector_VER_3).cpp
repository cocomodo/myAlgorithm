#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int, string> &a,const pair<int, string> &b) {
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	pair<int, string> p;
	vector<pair<int, string>> v;
	for (int i = 0; i < n; i++) {
		cin >> p.first >> p.second;
		v.push_back(p);
	}
	stable_sort(v.begin(), v.end(), compare);
	for (int i = 0; i < n; i++)
		cout << v[i].first << ' ' << v[i].second << '\n';
}