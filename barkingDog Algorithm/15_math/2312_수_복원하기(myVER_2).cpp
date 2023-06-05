#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; 
    cin>>t;
    while(t--){
        int n; 
        cin>>n;
        for(int i=2; i*i<=n;i++){
            int cnt=0;
            while(n%i==0){
                cnt++;
                n/=i;
            }
            if(cnt) cout<<i<<' '<<cnt<<'\n';
        }
        if(n!=1) cout<<n<<' '<<1<<'\n';
    }
}