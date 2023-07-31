#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[20'005];
const int INF =0x3f3f3f3f;
bool fix[20'005];
int d[20'005];
int v=10;
void dijkstra_naive(int st){
    fill(d, d+v+1,INF);//최단 거리 테이블 초기화
    d[st]=0;
    while(true){
        int idx = -1;
        for(int i=1; i<=v; i++){
            if(fix[i]) continue;
            if(idx==-1 ) idx=i;
            else if(d[i]< d[idx]) idx=i;
        }
        if(idx== -1 || d[idx]== INF) //더 이상 선택할 정점이 없다면
            break;
        fix[idx] = 1; //정점 idx 고정
        for(auto nxt: adj[idx])
            d[nxt.second]= min(d[nxt.second], d[idx]+nxt.first);
    }
}