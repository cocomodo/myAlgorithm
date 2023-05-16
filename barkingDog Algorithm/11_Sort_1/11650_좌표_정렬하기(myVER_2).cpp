#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> p[100'004];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}
	sort(p, p + n);
	for (int i = 0; i < n; i++)
		cout << p[i].first << ' ' << p[i].second << '\n';
}

/*
이 풀이는 pair<int,int> 타입을 담는 배열 p를 원소를 100'004개 잡아서
배열에 대해서 sort를 진행하고, 배열의 원소 p[i]에 대해서 각각의
원소가 pair이기 때문에 p[i].first, p[i].second로 각각의 페어의 
원소로 접근할 수 있는 것이다. 
내 첫번재 풀이는 벡터로, 이 풀이는 배열로 푸는것이고 결국
배열을 이용해서 pair를 담는다. 
*/