#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    priority_queue<int> mxPq;
    int n;
    cin>>n;
    int t;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>t;
            mxPq.push(t);
        }
    }
    for(int i=0; i<n-1; i++){
        mxPq.pop();
    }
    cout<<mxPq.top();
}
/*메모리 초과가 발생하는 풀이*/

/*2'250'000 개이고, 이걸 int로 담으면, 4byte
9'000'000 byte 100만 바이트가 1mb이니까, 9mb인데, 제한이 12mb
vecotr<int>를 사용하니까 오버헤드가 있어서 그런걸 수도?*/
