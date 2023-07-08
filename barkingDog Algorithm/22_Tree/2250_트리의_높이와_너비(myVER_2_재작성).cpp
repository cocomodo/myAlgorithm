#include <bits/stdc++.h>
using namespace std;

int n; 
int lc[10'005];
int rc[10'005];
pair<int,int> colLR[10'005];
int root,d;
int colno;

void inorder(int cur, int d){
    if(cur==-1) return;
    inorder(lc[cur],d+1);
    colno++;
    auto &[lcol,rcol] = colLR[d];
    if(lcol==0 || colno<lcol) lcol=colno;
    if(rcol==0 || colno>rcol) rcol=colno;
    inorder(rc[cur],d+1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    vector<bool> isRoot(n+1,true);
    for(int i=0; i<n; i++){
        int p, l, r;
        cin>>p>>l>>r;
        lc[p]=l;
        rc[p]=r;

        if(l!=-1) isRoot[l]=false;
        if(r!=-1) isRoot[r]=false;
    }
    for(int i=1; i<=n; i++){
        if(isRoot[i]){
            root=i;
            break;
        }
    }
    inorder(root,0);

    int mxWidth=0,mxDepth=0;
    for(int d=0; d<n; d++){ //이진트리에서 최악의 경우 쭉 일렬로 한쪽으로 길어질 수 있고 그때의 최대 depth는 n-1 이 될것이다.
        auto [lcol,rcol]= colLR[d];
        int width=rcol-lcol+1;
        if(mxWidth<width){
            mxWidth=width;
            mxDepth=d;
        }
    }
    cout<<mxDepth+1<<' '<<mxWidth;

}