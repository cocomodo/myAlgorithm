/*dfs를 이용해서 이분 그래프 문제를 해결하기 위해서 코드를 짜는 중인데, 
뭔가 재귀 속에서 들어가서 NO에 해당하는 경우를 도출했을때 그걸 딱 끊고 나와서
결과를 출력하는게 뭔가 깔끔하게 구현되지 않고 있는것 같다. 
일단 이 코드는 통과하지 못하는 상태이다. 다음에 다시 이어서 수정해보도록 하자

다음에 처음부터 다시 dfs를 활용한 이분 그래프 풀이를 작성해보도록 하자
현재는 뭔가 어딘가에 잘못 빠져들어서인지 수정할 부분이 잘 보이지 않는 상황이다
*/
#include <bits/stdc++.h>
using namespace std;

int tc;
int n, m;
vector<int> adj[20'005]; //전역으로 두고 clear() 함수를 사용할 수 있다. 
bool vis[20'005];
bool rb[20'005];
int super_chk;

int dfs(int cur, int chk){/*이렇게 짜버리면 가장 마지막에 불린 dfs의 return 값에 따라
출력문이 달라지는것 아닌가?*/
    vis[cur]=true;
    rb[cur]=chk;
    for(auto nxt: adj[cur]){
        if(vis[nxt]){
            if(rb[cur]==rb[nxt]) {
                super_chk=-1;
                return -1;
            }
            else continue;
        }
        // if(vis[nxt]&&rb[cur]==rb[nxt]) {
        //     return -1;
        // }
        // if(vis[nxt]) continue;
        dfs(nxt,-1*chk);
    }
    return 1;
}
// int posible; =>이것도 전역변수면 영향을 미칠수도 있다. 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>tc;
    while(tc--){
        super_chk=0;
        cin>>n>>m;
        /*전 케이스에서 담긴 각각의 adj배열의 원소에 해당하는 vector들의 내부를 
        지워주는 과정*/
        for(int i=1; i<=n; i++) 
            adj[i].clear();
        
        while(m--){
            int u, v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);/* => 이 부분이 내가 제대로 파악하지 못한 부분. 
            이걸 추가하니까 테스트가 통과함.*/
        }
        int posible=0;
        for(int i=1; i<=n; i++){
            fill(vis,vis+n+1,0);
            fill(rb,rb+n+1,0);//이걸 빼먹으면 안된다. 빼먹어도 될지도?
            posible=dfs(i,1);
            if(super_chk==-1){
                // cout<<"NO"<<'\n';
                break;
            }
        }
        if(super_chk==-1) cout<<"NO"<<'\n';
        else cout<<"YES"<<'\n';
    }
    return 0;
}