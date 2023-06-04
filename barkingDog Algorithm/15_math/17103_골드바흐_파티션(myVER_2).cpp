#include <bits/stdc++.h>
using namespace std;

vector<bool> state(1'000'005,true);
vector<int> sieve(int n){
    vector<int> primes;
    state[1]=false;
    for(int i=2;i*i<=n;i++){
        if(!state[i]) continue;
        for(int j=i*i;j<=n;j+=i)
          state[j]=false;
    }
    for(int i=2; i<=n; i++)
      if(state[i]) primes.push_back(i);
    
    return primes;
}

int t,n;
// int ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> primes=sieve(1'000'000);
    cin>>t;
    int ans=0;
    while(t--){
        ans=0;
        cin>>n;
        for(auto p:primes){
            if(p*2>n) break;
            if(state[n-p]) ans++;
        }
        cout<<ans<<'\n';
    }

}