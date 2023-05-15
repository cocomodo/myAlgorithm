#include <bits/stdc++.h>
using namespace std;

int n;
int a[1005];
int d[1005];
int pre[1005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		d[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (a[j] < a[i] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
				pre[i] = j;
			}
		}
	}
  //순차적으로 maxD를 갱신하면서 그때의 i를 maxI로 최신화 하고,
  //그 과정이 더이상 진행되지 않을때의 i를 maxI에 저장해서
  //그 maxI을 시작점으로 뒤로 역순으로 수열의 원소들을 
  //deque 혹은 vector에 넣었다가 프린트할 예정. 
	int maxI = 1;
	int maxD = d[1];
	for (int i = 2; i <= n; i++) {
		if (maxD < d[i]) {
			maxI = i;
			maxD = d[i];
		}
	}
	vector<int> ans;
	int cur = maxI;
	while (cur) {
		ans.push_back(a[cur]);
		cur = pre[cur];
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (auto c : ans) cout << c << ' ';
}