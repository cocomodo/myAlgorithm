/*
두 정점 사이의 간선이 1개 이하이고, 루프가 존재하지 않는 그래프가 '단순 그래프' 이다
'단순 그래프'의 경우 표현법 1- 인접 행렬 을 이요하여서 표현할 수 있다. 

관례적이라고 할 수 있을텐데, 
웬만하면 정점은 1-indexed로 번호를 붙인다. 
1번부터 v번 까지의 정점이 있는것이다. 

*/

#include <bits/stdc++.h>
using namespace std;




vector<int> adj[10];
bool vis[10];

void bfs(){
    queue<int> q;
    q.push(1);
    vis[1]=true;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        cout<<cur<<' ';
        for(auto nxt: adj[cur]){
            if(vis[nxt]) continue;
            q.push(nxt);
            vis[nxt]=true;
        }
    }
}
int dist[10];

void bfs_lth(){
    fill(dist, dist+10,-1);
    queue<int> q;
    q.push(1);
    dist[1]=0;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(auto nxt: adj[cur]){
            if(dist[nxt]!=-1) continue;
            q.push(nxt);
            dist[nxt]=dist[cur]+1;
        }
    }
}

//비재귀 DFS 첫번째 버전. 관념적 DFS와 다름
vector<int> adj[10]; 
bool vis[10];

void dfs(){
    stack<int> s;
    s.push(1);
    vis[1]=true;
    while(!s.empty()){
        int cur=s.top();
        s.pop();
        cout<<cur<<' ';
        for(auto nxt: adj[cur]){
            if(vis[nxt]) continue;
            s.push(nxt);
            vis[nxt]=true;
        }
    }
}
//재귀 DFS. 관념적 DFS와 같음.
vector<int> adj[10];
bool vis[10];

void dfs(int cur){
    vis[cur]=true;
    cout<<cur<<' ';
    for(auto nxt: adj[cur]){
        if(vis[nxt]) continue;
        dfs(nxt);
    }
}
//비재귀 DFS 두번째 버전. 관념적 DFS와 같음. 출력문 형태의 문제의 경우
//비재귀 DFS를 이용해야 할때, 이런식의 비재귀 DFS의 두번째 버전을 사용해야 함.
vector<int> adj[10];
bool vis[10];

void dfs(){
    stack<int> s;
    s.push(1);
    while(!s.empty()){
        int cur=s.top();
        s.pop();
        if(vis[cur]) continue;
        vis[cur]=true;
        cout<<cur<<' ';
        for(auto nxt: adj[cur]){
            if(vis[nxt]) continue;
            s.push(nxt);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    /* 인접 행렬을 이용한 표현법1 */
    //방향 그래프의 경우(Directed Graph)
    int adj_matrix[10][10]={};
    int v, e;
    cin>>v>>e;
    for(int i=0; i<e; i++){
        int u, v;
        cin>>u>>v;
        adj_matrix[u][v]=1;
    }
    /*인접 행렬을 이용한 표현법2 */
    //무방향 그래프(Undirected Graph)
    int adj_matrix[10][10]={};
    int v, e;
    cin>>v>>e;
    for(int i=0; i<e; i++){
        int u, v;
        cin>>u>>v;
        adj_matrix[u][v]=1;//무방향 그래프의 경우 양쪽으로 같이 표시를 해주어야 무방향성을 나타날 수 있다. 
        adj_matrix[v][u]=1;
    }

    /*인접 리스트를 이용한 표현법 1 */
    //방향 그래프(Directed Graph)
    vector<int> adj[10]; //=> 이건 vector를 원소로 갖는 배열을 의미. 이때에 각각의 원소에 1, 2, 3, 형태로 접근하고, 각각의 원소에 대해서 개별적으로 vector가 존재하고, 그 vector로 간선을 표현
    int v, e;
    cin>>v>>e;
    for(int i=0; i<e; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    /*인접 리스트를 이용한 표현법 2*/
    //무방향 그래프(Undirected Graph)   
    vector<int> adj[10];
    int v, e;
    cin>>v>>e;
    for(int i=0; i<e; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    /*인접 리스트 방식으로 구현된 코드에서 bfs를 도는 방법*/
    
}

/*
v가 100'000이면, 이걸 인접 행렬 방식으로 표현하면, int 로 잡았을때, 
이게 전체가
10'000'000'000 (100억) 이기 때문에, 
이때에 이걸 mb로 바꿔보면, 1'000'000을 떼어내야 하니까
40'000mb이고,이건 37gb이다. 
그래서 이렇게 큰 수를 인접행렬로 표현하면 용량 초과가 발생할 수 있다. 
*/
