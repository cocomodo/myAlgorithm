#include <bits/stdc++.h>
using namespace std;

int n;
int d[100'005];
int p[100'005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> d[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			p[i] += d[j];
		}
	}
	for (int i = 1; i <= n; i++)
		cout << p[i] << ' ';
	cout << '\n';
	int max_ans = -987654321;
	int min_value = 987654321;

	for (int i = 1; i <= n; i++) {
		max_ans = max(max_ans, p[i]);
		/*for (int j = 1; j <= i; j++) {
			min_value = min(min_value, *min_element(p + 1, p + j + 1));
		}*/
		min_value = min(min_value, *min_element(p + 1, p + i));
		if (p[i] > min_value)
			max_ans = max(max_ans, p[i] - min_value);
	}
	cout << max_ans;
}

/*
나보다 작은 값이 있고, 그 값을 뺀 값이 그 전까지 max보다 크다면, max를 갱신*/
/*
그 전까지 항의 합에서 가장 작은 값을 자기 자신의 항에서
뺐을때, 자기 자신보다 커진다면, 그러면 그게 그 위치에서의 최대합
그리고 그러한 최대합 들 중에서 가장 큰 값을 뽑으면 그게 정답
*/


/*
연속합이기 때문에, 그 항까지의 전체 합에서, 그 항 전까지 제일 작은 부분을 빼면 그게
연속합중에서 가장 큰 합이 된다.
*/