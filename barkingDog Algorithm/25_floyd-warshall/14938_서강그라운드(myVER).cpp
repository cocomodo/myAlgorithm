/*
일단
플로이드를 통해서 각 지점별로 거리를 구하는 형태의 코드를 작성해보자
무한대 초기화
자기자신 0 초기화
경로의 길이들 입력받아서 초기화
3중for문 dp 수행
가진 값들로 후처리
*/

#include <bits/stdc++.h>
using namespace std;

const int INF=0x3f3f3f3f;
int d[105][105];
int n, m, r;
int icnt[105];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>r;
    for(int i=1; i<=n; i++)
        cin>>icnt[i];

    for(int i=1; i<=n; i++)
        fill(d[i],d[i]+1+n,INF);
    

    for(int i=1; i<=r; i++){
        int a, b, c;
        cin>>a>>b>>c;
        d[a][b]=min(d[a][b],c);
        d[b][a]=min(d[b][a],c);//양방향 통행이 가능하다는걸 간과해서 이 부분을 찾는데 매우 오래 걸렸다. 단방향으로만 주어지는것인지, 양방향으로 주어지는 것인지 확실하게 파악하고 그걸 기반으로 그래프에 거리를 입력하도록 하자. 
    }    


    for(int i=1; i<=n; i++)
        d[i][i]=0;
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(d[i][k]+d[k][j]<d[i][j]){
                    d[i][j]=d[i][k]+d[k][j];
                }

    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         if(d[i][j]==0 || d[i][j]==INF) cout<<'0'<<' ';
    //         else cout<<d[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    int ans=0;
    for(int i=1; i<=n; i++){
        int tmp=0;
        // tmp+=icnt[i];
        for(int j=1; j<=n; j++){
            if(d[i][j]<=m) tmp+=icnt[j];
        }
        ans=max(ans,tmp);
    }
    cout<<ans;
}
