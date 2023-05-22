#include <bits/stdc++.h>
using namespace std;

//tuple<0,1,2,3> 이때 0은 이름, 1은 국어, 2는 영어, 3은 수학
bool cmp(const tuple<string,int,int,int>& a, const tuple<string,int,int,int>& b) {
	if (get<1>(a) == get<1>(b) && get<2>(a) == get<2>(b) && get<3>(a) == get<3>(b))
		return get<0>(a) < get<0>(b);
	if (get<1>(a) == get<1>(b) && get<2>(a) == get<2>(b))
		return get<3>(a) > get<3>(b);
	if (get<1>(a) == get<1>(b))
		return get<2>(a) < get<2>(b);
	return get<1>(a) > get<1>(b);
}

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); 
	int n;
	cin >> n;
	vector<tuple<string, int, int, int>> v;
	for(int i=0; i<n; i++) {
		string name;
		int korean;
		int eng;
		int	math;
		cin >>name>> korean >> eng >> math;
		v.push_back({ name,korean,eng,math });
	}
	sort(v.begin(), v.end(), cmp);
	for (auto c : v)
		cout << get<0>(c) << '\n';
}