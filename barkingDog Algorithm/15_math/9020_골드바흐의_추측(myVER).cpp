#include <bits/stdc++.h>
using namespace std;

vector<bool> state(10'001,true);
void sieve(int n){
    vector<int> primes;
    state[1]=false;
    for(int i=2;i*i<=n;i++){
        if(!state[i]) continue;
        for(int j=i*i;j<=n;j+=i)
          state[j]=false;
    }
    // for(int i=2;i<=n;i++)
    //   if(state[i]) primes.push_back(i);
    // return primes;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    sieve(10'001);
    while(t--){
        int n;
        cin>>n;
        for(int i=n/2;i>=1;i--)
            if(state[i]&&state[n-i]) {
                cout<< i<<' '<<n-i<<'\n';
                break;
            }
    }
}