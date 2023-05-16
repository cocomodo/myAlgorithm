// Authored by : hgmhc
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/9e42012f919544dfa94544e08b2ee1fe
#include <bits/stdc++.h>
using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  pair<int,string> x[n];
  for (auto& s : x) cin >> s.first >> s.second;
  stable_sort(x, x+n, [&](pair<int,string> a, pair<int,string> b) {
    return a.first < b.first;
  });
  for (auto p : x) cout << p.first << ' ' << p.second << '\n';
}
/*
13 to 15번째 줄의 코드가 낯설면 람다 함수 키워드로 구글링 추천
*/

/*
백준 사이트 컴파일러 상에서는 가변 길이 배열(VLA - C99 표준) 을 사용할 수 있어서
이 코드를 제출해도 정상적으로 통과한다. 
하지만 사용하지 않는 방법으로 익히도록 하자. 
*/