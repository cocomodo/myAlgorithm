#include <bits/stdc++.h>
using namespace std;

int n;
long long p[105];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	p[1] = 1LL;
	p[2] = 1LL;
	p[3] = 1LL;
	for (int i = 4; i <= 100; i++)
		p[i] = p[i - 3] + p[i - 2];

	while (n--) {
		int a;
		cin >> a;
		cout << p[a] << '\n';
	}
}

/*
2
6
12

파도판 수열 테스트 케이스 2개
p(6)을 출력해라
p(12)를 출력해라


p(1)=1, p(2)=1, p(3)= 1, p(4)= p(1)+p(2)=2,p(5)=p(2)+p(3)=2,p(6)=p(3)+p(4)=3;
*/