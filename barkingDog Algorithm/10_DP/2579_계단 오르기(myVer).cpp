#include <bits/stdc++.h>
using namespace std;

int n;
int a[305];
int d[305];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	d[1] = a[1];
	d[2] = a[1] + a[2];
	d[3] = max(a[1] + a[3], a[2] + a[3]);
	for (int i = 4; i <= n; i++)
		//i-2번째를 밟고 한칸 건너뛰어서 i번째를 밟을때와,
		//i-3번째를 밟고, 한칸 건너뛰어서 i-1번째, i번째를 밟을때의 값 중에서
		//최대값이, i를 무조건 밟았을때의 최대값에 해당한다. 
		d[i] = max({ d[i - 2] + a[i],d[i - 3] + a[i - 1] + a[i] });
	cout << d[n];

}