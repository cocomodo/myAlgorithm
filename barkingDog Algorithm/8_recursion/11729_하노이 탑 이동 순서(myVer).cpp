#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
//b = 6 - a - c;
void hanoi(int n, int a, int c) {
	if (n == 1) {
		cout << a << " " << c << "\n";
		return;
	}
	hanoi(n - 1, a, 6 - a - c);
	cout << a << " " << c << "\n";
	hanoi(n - 1, 6 - a - c, c);
	return;
}

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0);
	cin >> n;
	cout << (1 << n) - 1 << "\n";
	hanoi(n, 1, 3);

}