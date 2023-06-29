#include <bits/stdc++.h>
using namespace std;

int n, m, st;
vector<int> adj[1005];
bool vis[1005];

//비재귀 DFS
void dfs1(){
    stack<int> s;
    s.push(st);
    while(!s.empty()){
        int cur=s.top(); s.pop();
        if(vis[cur]) continue;
        vis[cur]=true;
        cout<<cur<<' ';
        for(int i=0; i<adj[cur].size(); i++){
            int nxt=adj[cur][adj[cur].size()-1-i];
            if(vis[nxt]) continue;
            s.push(nxt);
        }

    }
}

void dfs2(int cur){
    vis[cur]=true; //방문했다고 표시를 남기고
    cout<<cur<<' '; // 출력을 한다. 
    for(auto nxt: adj[cur]){
        if(vis[nxt]) continue;
        dfs2(nxt);
    }
}

void bfs(int st){
    queue<int> q;
    q.push(st);
    vis[st]=true;
    while(!q.empty()){
        int cur=q.front(); q.pop(); 
        cout<< cur<<' ';
        for(auto nxt: adj[cur]){
            if(vis[nxt]) continue;
            q.push(nxt);
            vis[nxt]=true;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>st;
    while(m--){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //번호가 작은 것 부터 방문하기 위해 정렬
    for(int i=1; i<=n; i++)
        sort(adj[i].begin(),adj[i].end());
    
    // for(int i=0; i<n;i++){/*전체 노드에 대해서, 노드가 1000개일때, 간선이 하나 
    // 주어지는 케이스의 경우, 노드들이 true로 체크가 될 수 없는데, true 여야만 건너뛰*/
    //     int start=(st+i-1)%n+1;
    //     if(vis[start]) continue;
    //     dfs2(start);
    // }
    dfs2(st);
    cout<<'\n';
    fill(vis+1,vis+n+1,false);
    // for(int i=0; i<n; i++){
    //     int start=(st+i-1)%n+1;
    //     if(vis[start]) continue;
    //     bfs(start);
    // }
    bfs(st);
}
/* 이 문제의 풀이법은, 문제에서 제시되는 그래프가 연결 그래프라고 확실하게 제시가 되어야
이 풀이가 정확하게 들어맞는 풀이법이다. 만약 문제에서 연결 그래프가 아니라면, 이건 
뚝 끊겨서 방문하지 않는 부분이 생기는 풀이이다. 

==>>>> 그래서 현재 작성되어 있는 bfs와 dfs를

for(int i=0; i<n; i++){
    int start=(st+i-1)%n+1;
    if(vis[start]) continue;
    bfs(start) or dfs2(start); 
}
형태처럼 감싼 부분이, 연결 그래프가 아니더라도 이 코드가 정상적으로 원하는 결과를 출력할 수 있게
만들어주는 부분이다. 문제에서 확실하게 연결 그래프인지 아닌지 제시가 안되어 있으므로 이렇게
연결 그래프가 아니더라도 문제를 해결 할 수 있는 코드를 작성해야 한다. 
*/

/*
위와같이 연결 그래프가 아니더라도, 라는 식으로 문제를 해결하려 코드를 작성해보니 예제 출력 형식의
출력이 나오지 않는다. 예제출력 형태로 코드가 나오기 위해서는
연결되어 있는 부분들만 출력하는 형태의 코드를 작성해야한다. 
이 문제는 예제 출력을 힌트로 얻어서 그에 맞는 코드를 작성해서 제출해야 할 것 같고, 
문제에 조금 애매한 부분이 있는 형태의 문제인듯 하다. 
조금 더 세부적으로 설명이 주어진다면 더욱 좋은 문제일듯 싶다. 
*/