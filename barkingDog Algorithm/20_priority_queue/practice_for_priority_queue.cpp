/*카카오 코딩테스트를 통과하기 위해서 매일 알고리즘을 최선을 다해서 공부하고 싶다. 
최소한 하루에 5문제정도를 풀어야 그나마 좀 괜찮지 않을까 싶다. 현재 상태로는
빠르게 마지막 영역까지 공부해서 개념을 다 떼고나서, 그리고 이제 다시 약점 부위별로
반복학습을 시작해서 견고하게 만들어야 할 것 같다. 
그러니까 빠르게 최선을 다해서 모든 개념들을 다 공부해보도록 하자. 하루에 5문제씩 최소 풀어보도록 하자.*/

/*
|1| => 1  => pq.top; 0

|1| 5 =>(5 삽입) 1        => pq.pop(); pq.top(); 1
1 |2| 5 =>(2 삽입) 2

1 2| 5 10 =>(10 삽입) 2      => pq.pop(); pq.pop(); pq.top(); 2
-99 1 |2 5 10 =>(-99 삽입) 2

-99 1 |2| 5 7 10 =>(7 삽입) 2  => pq.po(); pq.pop(); pq.pop(); pq.top(); 3
-99 1 2 |5| 5 7 10 =>(5 삽입) 5
*/

/* 가운데를 말하는 부분이, 그냥 하나의 쭉 이어진 자료구조가 아니라 
최대힙과 최소힙을 좌우로 붙여서 가운데 부분에서 왼쪽 혹은 오른족에서 top을 해서 확인한다면?
*/

#include <bits/stdc++.h>
using namespace std;

set<int> midle_set;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    // for(int i=0; i<n; i++){
    //     int t;
    //     cin>>t;
    //     midle_set.insert(t);
    //     auto it1=0;
    //     auto it2=prev(midle_set.end())-midle_set.begin();
    //     auto it3=(it1+it2)/2;
    //     cout<<*
    // }

}