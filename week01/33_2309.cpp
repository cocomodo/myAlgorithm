#include <bits/stdc++.h>
using namespace std;

int arr[9];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int total = 0;

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		total += arr[i];
	}
	sort(arr, arr + 9);
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (arr[i] + arr[j] == total - 100) {
				arr[i] = -1;
				arr[j] = -1;
				for (int i = 0; i < 9; i++)
					if (arr[i] != -1)
						cout << arr[i] << "\n";
				return 0;
			}
		}
		
	}
	
	
}