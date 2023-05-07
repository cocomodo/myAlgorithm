#include <bits/stdc++.h>
using namespace std;

int t;
int a[3][100'005];
int d[3][100'005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 1; i <= 2; i++)
			for (int j = 1; j <= n; j++)
				cin >> a[i][j];
		d[1][0] = 0;
		d[2][0] = 0;
		d[1][1] = a[1][1];
		d[2][1] = a[2][1];

		for (int j = 2; j <= n; j++) {
			d[1][j] = max(d[2][j - 2], d[2][j - 1]) + a[1][j];
			d[2][j] = max(d[1][j - 2], d[1][j - 1]) + a[2][j];
		}
		cout << max(d[1][n], d[2][n]) << '\n';
	}
}

/*
나의 경우 dp문제는 1-indexed로 푸는것이 더 깔끔하다고 생각하고
마음에 들어서 이런 방법으로 1-indexed로 바꾸어주었다
처음의 풀이에서 vector로 설정해서 푸는 방법에 대해서는
지금 현재 이 풀이에 대해서 완벽하게 이해를 하고 난뒤에
이해하는것이 더 좋을것 같다. 

*/