#include <bits/stdc++.h>
using namespace std;

int arrA[20'005];
int arrB[20'005];

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); 
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int cnt = 0;
		for (int i = 0; i < n; i++)
			cin >> arrA[i];
		for (int i = 0; i < m; i++)
			cin >> arrB[i];
		sort(arrA, arrA + n);
		sort(arrB, arrB + m,greater<int>()); //greater로 하면 내림차순 정렬
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arrA[i] > arrB[j]) {
					cnt += m - j;
					break;
				}
			}
		}//400'000'000(모두 계산해버리면 이정도)
		cout << cnt << '\n';
	}
}