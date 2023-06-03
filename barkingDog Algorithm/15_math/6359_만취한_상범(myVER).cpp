#include <bits/stdc++.h>
using  namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t, n;
    cin>>t;

    while(t--){
        cin>>n;
        int ans=0;
        vector<bool> state(n+1,true);
        for(int i=2;i<=n;i++){
            for(int j=i;j<=n;j+=i){
                if(state[j]) state[j]=false;
                else state[j]=true;
            }
        }
        for(int i=1;i<=n; i++){
            if(state[i])  ans+=1;
        }
        cout<<ans<<'\n';
    }
}