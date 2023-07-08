#include <bits/stdc++.h>
using namespace std;

int n;
int lc[10'005];
int rc[10'005];
int colno,root;
pair<int,int> colLR[10'005];

void inorder(int cur, int d){
    if(cur==-1) return; /*애초에 배열로 받을때 -1까지 받아서 이런식으로 
    코드를 작성한 것이다.*/
    inorder(lc[cur],d+1);
    colno++;
    auto &[lcol, rcol] = colLR[d];
    if(!lcol || colno<lcol) lcol=colno;
    if(!rcol || rcol<colno) rcol=colno;
    inorder(rc[cur],d+1);

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    vector<bool> isRoot(n+1,true);
    for(int i=0; i<n; i++){
        int p,l,r;
        cin>>p>>l>>r;
        lc[p]=l;
        rc[p]=r;

        if(l!=-1) isRoot[l]=false;/*자식으로 등장했다면 루트가 아니기 때문에
        루트가 아니라고 체크를 해준다. 그렇게 되면 결국 자식으로 등장하지 않은
        하나의 원소가 남고, 그건 true로 남아있을테니 그게 루트가 될 것이다.*/
        if(r!=-1) isRoot[r]=false;
    }
    for(int i=1; i<=n; i++)
        if(isRoot[i]){
            root=i;
            break;
        }
    int mxWidth=0, mxDepth=0;
    inorder(root, 0);
    for(int d=0; d<n; d++){
        auto [lcol,rcol] = colLR[d];
        if(lcol+rcol==0) break;
        int width=rcol-lcol+1;
        if(mxWidth<width){
            mxWidth=width;
            mxDepth=d;
        }
    }
    cout<<mxDepth+1<<' '<<mxWidth;

}