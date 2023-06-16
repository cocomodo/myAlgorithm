#include <bits/stdc++.h>
using namespace std;

int n;

vector<bool> sieve(n+1,true);
vector<int> primes;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=2;i*i<=n;i++){
        if(!sieve[i]) continue;
        for(int j=i*i;j<=n;j+=i)
            sieve[j]=false;
    }
    for(int i=2; i<=n; i++)
        if(sieve[i]) primes.push_back(i);
    primes.push_back(0);/*이건 왜 넣는것 같아? en==int(primes.size())를 사용하기
    위해서 넣은것으로 보여진다. 이걸 넣어서 갯수를 */

    int st=0,en=1,ans=0,tmpSum=primes[0];
    while(1){
        if(tmpSum==n) ans++;
        if(tmpSum<=n) tmpSum+=primes[en++];
        if(n<tmpSum) tmpSum-=primes[st++];
        if(en==int(primes.size())) break;
        /*인덱스 오버 플로우를 방지하면서 가장 마지막 소수를 넘어서는 위치까지 갔다는걸
        표시하기 위한 테크닉으로 보여진다. */
    }
    cout<<ans;
}
