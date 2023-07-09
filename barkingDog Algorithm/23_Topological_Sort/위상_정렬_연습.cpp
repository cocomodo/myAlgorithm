/**
 * 위상 정렬(topological sort):  방향 그래프에서 간선으로 주어진 정점 간 선후관계를 위배하지 않도록 나열하는 정렬
 * 
 * 사이클이 존재하지 않는 방향그래프. DAG (Directed Acyclic Graph)라고 줄여서 부르기도 한다.
*/

 #include <bits/stdc++.h>
 using namespace std;

 int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<int> adj[10];
    int deg[10];
    int n;

    queue<int> q;
    vector<int> result;
    
    for(int i=1; i<=n; i++){
        if(deg[i]==0) q.push(i);
    }
    while(!q.empty()){
        int cur=q.front(); q.pop();
        result.push_back(cur);
        for(int nxt: adj[cur]){
            deg[nxt]--;
            if(deg[nxt]==0) q.push(nxt);/*위의 deg[nxt]--와 아래의 deg[nxt]==0  판단을
            합쳐서 if(--deg[nxt]==0) 형태로 작성할 수 있다. */
        }
    }
    if(result.size()!=n)
        cout<<"cycle exists";
    else{
        for(auto x: result) cout<<x<<' ';
    }
 }