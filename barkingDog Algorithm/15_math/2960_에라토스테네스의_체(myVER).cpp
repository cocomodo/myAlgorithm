#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    int e=0;
    cin>>n>>k;
    vector<bool> state(n+1,false);
    for(int i=2; i<=n;i++){
        for(int j=i;j<=n;j+=i){
            if(state[j]) continue;
            state[j]=true;   
            e++;
            if(e==k) {
                cout<<j;
                return 0;
            }
        }
    }
}