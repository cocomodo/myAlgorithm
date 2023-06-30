#include <bits/stdc++.h>
using namespace std;

vector<int> v[100];
int vis[100];

void dfs(int x){
    for(int i=0; i<v[x].size();i++){
        if(!vis[v[x][i]]){
            vis[v[x][i]]=1;
            dfs(v[x][i]);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a;
    cin>>n;

    //그래프 입력. 연결리스트(vector를 사용) 형태로 입력받음
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>a;
            if(a) v[i].push_back(j);
        }
    }
    for(int i=0; i<n; i++){
        // memset(vis,0,sizeof(vis));
        fill(vis,vis+100,0);
        dfs(i);
        for(int j=0; j<n; j++)
            cout<<vis[j]<<' ';
        cout<<'\n';
    }
}