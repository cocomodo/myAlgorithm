#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--) {
		stack<char> S;
		string q;
		cin >> q;
		for (auto c : q) {
			if (c == '(') S.push(c);
			else {//c==')'
				if (!S.empty() && S.top() == '(') S.pop();
				else S.push(c);
			}
		}
		if (S.empty()) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	return 0;
}
