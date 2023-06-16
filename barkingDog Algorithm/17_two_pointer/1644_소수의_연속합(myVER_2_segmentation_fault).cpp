#include <bits/stdc++.h>
using namespace std;

int n;

vector<bool> sieve(n+1,true);
vector<int> primes;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=2; i*i<=n;i++){
        if(!sieve[i]) continue;
        for(int j=i*i;j<=n; j+=i)
            sieve[j]=false;
    }
    
    for(int i=2; i<=n; i++)
        if(sieve[i]) primes.push_back(i);
    primes.push_back(0);

    int st=0,en=1,ans=0,tmpSum=primes[0];
    while(1){
        if(tmpSum==n) ans++;
        if(tmpSum<=n) tmpSum+=primes[en++];
        if(n<tmpSum) tmpSum-=primes[st++];
        if(en==int(primes.size())) break;
    }
    cout<<ans;
}
