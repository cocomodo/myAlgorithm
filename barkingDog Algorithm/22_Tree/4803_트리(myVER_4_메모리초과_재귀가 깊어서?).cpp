/*이 풀이에서 메모리 초과를 받게되었다. 왜지? 재귀가 깊어지면서 스택메모리를 초과했다는 의미인가?
백준에서는 스택 메모리 제한이 없다는걸로 알고있는데 왜재?
어디에서 메모리 초과가 발생한거지?
*/

/*
예제 입력을
4 4
1 2
2 3
3 4
4 2
를 제출하게 되면, 재귀를 무한 호출하면서 스택메모리 영역에 메모리가 계속 쌓이면서
메모리 초과를 발생시킨다. 
시작 위치에 사이클이 붙어있으면 처음에 시작 위치들은 dfs 함수 밖에서 vis[i]=true
로 체크해 주기 때문에 백준에서 제시한 예제 입력들의 경우는 무한재귀에 빠지지 않았던 것이다.
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, tc, Trees;
vector<int> adj[505];
bool vis[505];
bool isTree;

void dfs(int cur, int prev){
    // vis[cur]=true;
    // isTree=true;
    for(auto nxt: adj[cur]){
        if(nxt==prev) continue; //부모는 제외.
        if(vis[nxt]){
            isTree=false;
            continue;
        }
        dfs(nxt,cur);
    }
} 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(true){
        fill(vis,vis+n+1,0);
        cin>>n>>m;
        if(n==0 && m==0) break;
        
        for(int i=1; i<=n; i++){
            adj[i].clear();
        }
        
        while(m--){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Trees=0;
        for(int i=1; i<=n; i++){
            if(vis[i]) continue;
            vis[i]=true;
            isTree=true;
            dfs(i,-1);
            Trees+=isTree;
        }
        cout<<"Case "<<++tc<<": ";
        if(Trees==1) cout<<"There is one tree."<<'\n';
        else if(Trees>1) cout<<"A forest of "<<Trees<<" trees."<<'\n';
        else cout<<"No trees."<<'\n';
    }
}