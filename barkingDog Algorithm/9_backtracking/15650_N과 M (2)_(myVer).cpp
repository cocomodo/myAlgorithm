#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		v.push_back(0);
	for (int i = 0; i < n-m; i++)
		v.push_back(1);
	do {
		for (int i = 0; i < n; i++) {
			if (v[i] == 0)
				cout << i + 1 << ' ';
		}
		cout << '\n';
	} while (next_permutation(v.begin(), v.begin()+n));
}