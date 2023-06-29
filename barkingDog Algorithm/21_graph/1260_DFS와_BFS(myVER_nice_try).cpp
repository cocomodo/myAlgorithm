#include <bits/stdc++.h>
using namespace std;

int n, m, V;
set<int> adj[1005];
vector<bool> vis(1005);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>V;
    
    //그래프 입력
    for(int i=1; i<=m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    //DFS
    for(int i=1; i<=n; i++){
        int s=(V+(i-1)-1)%n+1;
        //s=> 3 4 5 
        if(vis[s]) continue;
        stack<int> st;
        st.push(s);
        // vis[s]=true;
        // cout<<s<<' ';
        while(!st.empty()){
            int cur=st.top(); st.pop();
            if(vis[cur]) continue;
            vis[cur]=true;
            cout<<cur<<' ';
            for(auto it=prev(adj[cur].end()); it!=prev(adj[cur].begin());it--){
                if(vis[*it]) continue;
                st.push(*it);
                // vis[it]=true;
                // cout<<it<<' ';
            }
        }
    }
    cout<<'\n';
    fill(vis.begin(),vis.end(),0);
    //BFS 
    for(int i=1; i<=n; i++){
        int s=(V+(i-1)-1)%n +1;

        if(vis[s]) continue;
        queue<int> q;
        q.push(s);
        vis[s]=true;
        cout<< s<< ' ';
        while(!q.empty()){
            int cur=q.front(); q.pop();
            for(auto it : adj[cur]){
                if(vis[it]) continue;
                q.push(it);
                vis[it]=true;
                cout<<it<<' ';
            }
        }
    }

}
/*
예제 입출력은 정상적으로 잘 만들어 내지만, 제출했을시에 통과하지 못하였다. 
이 풀이의 경우 굉장히 엉성한 부분들을 땜질해서 만들어낸 풀이지만, 코드를 작성하면서
재미있게 작성할 수 있었다. 이 코드의 틀린 부분은 다음에 다시 찾아서 보완해보고 다시 
제출해보기로 하자. 

*/