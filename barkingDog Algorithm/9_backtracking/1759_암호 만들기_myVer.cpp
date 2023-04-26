#include <bits/stdc++.h>
using namespace std;

int L, C;
char pas[20];
char words[20];
bool isused[20];

bool aeiou(char t) {
	return t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u';
}

void func(int k,int st) {

	if (k == L) {
		bool flag = false;
		int cnt1 = 0;
		int cnt2 = 0;
		for (int i = 0; i < L; i++) {
			if (aeiou(pas[i])) cnt1++;
			else cnt2++;
		}
		if (cnt1 >= 1 && cnt2 >= 2) flag = true;

		if (flag) {
			for (int i = 0; i < L; i++)
				cout << pas[i];
			cout << '\n';
		}
	}

	/*if (k == L) {
		for (int i = 0; i < L; i++)
			cout << pas[i];
		cout << '\n';
		return;
	}
	}*/
	for (int i = st; i < C; i++) {
		//if (isused[i]) continue;
		//isused[i] = 1;
		pas[k] = words[i];
		func(k + 1, i + 1);
		//isused[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> L >> C;
	for (int i = 0; i < C; i++)
		cin >> words[i];
	sort(words, words + C);
	func(0,0);
	return 0;
}