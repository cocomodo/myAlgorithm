#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0);
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'P') { //p라면 개수 증가
			cnt++;
			continue;
		}  
		//'P'일때 continue;로 나머지 부분 넘겨버리기 때문에, 
		//여기에 도달했다는건 P가 아니라는 얘기이고, 그런 경우 무조건 A라는 얘기
		if (cnt >= 2 && s[i + 1] == 'P')
		{
			//PPAP를 P로 치환 한 뒤 cnt--;
			//이건 관념적으로 PPAP를 P로 치환했다고 생각하고 하는 방식으로 보여진다.
			//실질적으로 PPAP를 P로 바꾸었다기 보다는, cnt--을 해줘서 앞에 두개이던
			//PP를 AP를 합쳐서 PPAP로 만들고, 그리고 나서 그걸 P 하나로 바꾼다
			//라고 생각해주는 과정이다. 
			cnt--; 
			i++; //이렇게 해주면서 s[i+1]에서 P를 확인한 과정을 거쳤으니 
			//그 다음 과정을 봐줄 필요가 없어서 그 과정을 넘어가기 위해서 i++을 해준다.
		}
		else {
			cout << "NP" << "\n";
			return 0;
		}
	}
	if (cnt == 1)
		cout << "PPAP" << "\n";
	else
		cout << "NP" << "\n";
	return 0;
}