#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> child[55];
int root;
int del;

int go(int cur) {
    if(cur==del) return 0;
    if(child[cur].empty()) return 1;
    if(child[cur].size()==1 && child[cur][0]==del) return 1;
    int ret=0;
    for(auto nxt: child[cur]){
        ret+=go(nxt);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;
    for(int i=0; i<n; i++){
        int p;
        cin>>p;
        if(p==-1){
            root=i;
            continue;
        }
        child[p].push_back(i);//이렇게 되면 이제 부모에서 자식으로 단방향성 이동을 보장할 수 있다. 
    }
    cin>>del;
    cout<<go(root)<<'\n';
}