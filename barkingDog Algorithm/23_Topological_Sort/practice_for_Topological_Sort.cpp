#include <bits/stdc++.h>
using namespace std;

int n, m;
string s1, s2;

string name[1'005];
unordered_map<string,int> id; /* 이름을 인덱스로 받으면 사전순 정렬 시의
고유번호를 반환하는 해시*/

int indeg[1'005]; //각 사람들의 indegree를 카운트할 배열
vector<int> adj[1'005]; //인접리스트
vector<int> ch[1'005]; //각 사람들의 자녀들 고유번호를 저장할 벡터 ch

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>name[i];
    sort(name+1,name+n+1);//사전순으로 정렬

    for(int i=1; i<=n; i++)
        id[name[i]]=i;// 각각의 이름을 키로, 순서를 매칭
    
    cin>>m;
    for(int i=0; i<m; i++){
        cin>>s1>>s2;
        adj[id[s2]].push_back(id[s1]);
        indeg[id[s1]]++;
    }

    /**
     * 2
     * minji sangdo 
     * 를 출력하는 코드
    */
    vector<int> ac;
    for(int i=1; i<=n; i++)
        if(!indeg[i]) ac.push_back(i);
    
    cout<<ac.size()<<'\n';
    for(int a: ac)
        cout<<name[a]<<' ';
    cout<<'\n';

    //indegree가 1 많은 후손(자녀)들의 정보를 배열 ch에 저장
    for(int i=1; i<=n; i++){
        sort(adj[i].begin(),adj[i].end());
        for(int c: adj[i])
            if(indeg[c]-indeg[i]==1) ch[i].push_back(c);
    }

    //해당하는 사람과 자식의 수, 그리고 자식들의 이름을 출력
    for(int i=1; i<=n; i++){
        int sz=ch[i].size();
        cout<<name[i]<<' '<<sz<<' ';
        for(int c: ch[i])
            cout<<name[c]<<' ';
        cout<<'\n';
    }  
    
}