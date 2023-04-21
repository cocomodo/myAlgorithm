#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n;
string board[27];
int vis[27][27];

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); 
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> board[i];
	int cnt = 0; 
	vector<int> ans;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == '0' || vis[i][j] == 1)
				continue;
			queue<pair<int, int>> Q;
			vis[i][j] = 1;
			Q.push({ i,j });
			int area = 1;
			cnt++;
			while (!Q.empty()) {
				auto cur = Q.front(); Q.pop(); 
				for (int k = 0; k < 4; k++) {
					int nx = cur.X + dx[k];
					int ny = cur.Y + dy[k];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
					if (board[nx][ny] == '0' || vis[nx][ny] == 1) continue;
					vis[nx][ny] = 1;
					Q.push({ nx,ny });
					area++;
				}
			}
			ans.push_back(area);
		}
	}
	cout << cnt << "\n";
	sort(ans.begin(), ans.end());
	for (int i : ans)
		cout << i << "\n";
	return 0;
}