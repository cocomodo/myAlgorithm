#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin>>tc;
    multiset<int> mset;
    while(tc--){
        int query;
        cin>>query;
        while(query--){
            char order;
            int num;
            cin>>order>>num;
            if(order=='I') mset.insert(num);
            else{//order=='D'라면 
                if(!mset.empty()){
                    if(num==1){
                        auto it=prev(mset.end());
                        mset.erase(it);
                    }
                    else
                        mset.erase(mset.begin());
                }
            }
        }
        if(mset.empty()) cout<<"EMPTY"<<'\n';
        else{
            auto it=prev(mset.end());
            cout<<*it<<' ';
            auto itst=mset.begin();
            cout<<*itst;
            cout<<'\n';
        }
    }
}