#include <bits/stdc++.h>
using namespace std;

int n;
int a[100'005];
int d[100'005];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
		d[i] = max(a[i], d[i - 1] + a[i]);
	cout << *max_element(d + 1, d + 1 + n);
}