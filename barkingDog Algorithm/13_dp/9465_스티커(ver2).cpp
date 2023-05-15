#include <bits/stdc++.h>
using namespace std;

int arr[2][100'005];
int d[2][100'005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	int n;
	cin >> t;

	while (t--) {
		cin >> n;
		for (int i = 0; i < 2; i++)
			for (int j = 1; j < n + 1; j++) 
				cin >> arr[i][j];
		
		d[0][0] = 0;
		d[1][0] = 0;
		d[0][1] = arr[0][1];
		d[1][1] = arr[1][1];
		
		for (int j = 2; j < n + 1; j++) {
			d[0][j] = max(d[1][j - 2], d[1][j - 1]) + arr[0][j];
			d[1][j] = max(d[0][j - 2], d[0][j - 1]) + arr[1][j];
		}
		cout << max(d[0][n], d[1][n]) << '\n';
	}

}