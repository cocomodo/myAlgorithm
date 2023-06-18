#include <bits/stdc++.h>
using namespace std;

int n, k; 
int a[1'000'005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	int oddcnt = 0, en = 0, lth = 0;
	if (a[en] % 2 != 0) oddcnt++;
	for (int st = 0; st < n; st++) {
		while (en < n - 2 && oddcnt != k) {
			en++;
			if (a[en] % 2 != 0)	oddcnt++;
		}
		// en==n-1이 되었거나, oddcnt==k가 되었거나
		//oddcnt!=k 이어도 en==n-1이 되었으면 lth 갱신 시도
		lth = max(lth, en - st + 1 - oddcnt);
		if (a[st] % 2 != 0) oddcnt--;
	}
	cout << lth;
}
/*
 신경써야할 반례 
 5 2
 2 3 4 5 7 ==> 정답 출력 2

 1 2
 2  ==> 정답 출력 1

 4 6
 2 4 6 8 ==> 정답 출력 4

 2 6
 2 4 ==> 정답 출력 2
*/

/*
가장 긴 길이 문제이니까, 
그 사이에서 원소를 k개만큼만 제외하면, 
예를 들어서 
2 4 6 8 7 10 12 13 14 15인 경우, 여기서 k는 2라면 2개를 제외할 수
있고, 이때에 14-2+1=13이고, 이때에 2개를 빼면, (7과 13)
11이 되고, 
2 4 6 8 10 12 14 의 길이는 // 아 숫자로 하면 안되네 원소의
인덱스로 해야하네 
7-1+1=7이 나오고 이게 수열의 길이. 
9-1+1= 9
그럼 즉 수열의 길이는 인덱스를 통해서 갯수를 새고, 그 갯수에서
짝수인 원소의 갯수 이때는 k를 빼주면 딱 될것 같다. (나머지 값이
짝수라는 가정하에) 
*/