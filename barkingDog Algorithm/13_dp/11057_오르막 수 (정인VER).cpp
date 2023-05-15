#include <bits/stdc++.h>
using namespace std;

int n;
long long dp[10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (long long i = 0; i <= 9; i++)
		dp[i] = i+1LL;
	for (int i = 0; i < n - 1; i++)
		for (int j = 1; j <= 9; j++)
			dp[j] = (dp[j - 1] + dp[j]) % 10007;

	cout << dp[9];
}