#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int t;
    priority_queue<int> pq; queue<int> tmpq;
    for(int i=1; i<=n; i++){
        cin>>t;
        pq.push(t);
        int cnt=i/2;
        for(int j=0; j<cnt; j++){
            tmpq.push(pq.top());
            pq.pop();
        }
        cout<<pq.top()<<'\n';
        for(int j=0; j<cnt; j++){
            pq.push(tmpq.front());
            tmpq.pop();
        }

    }
}

/*
시간초과(Time Limit Exceed-TLE)가 발생한 풀이인데, 예제 코드 출력할때는 
정상적으로 잘 돌아갔다. 비록 시간초과가 발생했지만, 이렇게 풀이를 생각해 낸것도
마음에 들고 풀이도 재미있었다. 
*/