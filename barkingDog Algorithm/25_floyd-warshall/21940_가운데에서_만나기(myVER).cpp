/*
왕복시간들중의 최대가, 최소가 되는 곳으로 결정할 것이다.

무한대 초기화
0초기화 (여긴 없는것으로보임)
값 받아들이기
플로이드 돌리기
나온 값으로 처리하기
*/
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int d[205][205];
int n, m;
int location[205];
int intervalfee[205];
int max_fee[205];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m;

    for(int i=1; i<=n; i++)
        fill(d[i],d[i]+1+n,INF);    
    
    for(int i=1; i<=n; i++) /*나는 d[i][i]=0 이어야 한다는 조건을 문제에서 
    찾지못해서 이걸 0으로 초기화 하지 않았는데, 이렇게 해주어야 답이 나온다. 문제를
    다시 읽어보면서 이렇게 d[i][i]=0 이어야 한다는 부분이 어디일지 파악해보자.*/
        d[i][i]=0;

    for(int i=1; i<=m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        d[a][b]=min(d[a][b],c); //단방향
    }
    int k; //사람의 총 인원
    cin>>k;
    for(int i=1; i<=k; i++) cin>>location[i];

    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(d[i][k]+d[k][j]<d[i][j]){
                    d[i][j]=d[i][k]+d[k][j];
                }
    int min_val=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){ //k회 실행
            intervalfee[i]=max(intervalfee[i],d[i][location[j]]+d[location[j]][i]);//왕복비용들 중 최댓값.
        }
    }
    min_val=*min_element(intervalfee+1, intervalfee+1+n);
    for(int i=1; i<=n; i++)
        if(intervalfee[i]==min_val) cout<<i<<' ';

}