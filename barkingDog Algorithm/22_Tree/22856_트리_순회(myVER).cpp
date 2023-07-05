#include <bits/stdc++.h>
using namespace std;

const int root=1;
int n, c,l,r;
int lc[100'005];
int rc[100'005];
int p[100'005]; //  부모노드 표시

vector<bool> vis(100'005);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    p[root]=-1; //이 코드는 없어도 된다. 개념적으로 -1로 표시해주는것이다.
    for(int i=0; i<n; i++){
        cin>>c>>l>>r;
        lc[c]=l;
        rc[c]=r;
        p[l]=c;
        p[r]=c;
    }
    int endpoint = root;
    while(rc[endpoint]!=-1)
        endpoint=rc[endpoint]; /* 계속 오른쪽으로 파고들어가서, 더이상 오른쪽으로
        갈곳이 없을때까지 가면, 그 마지막 값이 바로 중위 순회의 끝 값과 같다.*/
    
    int cur=root, move=0;
    while(true){
        vis[cur]=true;
        move++;
        if(lc[cur]!=-1 && !vis[lc[cur]])
            cur=lc[cur];
        else if(rc[cur]!=-1 && !vis[rc[cur]])
            cur=rc[cur];
        else{
            if(cur==endpoint)/*노드가 하나만 있어도 결국 여기서 걸리기 때문에, 루트에서
            부모로 넘어갈 일은 절대 없다. 그래서 아래 코드에서 루트에서의 예외처리를 하지 않는
            모습을 보이고 있다.*/
                break;
            else
                cur=p[cur];
        }
    }
    cout<<move-1;
}