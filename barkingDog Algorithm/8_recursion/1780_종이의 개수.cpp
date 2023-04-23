#include <bits/stdc++.h>
using namespace std;

int n;
int paper[2200][2200];//3^7= 2187
int cnt[3];//-1,0,1로 채워진 종이 갯수

//해당 종이 내부에 같은 숫자로만 채워져있는지 확인하는 함수
bool check(int x, int y, int n) {
	for (int i = x; i <= x + n-1; i++)
		for (int j = y; j <= y + n-1; j++)
			if (paper[x][y] != paper[i][j])//하나라도 다르면 false 하고 리턴
				return false;

	return true;
}
void solve(int x, int y, int z) {
	if (check(x, y, z)) {
		cnt[paper[x][y] + 1] += 1; //-1이면 +1을 해서 cnt[0]에 저장
        //0이면 +1해서 cnt[1]에 저장, 1이면 +1해서 cnt[2]에 저장
		return; 
	}
	int n = z / 3;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			solve(x + i * n, y + j * n, n);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> paper[i][j];
	solve(0, 0, n);
	for (int i = 0; i < 3; i++) cout << cnt[i] << "\n";
}