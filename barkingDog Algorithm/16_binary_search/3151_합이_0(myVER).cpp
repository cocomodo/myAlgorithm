#include <bits/stdc++.h>
using namespace std;

int n;
int a[10'005];
/*전체 가능한 조합의 수는 10000c3이고, 이 수는
10000*9999*9998/3*2*1 => 5000*3333*9998이고 이 수는 
대략적으로 10000*5000*3333 과 비슷하고, 5000 0000 *3000이라고 하면 
150 000 000 000 => 1천 5백억이다. 그래서 가능한 모든 경우의 수는 int 범위를
넘어서게 되고, 이때 모든 원소가 0이라면 충분히 그만한 경우의 수가 나오게 된다
그래서 ans는 타입을 long long 으로 선언해주어야 한다. */
long long ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);

	for (int i = 0; i < n-2; i++) {
		for (int j = i + 1; j < n-1; j++) {
			int idx = lower_bound(a+j+1, a + n, -a[i] - a[j]) - a;
			if (a[i] + a[j] + a[idx] == 0) {

				int cnt = upper_bound(a+j+1, a + n, -a[i] - a[j]) - lower_bound(a+j+1, a + n, -a[i] - a[j]);
				ans += cnt;
			}
		}
	}
	cout << ans;
}