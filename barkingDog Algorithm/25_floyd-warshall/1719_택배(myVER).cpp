#include <bits/stdc++.h>
using namespace std;

const int INF=0x3f3f3f3f;
int n, m;
int d[205][205];
vector<int> p[205][205];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1; i<=n; i++){
        
        fill(d[i],d[i]+1+n,INF);
        d[i][i]=0;
    }
    while(m--){
        int a, b, c;
        cin>>a>>b>>c;
        d[a][b]=c;
        d[b][a]=c;
    }

    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(d[i][k]+d[k][j]<d[i][j]){
                    d[i][j]=d[i][k]+d[k][j];
                    if(k==i || k==j) continue;
                    p[i][j].push_back(k);
                }
    
    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         cout<<d[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) cout<<'-'<<' ';
            else {
                if(p[i][j].empty()) cout<<j<<' ';
                else cout<<p[i][j].back()<<' ';
            }
        }
        cout<<'\n';
    }
}