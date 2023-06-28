#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> minPq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie();

    int n;
    cin>>n;
    while(n--){
        int t;
        cin>>t;
        minPq.push(t);
    }
    long long ans=0;
    while(minPq.size()>1){
        long long tmp=0;
        tmp+=minPq.top(), minPq.pop();
        tmp+=minPq.top(), minPq.pop();
        ans+=tmp;
        minPq.push(tmp);
    }
    cout<<ans;
}

/*타입을 설정하는데 아쉬움이 남는 풀이 
priority_queue경우 int로 설정해놓고, tmp값을 long long 으로 설정하면
의미가 없다 그저  int 범위 였기 때문에 통과할 수 있었을 뿐이다. 이런식으로 얻어걸리는
식의 타입 설정을 하지 않도록 주의하도록 하자. 확실하게 타입이 어떻게 되야 하는지에
대해서 이해하고 타입을 설정하고 풀이를 쌓아나가도록 하자. 
*/