#include <bits/stdc++.h>
using namespace std;

int n;
long long d[105];
long long p[105];
long long mod = 1'000'000'005;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); 

	cin >> n;
	d[1] = 9;
	d[2] = 17;

	p[1] = 0;
	p[2] = 1;
	p[3] = 2;
	for (int i = 3; i <= 100; i++) {
		p[i] = (p[i - 1] + p[i - 2]) % mod;
	}
	for (int i = 3; i <= 100; i++) {
		d[i] = (2 * d[i - 1] -  p[i])% mod;
	}

	for (int i = 1; i <= 100; i++)
		cout << d[i] << '\n';
	
}




/*

n=1// 1 2 3 4 5 6 7 8 9 ///9개

n=2// 12 23 34 45 56 67 78 89 // 8개

n=2// 21 32 43 54 65 76 87 98 // 8개

n=2// 10  //1개 

(n=2)==> 8+8+1 =17개 
*/

/*
1 2 3 4 5 6 7 8 9 

	1 2 3 4 5 6 7 8 9
	10 21 32 43 54 65 76 87 98 
	
	
	1 2 3 4 5 6 7 7 8 9
	12 23 34 45 56 67 78 89 9-10



	10 21 32 43 54 65 76 87 98
	10--1 210 321 432 543 654 765 876 987


	10 21 32 43 54 65 76 87 98
	101 212 323 434 545 656 767 878 989


	12 23 34 45 56 67 78 89
	121 232 343 454 565 676 787 898

	12 23 34 45 56 67 78 89
	123 234 345 456 567 678 789 89-10

*/

/*
210 321 432 543 654 765 876 987 
210-1 3210 4321 5432 6543 7654 8765 9876  p

210 321 432 543 654 765 876 987
2101 3212 4323 5434 6454 7656 8767 9878

p

p




*/