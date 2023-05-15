#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[105];
int d[10'005]; //d[i]: 가치의 합이 i원이 되도록 하는 총 경우의 수.

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			if(k-a[j]>0) d[i] += d[k - a[j]];
		}
	}

}

/*
풀이에는 실패했지만, 착상이 정답 코드와 제법 유사한 방향으로
나아간것 같아서 나쁘지 않은것 같다. 조금 더 노력해서 풀어낼 수 있도록
해보자. 지속적으로 노력하자. 
*/