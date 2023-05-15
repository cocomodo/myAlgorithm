#include <bits/stdc++.h>
using namespace std;

int d[505][505];
int p[505][505];

int main() {
	ios::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cin >> d[i][j];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 0)
				p[i][j] = p[i - 1][j] + d[i][j];
			else if (j == i)
				p[i][j] = p[i - 1][j - 1] + d[i][j];
			else //가운데에 있는 경우
				p[i][j] = max(p[i - 1][j - 1], p[i - 1][j]) + d[i][j];
		}
	}
	int ans = 0;
	for (int j = 1; j <= n; j++) {
		ans = max(ans, p[n][j]);
	}
	cout << ans;
}

/*
d[i]=max(d[i-1](왼쪽),d[i-1](오른쪽))+a[i] 형태로 보여짐.
만약 j=0이면 무조건 윗 항에서 j=0일때를 선택, 만약 j=i이면 무조건
윗 항에서 j=i-1 선택
둘다 아니라면 j=(현재 차수 -1) or (현재차수) 중에서 선택.
*/