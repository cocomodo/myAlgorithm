#include <bits/stdc++.h>
using namespace std;

int arr[102][102];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    //사과 위치 표시
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        //사과 표시 (4)
        arr[x][y] = 4;
    }

    //방향 전환
    int L;
    cin >> L;
    //방향 전환 저장할 벡터
    vector<pair<int, char>> turnInfo;

    //방향 전환 입력 받음 (L개)
    for (int i = 0; i < L; i++) {
        int sec;
        char dir;
        cin >> sec >> dir;
        turnInfo.push_back({ sec, dir });
    }


    int time = 0;
    pair<int, int> head = { 1,1 };
    int dir = 0;
    int index = 0;
    queue<pair<int, int>> snake;
    //출발 지점에 뱀 표시 (2 이면 뱀)
    arr[1][1] = 2;
    snake.push(head);

    //게임 시작
    while (1) {
        //1초 추가
        time++;

        //머리 전진
        head.first += dx[dir];
        head.second += dy[dir];
        int nx = head.first;
        int ny = head.second;

        //벽, 몸통인경우
        if (nx > n || ny > n || nx < 1 || ny < 1 || arr[nx][ny] == 2) {
            cout << time;
            return 0;
        }//빈칸이면 꼬리 제거
        else if (arr[nx][ny] == 0) {
            pair<int, int> cur = snake.front();
            snake.pop();
            arr[cur.first][cur.second] = 0;
        }

        //벽, 몸통, 빈칸 아니면 꼬리 제거 안하고 머리 push
        arr[nx][ny] = 2;
        snake.push({ nx, ny });

        //입력받은 방향 전환 시간과, 현재 시간이 일치하면 방향 전환
        if (time == turnInfo[index].first) {
            if (turnInfo[index].second == 'D') {
                //오른쪽으로 회전
                dir = (dir + 1) % 4;
                index++;
            }
            else if (turnInfo[index].second == 'L') {
                //왼쪽으로 회전
                dir = (dir + 3) % 4;
                index++;
            }
        }
    }
}