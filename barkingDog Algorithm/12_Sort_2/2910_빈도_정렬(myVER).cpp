#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.first > b.first;
}

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); 
	int n, c;
	cin >> n >> c;
	vector<pair<int, int>> arr; // pair:{cnt,num}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		bool chk = false;
		for (auto& a : arr) {// vector 속에 있는 모든 원소에 대해서 판별하다가 찾으면 break를 통해서 중지. 이때 auto& a가 아니라 auto a 로 작성하면 틀린다. 
			if (a.second == x) {
				chk = true;
				a.first++;
				break;
			}
		}
		if (!chk) arr.push_back({ 1,x });//이건 처음 등장해서 등장 cnt를 1로 하고 새롭게 원소를 추가하는 과정.이때 !chk의 경우, chk==false이면 !false==true가 되어서 if문이 실행. chk==true	이면 !true==false가 되어서 if문이 미실행. 그래서 이걸 그냥 !chk로만 해석해보면, !chk==> chk가 false라면, 으로 해석해도 충분히 동일하게 연산이 실행되게 치환할 수 있음. 의미가. 그리고 chk==>chk가 참이라면, 이라고 표현을 치환할 수 있음. 결국 이 if문은, 위에 있는 for문을 다 돌아도 동일한 값을 가진 원소를 만나지 못해서 chk=true;로 바뀌지 못해서 처음 false로 설정한 채로 남아있는 경우에, 그래서 결론적으로 처음 등장한 수의 경우에 이렇게 등장 cnt를 1로 하는 x의 값을 arr에 첨부하는 과정. 그리고 이렇게 false라면, true라면, 이라고 해석하는건 처음에 bool chk=fasle;처럼, 기본값이false로 설정되어 있는 경우에 가능한 해석이다. 만약 이게 헷갈린다면 그냥 chk==true, chk==false등으로 코드를 작성하도록 하자.  

	}
	stable_sort(arr.begin(), arr.end(), cmp);

	for (auto b : arr)
		while (b.first--) cout << b.second << ' ';
}