#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int cnt = 0;
	while (n--) {
	stack<char> S;
		string op;
		cin >> op;
		for (auto c : op) {
			if (c == 'A') {
				if (S.empty()) S.push(c);
				else {
					if (S.top() == 'B') S.push(c);
					else S.pop();//원래 들어있던 A를 같이 짝지어 빼는 과정
				}
			}
			else if (c == 'B')
			{
				if (S.empty()) S.push(c);
				else {
					if (S.top() == 'A') S.push(c);
					else S.pop();//원래 들어있던 B를 같이 짝지어 빼는 과정
				}
			}
		}
		
	if (S.empty()) cnt++;
	}
	cout << cnt << "\n";
	return 0;
}