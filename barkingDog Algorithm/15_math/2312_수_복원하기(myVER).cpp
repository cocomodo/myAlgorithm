#include <bits/stdc++.h>
using namespace std;

vector<bool> state(100'001,true);
vector<int> sieve(int n){
    vector<int> primes;
    state[1]=false;
    for(int i=2; i*i<=n;i++){
        if(!state[i]) continue;
        for(int j=i*i;j<=n; j+=i)
          state[j]=false;
    }
    for(int i=2;i<=n;i++)
      if(state[i]) primes.push_back(i);
    
    return primes;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    vector<int> primes=sieve(100'001);
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>> divider;
        for(auto p : primes){
            int cnt=0;
            while(n%p==0){
                cnt++;
                n/=p;
            }
            if(cnt!=0)divider.push_back({p,cnt});            
            if(n==1) break;
        }
        for(auto q : divider){
            cout<<q.first<<' '<<q.second<<'\n';
        }
    }
}
/*
처음에 에라토스테네스의 체를 구현할때 j+=i 형태로 for문을 작성해야 했는데, j++형태로 작성해서 
소수가 2와 3만 담겨서 한동안 잘못된 부분을 찾지 못해서 시간을 허비하였다. 
다음에는 에라토스테네스의 체를 작성하고, 체를 통해 걸러낸 소수들이 제대로 담겼는지부터
확인하고 이어서 코드를 작성해 나가도록 하자. 
*/