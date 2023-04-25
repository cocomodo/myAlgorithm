//아래와 같은 풀이는 시간초과가 난다. 
#include <bits/stdc++.h>
using namespace std;

int n, s;
int arr[25];
int cnt;
int sum;
bool isused[25];
void func(int k) {
	if (sum == s) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (isused[i])
			continue;
		isused[i] = 1;
		sum += arr[i];
		func(k + 1);
		isused[i] = 0;
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	func(0);
	cout << cnt;
}