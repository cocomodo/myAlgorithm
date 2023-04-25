#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;  // N: 자연수의 개수, M: 선택할 자연수의 개수
vector<int> nums;  // 자연수를 담을 벡터
vector<int> ans;  // 선택한 자연수를 담을 벡터
bool visited[8];  // 중복 선택 방지를 위한 배열

void dfs(int cnt) {
    // M개의 수를 선택했으면 출력 후 리턴
    if (cnt == M) {
        for (int n : ans)
            cout << n << ' ';
        cout << '\n';
        return;
    }
    
    // 이전에 선택된 자연수를 체크하기 위한 변수
    int prev = -1;
    
    for (int i = 0; i < N; i++) {
        // 이미 선택된 자연수인 경우 스킵
        if (visited[i]) continue;
        // 이전에 선택된 자연수인 경우 스킵
        if (prev == nums[i]) continue;
        
        visited[i] = true;  // 선택된 자연수 표시
        ans.push_back(nums[i]);  // 선택된 자연수 벡터에 추가
        prev = nums[i];  // 이전에 선택된 자연수 갱신
        dfs(cnt + 1);  // 다음 자연수 선택
        visited[i] = false;  // 선택 해제
        ans.pop_back();  // 선택된 자연수 제거
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        nums.push_back(n);
    }
    
    sort(nums.begin(), nums.end());  // 오름차순 정렬
    
    dfs(0);  // dfs 탐색 시작
    
    return 0;
}
