
// 2초 128mb
#include <bits/stdc++.h>
using namespace std;

int n;
long long d[1'000'005];
long long mod = 1'000'000'000;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	
	d[0] = 0;
	d[1] = 1;
	for (int i = 2; i <= 1'000'000; i++)
		d[i] = (d[i - 1] + d[i - 2])%mod;

	if (n == 0) {
		cout << 0 << '\n';
		cout << 0;
	}
	else if (n < 0) {
		if (n % 2 == 0) {// 음수를 받고 짝수항일때=> 음수값 출력
			cout << -1 << '\n';
			cout << d[-n];
		}
		else {
			cout << 1 << '\n';
			cout << d[-n];
		}
	}
	else {//그냥 양수일때
		cout << 1 << '\n';
		cout << d[n];
	}
}

//음수를 받았을때, 짝수면  음수를 출력
//음수를 받았을때, 홀수면 양수를 출력. 
