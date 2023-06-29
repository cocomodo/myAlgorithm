#include <bits/stdc++.h>
using namespace std;

priority_queue<int> mxPq;
priority_queue<int, vector<int>, greater<>> minPq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0; i<n;i++){
        int t;
        cin>>t;
        if(mxPq.size()<=minPq.size())
            mxPq.push(t);
        else
            minPq.push(t);

        if(!mxPq.empty() &&!minPq.empty()&& mxPq.top() > minPq.top()){/*로직상 mxPq는 empty() 일 수 없기 때문에 
        !mxPq.empty() 확인이 필요 없지만 넣어봄*/
            minPq.push(mxPq.top());
            mxPq.pop();
            mxPq.push(minPq.top());
            minPq.pop();
        }
        cout<<mxPq.top()<<'\n';
    }
}