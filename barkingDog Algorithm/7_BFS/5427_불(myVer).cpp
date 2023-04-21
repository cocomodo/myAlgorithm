#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int TC, bx, by;
int board[1002][1002];
int visF[1002][1002];
int visS[1002][1002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> TC;
	while (TC--) {
		bool escape = false;
		queue<pair<int, int>> Qf;
		queue<pair<int, int>> Qs;
		cin >> by >> bx;
		for (int i = 0; i < bx; i++) {
			fill(visF[i], visF[i] + by, -1);
			fill(visS[i], visS[i] + by, -1);
		}
		for (int i = 0; i < bx; i++) {
			for (int j = 0; j < by; j++) {
				char c;
				cin >> c;
				if (c == '#') board[i][j] = -1;
				else {
					if (c == '@') {
						Qs.push({ i,j });
						visS[i][j] = 0;
					}
					else if (c == '*') {
						Qf.push({ i,j });
						visF[i][j] = 0;
					}
					board[i][j] = 0;
				}
			}
		}
		while (!Qf.empty()) {
			auto v = Qf.front(); Qf.pop();
			for (int k = 0; k < 4; k++) {
				int nx = v.X + dx[k];
				int ny = v.Y + dy[k];
				if (nx < 0 || nx >= bx || ny < 0 || ny >= by) continue;
				//벽이 아니고, 이미 방문을 했다면, 패스
				if (board[nx][ny] == -1 || visF[nx][ny] >= 0) continue;
				visF[nx][ny] = visF[v.X][v.Y] + 1;
				Qf.push({ nx,ny });
			}
		}
		while (!Qs.empty() && !escape) {
			auto v = Qs.front(); Qs.pop();
			for (int k = 0; k < 4; k++) {
				int nx = v.X + dx[k];
				int ny = v.Y + dy[k];
				if (nx < 0 || nx >= bx || ny < 0 || ny >= by) {
					//기본 위치가 visS가 1이기 때문에, 탈출하기 마지막 위치에 도달했을때
					//visS를 출력하면 그게 바로 걸린 시간과 같다
					//근데 이 문제의 경우 시간에 대한 개념과 방문에 대한  
					//개념이 섞여서 그런지 시작을 1로 놓고 계산해서 
					//마지막에 +1을 안하고 출력하는게 조금 헷갈리는것 같다. 
					cout << visS[v.X][v.Y] + 1 << "\n";
					escape = true;
					break;
				}
				if (board[nx][ny] == -1|| visS[nx][ny] >= 0) continue;
				if (visF[nx][ny] != -1 && visF[nx][ny] <= visS[v.X][v.Y] + 1) continue;
				visS[nx][ny] = visS[v.X][v.Y] + 1;
				Qs.push({ nx,ny });
			}
		}
		if (!escape) cout << "IMPOSSIBLE" << "\n";
	}
}