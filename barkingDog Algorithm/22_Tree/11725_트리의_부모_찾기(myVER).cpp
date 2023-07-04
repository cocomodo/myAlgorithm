#include <bits/stdc++.h>
using namespace std;

int n;//n>=2;
vector<int> adj[100'005];
int p[100'005];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int m=n-1;
    while(m--){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;

    q.push(1);
    while(!q.empty()){
        int cur=q.front(); q.pop();
        for(auto nxt: adj[cur]){
            if(p[cur]==nxt) continue; //여기를 잘 생각해야 한다. 반대로 입력했다.
            q.push(nxt);
            p[nxt]=cur;
        }
    }    
    // vector<int> ans;
    // for(int i=1; i<=n; i++){//이렇게 해버리면 n=1일때 이 for문이 실행이 안된다.
    //     if(p[i]!=0) ans.push_back(p[i]);
    // }
    for(int i=2; i<=n; i++){
        cout<<p[i]<<'\n';
    }
    // cout<<ans.size() <<'\n'; 
    // for(auto c: ans) cout<<c<<' ';
}
/*여기서 사용하는 n은 노드의 갯수이다. vertex의 수가 몇개 있는지 알려준다.*/