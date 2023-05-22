#include <bits/stdc++.h>
using namespace std;

vector<string> stArr;

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); 
	string st;
	cin >> st;
	stArr.push_back(st);
	int len_st = st.length();
	for (int i = 0; i <len_st-1; i++) { 
		/*
		* i<len_st; 로 둔다면, 이때 len_st == 8이고, 이 값을 기반으로 생각해보면, 0, 1, 2, 3, 4, 5, 6, 7 까지의 8회가 시행되는데, 그렇게 되면 앞글자를 지우는 연산이 8회가 시행된다.처음에 원본인 baekjoon 글자는 그대로 넣었고, 그리고 나서 8회동안 첫 글자를 지우는 연산을 시행하면
		* baekjoon(내가 넣어준 첫번째)
		* aekjoon(i=0일때)
		* ekjoon (i=1 일때)
		* kjoon  (i=2 일때)
		* joon   (i=3 일때)
		* oon    (i=4 일때)
		* on     (i=5 일때)
		* n      (i=6 일때)
		*        (i=7 일때) 
		* 처럼 연산되어서 맨 마지막에 공백이 들어가게 된다. 
		*/
		st.erase(0,1);
		stArr.push_back(st);
	}
	sort(stArr.begin(), stArr.end());
	for (auto i : stArr)
		cout << i << '\n';
}