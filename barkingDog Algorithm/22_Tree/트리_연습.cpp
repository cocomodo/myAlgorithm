#include <bits/stdc++.h>
using namespace std;


/* bfs 예시 1 - 부모 배열 채우기 */
vector<int> adj[10];
int p[10]; //vis배열이 없고 이게 있다. 부모를 표시하는 배열
void bfs1(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        cout<<cur<<' ';
        for(int nxt: adj[cur]){
            if(p[cur]==nxt) continue;// 탐색해보려는 nxt가 부모라면, 건너뛰어라
            q.push(nxt);
            p[nxt]=cur;
        }
    }
}

/*BFS 예시 2 - 부모와 depth 배열(깊이를 저장) 채우기*/
vector<int> adj[10];
int p[10];
int depth[10];

void bfs2(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        cout<<cur<<' ';
        for(int nxt: adj[cur]){
            if(p[cur]==nxt) continue;
            q.push(nxt);
            p[nxt]=cur;
            depth[nxt]=depth[cur]+1; 
        }
    }
}

/* DFS 예시 1 - 부모와 depth 배열 채우기. 비재귀 DFS */
vector<int> adj[10];
int p[10];
int depth[10];

void dfs(int root){
    stack<int> s;
    s.push(root);
    while(!s.empty()){
        int cur=s.top();
        s.pop();
        cout<<cur<<' ';
        for(int nxt: adj[cur]){
            if(p[cur]==nxt) continue;
            s.push(nxt);
            p[nxt]=cur;
            depth[nxt]=depth[cur]+1;
        }
    }
}

/* DFS 예시 2 - 부모와 depth 배열 채우기. 재귀 DFS */
vector<int> adj[10];
int p[10];

int depth[10];
void dfs(int cur){
    cout<<cur<<' ';
    for(int nxt: adj[cur]){
        if(p[cur]==nxt) continue;
        p[nxt]=cur;
        depth[nxt]=depth[cur]+1;
        dfs(nxt);
    }
}

/* DFS 예시 3 - 단순 순회. 재귀 DFS */
vector<int> adj[10];
void dfs(int cur, int par){
    cout<<cur<<' ';
    for(int nxt: adj[cur]){
        if(par==nxt) continue;
        dfs(nxt, cur);
    }
}
//call dfs(1,0);

/*이진 트리의 순회*/

/*레벨 순회*/
int lc[9] =  {0,2,4,6,0,0,0,0,0};
int rc[9] =  {0,3,5,7,0,8,0,0,0};
void bfs(){ // root =1
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        cout<<cur<<' ';
        if(lc[cur]) q.push(lc[cur]);
        if(rc[cur]) q.push(rc[cur]);
    }
}

/* 전위 순회(Preorder Traversal) */
/*
1. 현재 정점을 방문한다. 
2. 왼쪽 서브 트리를 전위 순회한다. 
3. 오른쪽 서브 트리를 전위 순회한다.
*/

/* 전위 순회는 DFS 와 방문 순서가 동일하다 */
int lc[9]= {0, 2, 4, 6, 0, 0, 0, 0, 0};
int rc[9]= {0, 3, 5, 7, 0, 8, 0, 0, 0};
void preorder(int cur){
    cout<<cur<<' ';
    if(lc[cur]!=0) preorder(lc[cur]);
    if(rc[cur]!=0) preorder(rc[cur]);
}
//preorder(1);

/* 중위 순회(Inorder Traversal) */
/*
1. 왼쪽 서브 트리를 중위 순회한다.
2. 현재 정점을 방문한다. 
3. 오른쪽 서브 트리를 중위 순회한다.
=> 모양에서 가장 왼쪽에 있는 것 부터 방문하는 순서.
=> 트리가 이진탐색트리였다면 자연스럽게  크기순서로 방문하게 된다. *중위순위를 이진탐색트리에서 돌때
*/
int lc[9]={0, 2, 4, 6, 0, 0, 0, 0, 0};
int rc[9]={0, 3, 5, 7, 0, 8, 0, 0, 0};
void inorder(int cur){
    if(lc[cur]=!0) inorder(lc[cur]);
    cout<<cur<<' ';
    if(rc[cur]!=0) inorder(rc[cur]);
}
/* 후위 순회(Postorder Traversal) */
/*
1. 왼쪽 서브트리를 후위 순회한다. 
2. 오른쪽 서브 트리를 후위 순회한다. 
3. 현재 정점을 방문한다. 
전위 순회, 중위 순회와 다르게 특별하게 설명할만한 순서를 갖지 않는다. 
*/
int lc[9]={0,2,4,6,0,0,0,0,0};
int rc[9]={0,3,5,7,0,8,0,0,0};
void postorder(int cur){
    if(lc[cur]!=0) postorder(lc[cur]);
    if(rc[cur]!=0) postorder(rc[cur]);
    cout<<cur;
}
//postorder(1);

/*서로 다른 트리라도 순회 결과가 일치할 수 있다.*/
/*중위 순회와 다른 순회가 주어지면 두개의 순회 결과가 주어졌을때 트리는 유일하다*/
/*중위 순회를 포함하지 않는 전위 순회, 후위 순회만 주어지는 경우 트리가 유일하지 않다*/

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    
}