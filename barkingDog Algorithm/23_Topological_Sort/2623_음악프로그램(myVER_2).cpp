#include <bits/stdc++.h>
using namespace std;

int n, m;
int ideg[1005];
vector<int> adj[1005];
vector<int> sq;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    
    int q,u,v;
    for(int i=0; i<m; i++){
        cin>>q;
        if(q==0) continue;
        cin>>u;
        while(--q){
            cin>>v;
            adj[u].push_back(v);
            ideg[v]++;
            swap(u,v); /*스왑을 사용할 생각을 하지못했구나. 스왑이라는걸 
            통해서 u는 한번만 입력받아서 남기고, 그 뒤에 v를 입력받으면서 스왑으로
            v를 u로 넘기면 된다*/
        }
    }
    queue<int> que;
    vector<int> outval;
    for(int i=1; i<=n; i++){
        if(ideg[i]==0) que.push(i);
    }
    while(!que.empty()){
        int cur=que.front(); que.pop();
        outval.push_back(cur);
        for(int nxt: adj[cur]){
            ideg[nxt]--;
            if(ideg[nxt]==0) que.push(nxt);
        }
    }
    if(outval.size()!=n) cout<<0;
    else {
        for(auto c: outval) cout<<c<<'\n';
    }

}