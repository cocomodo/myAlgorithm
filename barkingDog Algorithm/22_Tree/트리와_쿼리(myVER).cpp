#include <bits/stdc++.h>
using namespace std;

int n, r, q; //이때 r은 루트의 번호. 예제에서는 5. 5를 기점으로 쭉 이어지는 트리 형태
vector<int> adj[100'005];
int p[100'005];
int sub_cnt[100'005];
// int query[100'005];
void dfs(int cur, int prev){
    sub_cnt[cur]++;
    for(auto nxt: adj[cur]){
        if(nxt==prev) continue;
        dfs(nxt,cur);
        sub_cnt[cur]+=sub_cnt[nxt];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>r>>q;
    for(int i=0;i<n-1; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(r,-1); /*처음에 이걸 dfs(5,-1);로 돌렸는데, 이건 입력받은 r에 따라 
    루트가 달라지는 문제이다. 그렇기 때문에 dfs(5,-1)로 고정하고 돌리면 안된다. */
    for(int i=1;i<=q;i++){
        // cin>>query[i];
        int t;
        cin>>t;
        cout<<sub_cnt[t]<<'\n';
    }
    // for(int i=1; i<=q; i++){
    //     int t=query[i];
    //     cout<<sub_cnt[t]<<'\n';
    // }

}
/*
parent 배열을 채울 재귀 dfs를 돌고
cnt[i] 배열을 채울 재귀 dfs를 돌면
모든 서브트리에 대한 vertex의 갯수를 담은 배열을 얻을 수 있다. 

여기서 잘 이해해야 할 부분은, 재귀 dfs를 이용해서 서브트리의 자식으로 내려갔다가 
처리를 끝내고 다시 부모로 올라왔을때, 자식에서 처리한 내용을 바탕으로 부모에서
그 정보를 이용해서 연산을 할 수 있다는 것이다. 
내가 현재 자식에서 정보처리를 하고, 다시 부모로 올라왔을때, 그 자식에서 변경된,
혹은 추가된 정보를 이용해서 부모에서 처리해 줄 수 있다는 개념이 없었기 때문에, 
이 문제를 재귀 dfs를 이용해서 서브트리의 노드의 갯수를 카운트 하는 방법에 대해서
떠올리지 못했다. 
*/
