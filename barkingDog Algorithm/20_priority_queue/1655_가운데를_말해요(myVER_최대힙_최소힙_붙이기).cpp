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

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    priority_queue<int> mxpq; //좌측에 
    priority_queue<int, vector<int>, greater<>> minpq;//우측에
    int t;
    cin>>t;
    mxpq.push(t);
    cout<<t<<'\n';
    // if()
    for(int i=2; i<n; i++){
        cin>>t;
        if(mxpq.top()<=t) {
            cout<<mxpq.top()<<'\n';
            minpq.push(t);
        }
        else mxpq.push(t);
    }

}