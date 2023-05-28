#include <bits/stdc++.h>
using namespace std;

int n, c,m, ans;
int truck[2002];
vector<tuple<int,int,int>> orders;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>c>>m;
    int f, t, b;
    for(int i=0; i<m; i++){
        cin>>f>>t>>b;
        orders.push_back({t,f,b});
    }
    sort(orders.begin(),orders.end());
    for(auto v: orders) {
        tie(t,f,b)=v;
        bool loadable=true;
        for(int i=f; i<t; i++){
            b=min(b,c-truck[i]);
            if(!b){ //b==0이 되었다면, 
                loadable=false;
                break;
            }
        }
        if(loadable){
            ans+=b;
            for(int i=f; i<t; i++) truck[i] +=b;
        }
    }
    cout<<ans;
}