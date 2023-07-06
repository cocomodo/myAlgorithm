/*각각의 dfs를 m번씩 돌면서 적립시킬까 했는데, 
이제보니까 m의 범위가 100'000이라, 최대 100,000번 
dfs를 도는건 아닌것 같다.
dfs를 한번 돌면서, 각각의 위치가 되었을때 그 위치에 저장되어있는데
칭찬수치를 추가적으로 더해주어서 다음 단계로 넘기는것이 맞는것 같다. */

#include <bits/stdc++.h>
using namespace std;

int n, m;
// vector<int> adj[100'005];
int point[100'005];
vector<int> child[100'005];
vector<pair<int,int>> output;

void dfs(int cur,int dist){//이렇게 dfs로 탐색 해버리면 순차적으로 출력이 안된다.
    cout<<dist<<' ';
        // cout<<"test"<<'\n';
    for(auto nxt: child[cur]){
        dfs(nxt,dist+point[nxt]);
    }
}
void bfs(int st, int dist){
    output.push_back({st,dist});
    queue<pair<int,int>> q;
    q.push({st,dist});
    while(!q.empty()){
        auto [cur,curdist]=q.front(); q.pop();
        for(auto nxt: child[cur]){
            output.push_back({nxt,curdist+point[nxt]});
            // output[nxt]=curdist+point[nxt];
            // cout<<curdist+point[nxt]<<' ';
            q.push({nxt,curdist+point[nxt]});
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=1; i<=n; i++){
        int t;
        cin>>t;
        if(t==-1){
            continue;
        }
        child[t].push_back(i);//자식들이 정렬 되어있어야 할것이다.
    }
    // sort(child+1,child+n+1);// 이렇게 정렬하면서 예제에서 주어지는 경우는 순서가 꼬인다.
    for(int i=1; i<=n; i++){
        sort(child[i].begin(),child[i].end());
    }
    for(int i=0; i<m; i++){
        int u, d;
        cin>>u>>d;
        point[u]=d;/*여기를 point[u]+=d 처럼 중복허용 하면 통과하게 된다.*/
    }
    bfs(1,0);
    sort(output.begin(),output.end());
    for(auto [node,nodePoint]:output){
        cout<<nodePoint<<' ';
    }
    // for(auto nxt: child[1]) cout<<nxt<<'\n';

}