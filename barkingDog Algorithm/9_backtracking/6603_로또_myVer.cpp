#include <bits/stdc++.h>
using namespace std;

int k;
int s[15];
int arr[15];
bool isused[15];
int m = 6;

void func(int t,int st) {
	if (t == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	//int st = 0;
	//if (t != 0) st = s[t - 1] + 1;
	for (int i = st; i < k; i++) {
		if (isused[i])  continue;
		isused[i] = 1;
		arr[t] = s[i];
		func(t + 1,i+1);
		isused[i] = 0;
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (true) {
		cin >> k;
		if (k == 0) return 0;
		for (int i = 0; i < k; i++) {
			cin >> s[i];
		}
		func(0,0);
		cout << '\n';
	}
}