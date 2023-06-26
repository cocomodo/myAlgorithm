#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int> pq; //최대 힙
    // priority_queue<int, vecotr<int>, greater<int>> pq; // 이렇게 선언시에 최소 힙
    pq.push(10); pq.push(2); pq.push(5); pq.push(9); // {10, 2, 5, 9}
    cout<<pq.top()<<'\n'; //10
    pq.pop(); // {2,5,9}
    cout<<pq.size()<<'\n'; //3
    if(pq.empty()) cout<< "PQ is empty\n";
    else cout<< "PQ is not empty\n";
    pq.pop(); //{2, 5}
    cout<<pq.top()<<'\n'; // 5
    pq.push(5); pq.push(15); //{2,5,5,15}
    cout<<pq.top()<<'\n'; // 15;
}