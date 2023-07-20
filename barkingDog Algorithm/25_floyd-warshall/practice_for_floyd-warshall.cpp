#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[405][405];
int v, e;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>v>>e;
    
    for(int i=1; i<=v; i++){
        fill(d[i],d[i]+1+v,INF);
    }
    
    /*이걸 초기화 해주지 않으면, 자기 자신으로 돌아오는 경로가 있는지에 대해서도 알아낼 수 있는
    플로이드 결과물을 얻을 수 있는가?*/
    for(int i=1; i<=v; i++){
        // d[i][i]=0;//도로는 마을과 마을 사이에 놓여있다고 했으므로 자기 자신으로 향하는 도로는 없다
    }
    for(int i=1; i<=e; i++){
        int a, b, c;
        cin>>a>>b>>c;
        d[a][b]=c;
    }

    for(int k=1; k<=v; k++)
        for(int i=1; i<=v; i++)
            for(int j=1; j<=v; j++){
                if(d[i][k]+d[k][j]<d[i][j]){
                    d[i][j]=d[i][k]+d[k][j];
                }
            }
    int ans=INF;
    for(int i=1; i<=v; i++)
        ans=min(ans,d[i][i]);
    if(ans==INF) ans=-1;
    cout<<ans;
    // for(int i=1; i<=v; i++){
    //     for(int j=1; j<=v; j++){
    //         cout<< d[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }

}