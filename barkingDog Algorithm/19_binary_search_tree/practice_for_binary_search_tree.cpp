#include <bits/stdc++.h>
using namespace std;

int n, m, p, l , x;
int probToLevel[100'005];
set<int> probBylevel[105];



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    while(n--){
        int prob, level;
        cin>>prob>>level;
        probToLevel[prob]=level;
        probBylevel[level].insert(prob);
    }
    cin>>m;
    while(m--){
        string query;
        cin>>query;
        if(query=="add"){
            int prob, level;
            cin>>prob>>level;
            probToLevel[prob]=level;
            probBylevel[level].insert(prob);
        }
        else if(query=="recommend"){
            cin>>x;
            if(x==1){
                for(int i=100; i>=1;i--){
                    if(probBylevel[i].empty()) continue;
                    auto it=prev(probBylevel[i].end());
                    cout<<*it<<'\n';
                    break;
                }
            }
            else{//x==-1;
                for(int i=1; i<=100; i++){
                    if(probBylevel[i].empty()) continue;
                    auto it=probBylevel[i].begin();
                    cout<<*it<<'\n';
                    break;
                }
            }
        }
        else if(query=="solved"){
            int q;
            cin>>q;
            probBylevel[probToLevel[q]].erase(q);
        }
    }
}