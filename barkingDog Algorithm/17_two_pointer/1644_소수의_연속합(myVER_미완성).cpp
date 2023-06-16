#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> sieve(int n) {
	vector<int> primes;
	vector<bool> checks(n + 1,true);
	checks[1] = false;
	for (int i = 2; i * i <= n; i++) {
		for (int j = 2 * i; j<= n; j += i) {
			//이 속은 j에 대해서 기록해야 하는데 몇번 i로 작성했다. 
			//주의하도록 하자. 
			if (!checks[j]) continue;
			checks[j] = false;
		}
	}
	for (int i = 2; i <= n; i++) {
		if (checks[i]) primes.push_back(i);
	}
	return primes;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector<int> primes;
	primes = sieve(n);
	// iterator primes.begin();
}