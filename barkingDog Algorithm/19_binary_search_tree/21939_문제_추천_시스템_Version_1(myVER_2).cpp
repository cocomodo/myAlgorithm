#include <bits/stdc++.h>
using namespace std;

int n, m , p, l , x;

int problevel[300'005];
set<int> probBylevel[105];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cin>>n;
    while(n--){
        cin>>p>>l;
        problevel[p]=l;
        probBylevel[l].insert(p);
    }
    cin>>m;
    while(m--){
        string query;
        cin>>query;
        if(query=="recommend"){
            cin>>x;
            if(x==1){
                for(int i=100;i>=1;i--){
                    if(probBylevel[i].empty()) continue;
                    auto it1=prev(probBylevel[i].end());
                    cout<<*it1<<'\n';
                    break;
                }
            }
            else{//x==-1
                for(int i=1; i<=100;i++){
                    if(probBylevel[i].empty()) continue;
                    auto it2=probBylevel[i].begin();
                    cout<<*it2<<'\n';
                    break;
                }
            }
        }
        else if(query=="add"){
            int p, q;
            cin>>p>>q;
            problevel[p]=q;
            probBylevel[q].insert(p);
        }
        else if(query=="solved"){
            int p;
            cin>>p;
            probBylevel[problevel[p]].erase(p);
        }
    }
}