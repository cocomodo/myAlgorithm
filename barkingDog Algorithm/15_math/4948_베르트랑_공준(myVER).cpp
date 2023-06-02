#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int n){
    vector<int> primes;
    vector<bool> state(n+1,true);
    state[1]=false;
    for(int i=2; i*i<=n;i++){
        if(!state[i]) continue;
        for(int j=i*i;j<=n;j+=i)
            state[j]=false;
    }
    for(int i=2; i<=n; i++){
        if(state[i]) primes.push_back(i);
    }
    return primes;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true){
        int n;
        cin>>n;
        if(n==0) break;
        vector<int> primes2=sieve(2*n);
        vector<int> prime1=sieve(n);
        cout<<primes2.size()-prime1.size()<<'\n';
    }
}