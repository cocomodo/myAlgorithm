#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int n){
    vector<int> primes;
    vector<bool> state(n+1,true);
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
            for(auto q:primes){
                if(q*2<n) continue;
                if(q>=n) break;
                if(p+q==n){
                    ans++;
                    // cout<<p<<' '<<q<<'\n';
                }
            }
        }
        cout<<ans<<'\n';
    }

}