#include <bits/stdc++.h>
using namespace std;

int n;//2000
int a[2'005]; //-1e10<=a <= 1e10
long long ans;
bool chk[2'005];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n-2; i++) {
		for (int j = i+1; j < n - 1; j++) {
				auto up_idx = upper_bound(a+j+1, a + n, a[i] + a[j]) - a;
				auto lb_idx = lower_bound(a+j+1, a + n, a[i] + a[j]) - a;
				auto up_idx2 = upper_bound(a + j + 1, a + n, a[j] - a[i]) - a;
				auto lb_idx2 = lower_bound(a + j + 1, a + n, a[j] - a[i]) - a;
					for (int k = lb_idx; k < up_idx; k++) {
						if (up_idx != lb_idx) chk[k] = true;
						/*if (j != k && k != i) {
							if (ub_idx != lb_idx) {
								if (a[i] + a[j] == a[k]) chk[k] = true;
								if (a[i] + a[k] == a[j] ) chk[j] = true;
								if (a[k] + a[j] == a[i] ) chk[i] = true;
							}
						}*/
					}
					for (int p = lb_idx2; p < up_idx2; p++)
						if (up_idx2 != lb_idx2) chk[p] = true;
			
			
		}
	}
	for (int i = 0; i < n; i++) {
		if (chk[i] == true) ans++;
	}
	cout << '\n';
	for (int i = 0; i < n; i++) {
		if (chk[i] == true)
			
			cout <<"i is : " << i << ' ' <<"a[i] is : " << a[i] << '\n';
	}
	cout << ans;
}

/*
위 풀이는 합이 0과 같은 풀이인데, 이때 합이 0은 (2 6 8) (3 5 8)이 모두 포함된
갯수를 출력하는게 맞지만, 이 문제의 경우 8이 "좋다" 로 체크가 되었다면 두개가
중복으로 포함되는게 아니라 체크된 "8" 하나만 ans에 갯수로 포함되면 되니까
풀이가 달라져야 한다. 
*/
/*
중요한 예제입력.
5 
-3 -1 0 0 1

5
0 0 0 0 0 

*/
/*
이 풀이의 경우, 
i j k
+ + +
- + + 
- - +
- - - 
인 경우들에 대한 합의 경우들이 나뉘어 지는걸 제대로 걸러내지 못한다
*/