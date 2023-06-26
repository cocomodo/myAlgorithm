#include <bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>, greater<int>> pq; /*sort에는 compare 함수를 넣을때 
greater<int>() 형태로 넣을 수 있었는데, 여기다가는 이렇게 넣으니까 에러가 난다.*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int n;
    cin>>n;
    while(n--){
        int t;
        cin>>t;
        if(t==0){
            if(pq.empty()) cout<<0<<'\n';
            else {
                cout<<pq.top()<<'\n';
                pq.pop();
            }
        }
        else{
            pq.push(t);
        }
    }
}