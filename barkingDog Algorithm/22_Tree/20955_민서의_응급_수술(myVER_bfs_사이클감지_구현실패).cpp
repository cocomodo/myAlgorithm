/*결국 각각의 트리들을 순회하면서 체크를 남기고, 그리고 그 체크가 되는 것들을
숫자로 세가지고 더하면 총 갯수가 나오고, 거기서 하나만 빼면 전체를 트리 형태로
연결하기 위해서.. 라고 생각했는데, 생각해보니 이 문제의 경우는, 사이클 형태가
존재하는 경우, 그 사이클 부분을 끊어주어서 트리가 되도록 만드는 연산도 들어갈 
수 있는 문제로 보여진다. 
*/

/*
사이클이 있으면, 그걸 끊기 위한 연산이 있어야해서 하나 추가, 사이클이 있을때마다 하나씩 추가
그리고 각각이 떨어져 있으면 그것의 갯수를 세서 그것도 다 추가. 그리고 마지막에 하나 빼주면 
딱 그 숫자가 된다. 
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[100'005];
bool vis[100'005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    int ans=0;
    while(m--){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }                                         
    for(int i=1; i<=n; i++){
        if(vis[i]) continue;
        ans++;//떨어져있는 그래프 들을 카운트함
        queue<int> q;
        q.push(i);
        vis[i]=true;
        while(!q.empty()){
            int cur=q.front(); q.pop();
            for(auto nxt: adj[cur]){
                if(vis[nxt]) continue;/*이 부분은 결국 자기가 왔던 부분이 아닌
                곳을 가기 위해서 왔던 곳이라면 가지 않기 위해 하는 과정이다.
                그렇다면 자기가 왔던 곳이 아니라, 사이클이 있어서 나중에 돌다가 방문했던
                곳으로 가게 되는건 어떻게 구분하지?*/
                vis[nxt] =true;
                q.push(nxt);
            }
        }
    }

}