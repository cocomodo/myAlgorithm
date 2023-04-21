#include <bits/stdc++.h>
using namespace std;

bool compare(string a, string b)
{
    int i = 0;
    if (a.length() == b.length())
    {
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] != b[i])
                return a[i] < b[i];
        }
    }
    return a.length() < b.length();
}
int main()
{
    int num;
    string tmp;
    cin >> num;
    vector<string> arr;
    for (int i = 0; i < num; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end(), compare);
    cout << arr[0] << '\n';
    for (int i = 1; i < num; i++)
    {
        if (arr[i - 1] == arr[i])
            continue;
        cout << arr[i] << '\n';
    }
}

// array로 문제 해결했을시 버전

// #include <bits/stdc++.h>
// using namespace std;

// bool compare(string a, string b) {
// 	int i = 0;
// 	if (a.length() == b.length()) {
// 		for (int i = 0; i < a.length(); i++) {
// 			if (a[i] != b[i])
// 				return a[i] < b[i];
// 		}
// 	}
// 	return a.length() < b.length();
// }

// int main() {
// 	int num;
// 	string tmp;
// 	cin >> num;
// 	string arr[20'000];
// 	for (int i = 0; i < num; i++) {
// 		cin >> tmp;
// 		arr[i] = tmp;
// 	}
// 	sort(arr, arr+num, compare);
// 	cout << arr[0] << "\n";
// 	for (int i = 1; i < num; i++) {
// 		if (arr[i - 1] == arr[i])
// 			continue;
// 		cout << arr[i] << "\n";
// 	}
// }