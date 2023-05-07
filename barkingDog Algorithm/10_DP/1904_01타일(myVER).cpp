#include <bits/stdc++.h>
using namespace std;

int n;
int d[1'000'005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> n;

	d[1] = 1;
	d[2] = 2;

	for (int i = 3; i <= 1'000'000; i++)
		d[i] = (d[i - 1] + d[i - 2]) % 15746;
	cout << d[n] % 15746;
}